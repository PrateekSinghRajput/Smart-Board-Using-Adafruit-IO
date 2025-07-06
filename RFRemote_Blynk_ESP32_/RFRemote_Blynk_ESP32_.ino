#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RCSwitch.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include "config.h"

// LCD and RF
LiquidCrystal_I2C lcd(0x27, 16, 2);
RCSwitch rfReceiver = RCSwitch();

// Relay states and last control source
bool relayStates[4] = {false, false, false, false};
String lastSource = "None";

// Blynk setup
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASS;

// Forward declarations
void updateLCD();
void setRelay(int idx, bool state, String source);
void toggleRelay(int idx, String source);

// Blynk virtual pin handlers
BLYNK_WRITE(V1) { setRelay(0, param.asInt(), "Blynk"); }
BLYNK_WRITE(V2) { setRelay(1, param.asInt(), "Blynk"); }
BLYNK_WRITE(V3) { setRelay(2, param.asInt(), "Blynk"); }
BLYNK_WRITE(V4) { setRelay(3, param.asInt(), "Blynk"); }

unsigned long lastRFTime = 0;
const unsigned long debounceDelay = 300; 

void setup() {
    Serial.begin(115200);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("System Ready");

    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT);
    pinMode(relay4, OUTPUT);

    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, LOW);

    delay(2000);
    lcd.clear();
    updateLCD();

    // Start WiFi and Blynk
    WiFi.begin(ssid, pass);
    Blynk.begin(auth, ssid, pass,"blynk.cloud", 80);

    // Start RF receiver
    rfReceiver.enableReceive(digitalPinToInterrupt(4)); // RF Receiver on GPIO4
}



void loop() {
    Blynk.run();

    if (rfReceiver.available()) {
        unsigned long now = millis();
        if (now - lastRFTime > debounceDelay) {
            long receivedData = rfReceiver.getReceivedValue();
            Serial.print("RF received: ");
            Serial.println(receivedData);

            if (receivedData == RF_CODE_1) toggleRelay(0, "RF");
            else if (receivedData == RF_CODE_2) toggleRelay(1, "RF");
            else if (receivedData == RF_CODE_3) toggleRelay(2, "RF");
            else if (receivedData == RF_CODE_4) toggleRelay(3, "RF");

            lastRFTime = now;
        }
        rfReceiver.resetAvailable();
    }
}


void setRelay(int idx, bool state, String source) {
    int relayPins[4] = {relay1, relay2, relay3, relay4};
    relayStates[idx] = state;
    digitalWrite(relayPins[idx], state ? HIGH : LOW);
    lastSource = source;
    updateLCD();
    // Sync state to Blynk if source is not Blynk
    if (source != "Blynk") Blynk.virtualWrite(V1 + idx, state);
}

void toggleRelay(int idx, String source) {
    setRelay(idx, !relayStates[idx], source);
}

void updateLCD() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("R1:"); lcd.print(relayStates[0] ? "ON " : "OFF");
    lcd.print(" R2:"); lcd.print(relayStates[1] ? "ON " : "OFF");
    lcd.setCursor(0, 1);
    lcd.print("R3:"); lcd.print(relayStates[2] ? "ON " : "OFF");
    lcd.print(" R4:"); lcd.print(relayStates[3] ? "ON " : "OFF");
   
}
