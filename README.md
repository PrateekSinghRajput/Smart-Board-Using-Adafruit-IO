# 🏠 IoT-Based Smart Home Automation System

## 📋 Overview

Welcome to the **IoT-Based Smart Home Automation System**!  
This project utilizes the **Adafruit ESP32** microcontroller to control home appliances via a 4-channel relay module. Operate devices through a web interface (Adafruit IO) or manual switches, with real-time status monitoring and a fail-safe manual override for uninterrupted control—even during internet outages.

---

## 🔑 Features

- 🌐 **Remote Control:** Operate appliances from anywhere via Adafruit IO web dashboard.
- 🔄 **4-Channel Relay Module:** Manage up to four devices independently.
- 🕹️ **Manual Override:** Maintain local control during internet outages.
- 📊 **Live Status:** Monitor appliance states in real-time (web & OLED display).
- 💡 **ESP32 Powered:** Fast, efficient, and Wi-Fi enabled.
- 🖥️ **OLED Display:** View system status directly on the device.

---

## 🛠️ Technologies & Components

| Component/Tech           | Description                                      |
|--------------------------|--------------------------------------------------|
| **Adafruit ESP32**       | RISC microcontroller with Wi-Fi                  |
| **4-Channel Relay Module** | Controls up to 4 appliances                    |
| **Manual Push Switches** | Hardware override for manual control             |
| **OLED Display**         | Local status display (I2C)                       |
| **Adafruit IO**          | Cloud dashboard for control & monitoring         |
| **Wi-Fi**                | Wireless connectivity                            |

---

## ⚙️ System Architecture

1. **Appliance Control**  
   - Relays switch appliances via ESP32.
   - Commands from Adafruit IO or manual switches.

2. **Real-Time Monitoring**  
   - Relay states updated instantly on web and OLED.

3. **Manual Override**  
   - Physical switches ensure local control during outages.

4. **Communication**  
   - ESP32 syncs with Adafruit IO via Wi-Fi.
   - Keeps manual and web commands in sync.

---

## 🚀 Getting Started

### 🔌 Hardware Setup

- Connect relay module to ESP32 GPIOs.
- Attach manual push switches to input pins.
- Connect OLED display via I2C.
- Power with a stable 5V supply.

### 💻 Software Setup

- Program ESP32 using Arduino IDE or PlatformIO.
- Install Adafruit IO libraries.
- Add your Wi-Fi and Adafruit IO credentials in the code.
- Implement logic for relays, manual override, and status updates.

### 🏠 Usage

- Control appliances remotely via Adafruit IO dashboard.
- Monitor status on both dashboard and OLED.
- Use manual switches for local control if internet is unavailable.

---

## 📝 Project Timeline

- **Total Duration:** 6 Months  
  (Design, development, testing, deployment)

---


Thank you for checking out the IoT-Based Smart Home Automation System!  
Enjoy smart, seamless, and reliable control of your home. 🏡✨
