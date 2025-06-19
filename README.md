# 🏠 IoT-Based Smart Home Automation System

## 📋 Project Overview

This project presents an **IoT-based Smart Home Automation system** developed using the **Adafruit ESP32** microcontroller. The system controls a 4-channel relay module, enabling seamless operation of various home appliances through both a **web-based interface** and **manual switches**.

Real-time status monitoring is implemented on a web dashboard, allowing reliable remote control of appliances via Wi-Fi. Additionally, a **fail-safe manual override** feature ensures appliance control during internet outages, combining hardware and software components for a robust and user-friendly home automation experience.

---

## 🔑 Key Features

- 🌐 **Wi-Fi Enabled Control:** Operate home appliances remotely via a web dashboard using Adafruit IO.
- 🔄 **4-Channel Relay Module:** Control multiple appliances independently.
- 🕹️ **Manual Switch Override:** Maintain appliance control locally during internet outages.
- 📊 **Real-Time Status Monitoring:** View appliance states live on the web interface.
- 💡 **RISC Microcontroller (ESP32):** Efficient processing and connectivity.
- 🖥️ **OLED Display:** Local display of system status and feedback.

---

## 🛠️ Technologies & Components

| Component/Technology      | Description                                      |
|--------------------------|-------------------------------------------------|
| Adafruit ESP32           | RISC-based microcontroller with Wi-Fi capability. |
| 4-Channel Relay Module   | Controls switching of home appliances.          |
| Manual Push Switches     | Hardware override for manual control.            |
| OLED Display (Adafruit)  | Displays real-time status locally.                |
| Adafruit IO              | Cloud platform for IoT device data visualization and control. |
| Wi-Fi                    | Wireless communication protocol for remote access. |

---

## ⚙️ System Architecture

1. **Appliance Control**  
   - Appliances connected to relay channels controlled via ESP32.  
   - Commands received from Adafruit IO dashboard or manual switches.

2. **Real-Time Monitoring**  
   - Relay states updated on the web dashboard in real-time.  
   - OLED display shows local status and feedback.

3. **Manual Override**  
   - Physical switches allow direct appliance control, independent of internet connectivity.  
   - Ensures fail-safe operation during network outages.

4. **Communication**  
   - ESP32 connects to Wi-Fi and communicates with Adafruit IO cloud platform.  
   - Handles synchronization between manual and remote commands.

---

## 🚀 Getting Started

### Hardware Setup

- Connect the 4-channel relay module to the ESP32 GPIO pins.  
- Attach manual push switches to designated input pins for override control.  
- Connect the OLED display via I2C interface to ESP32.  
- Power the system with a stable 5V supply.

### Software Setup

- Program the ESP32 using Arduino IDE or PlatformIO.  
- Use Adafruit IO libraries for cloud communication.  
- Implement logic for relay control, manual override, and status updates.  
- Configure Wi-Fi credentials and Adafruit IO keys in the code.

### Usage

- Access the web dashboard on Adafruit IO to control appliances remotely.  
- Monitor appliance status in real-time on both the dashboard and OLED display.  
- Use manual switches for local control when internet is unavailable.

---

## 📝 Project Duration

- **Total Duration:** 6 Months  
- Includes design, development, testing, and deployment.

---

## 🤝 Contribution & Support

Feel free to fork the repository, raise issues, or submit pull requests for improvements and bug fixes.

---

## 📜 License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

---

Thank you for exploring the IoT-Based Smart Home Automation System!  
Enjoy seamless and reliable control of your home appliances. 🏠✨
