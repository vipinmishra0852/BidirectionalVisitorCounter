## People Counter with Temperature Monitoring 

This project uses Arduino to count the number of people entering and leaving a room while also monitoring the average temperature.

### Features

* Counts people entering and leaving using ultrasonic sensors.
* Calculates and displays the average temperature from two DHT11 sensors.
* Provides visual feedback using LEDs (one for entry and one for exit).

### Hardware Requirements

* Arduino Uno or compatible board
* DHT11 temperature sensor (x2)
* Ultrasonic sensor (x2)
* Breadboard
* Jumper wires
* LEDs (x2)
* Resistors (values may vary depending on LEDs)

### Software Requirements

* Arduino IDE ([https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE](https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE))
* DHT library ([https://learn.adafruit.com/dht/downloads](https://learn.adafruit.com/dht/downloads))

### Installation

1. Download and install the Arduino IDE.
2. Download and install the DHT library following the instructions provided by the library source.
3. Clone or download this repository.
4. Open the `.ino` file (usually named the same as the project) in the Arduino IDE.
5. Connect your hardware components according to the schematic (which can be added to this readme if available).
6. Upload the code to your Arduino board.

### Usage

1. Open the serial monitor in the Arduino IDE (Tools -> Serial Monitor).
2. The program will start printing the average temperature and number of people in the room.
3. Observe the LEDs for visual feedback on entry (LED1) and exit (LED2).

### How it Works

The code utilizes two DHT11 sensors to read temperature values. The average temperature is then calculated and displayed on the serial monitor.

Ultrasonic sensors are used to detect movement across doorways. When a person enters (sensor 1 detects movement while sensor 2 doesn't), the `num_people` counter is incremented and the entry LED (LED1) is turned on. Similarly, when a person leaves (sensor 2 detects movement while sensor 1 doesn't), the counter is decremented (only if greater than 0) and the exit LED (LED2) is turned on.

### Additional Notes

* This is a basic example and can be extended to include features like logging data to an SD card or sending notifications.
* The accuracy of the ultrasonic sensors and temperature readings may vary depending on environmental conditions.
* Make sure to adjust resistor values based on your specific LEDs.

### Contribution

Feel free to contribute to this project by forking the repository and submitting pull requests with improvements or new features.
