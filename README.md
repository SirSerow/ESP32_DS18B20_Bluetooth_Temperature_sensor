# ESP32 Temperature Sensor with Bluetooth (PlatformIO)

## Overview
This project implements a simple **temperature sensor** reading using an **ESP32** microcontroller. The sensor data is transmitted via **Bluetooth Serial** to a paired device. The project is built using the **Arduino framework** and the **PlatformIO** toolset for compilation and flashing.

## Features
- Reads temperature data from a **Dallas DS18B20** sensor.
- Uses **Bluetooth Serial** to send temperature readings to a paired device.
- LED control via Bluetooth commands.
- Built with **PlatformIO** for easy development and flashing.

## Hardware Requirements
- **ESP32** development board
- **DS18B20** temperature sensor
- **4.7kΩ pull-up resistor** (for the OneWire bus)
- **LED (optional)**

## Software Requirements
- **PlatformIO** installed on VS Code ([Installation Guide](https://platformio.org/install/ide?install=vscode))
- **Arduino framework**
- **Required libraries**:
  - `OneWire`
  - `DallasTemperature`
  - `BluetoothSerial`

## Wiring Diagram
| ESP32 Pin | DS18B20 Pin |
|-----------|------------|
| 15        | Data (DQ)  |
| 3.3V      | VCC        |
| GND       | GND        |

> **Note:** A **4.7kΩ pull-up resistor** should be placed between the **Data** and **VCC** pins of the DS18B20.

## Installation & Setup
1. **Clone the repository**:
   ```sh
   git clone https://github.com/yourusername/esp32-temp-sensor.git
   cd esp32-temp-sensor
   ```
2. **Open the project in VS Code with PlatformIO**.
3. **Build and flash the firmware**:
   ```sh
   pio run --target upload
   ```
4. **Monitor the Serial Output**:
   ```sh
   pio device monitor
   ```

## Bluetooth Usage
- Pair the ESP32 with your device (default Bluetooth name: **ESP32_Temperature**).
- Use a Bluetooth terminal app to send commands:
  - **Send `/t`** → Receive temperature readings.
  - **Any other input** → Echo the received character.

## Expected Output
When `/t` is sent via Bluetooth, the response should be similar to:
```
Temperature is: 25.4°C
```
If the sensor is not detected:
```
Error: Could not read temperature data
```

## Future Enhancements
- Add multiple sensor support.
- Implement a **mobile app** for better Bluetooth interaction.
- Improve **power efficiency** for battery-powered applications.

## License
This project is open-source under the **MIT License**. Contributions are welcome!
