# Hand-Gesture-Controlled-Car
🤖 Hand Gesture Controlled Car using Arduino
This project showcases a simple yet effective hand gesture controlled car built using Arduino and accelerometer-based motion sensing. By detecting the orientation of your hand, the system interprets directional gestures to control a 2WD robotic car in real-time.

🚗 Features
Control car movement using hand gestures:

Tilt forward → Move Forward

Tilt backward → Move Backward

Tilt left → Turn Left

Tilt right → Turn Right

Steady hand → Stop

Wireless communication using RF modules 

Built using an Arduino Uno/Nano, accelerometer (e.g., MPU6050 ), motor driver (L298N), and DC motors

🧰 Components Used
Arduino Uno or Nano (2x – one for transmitter, one for receiver)

Accelerometer Sensor (e.g., MPU6050)

L298N Motor Driver Module

2 or 4 DC Gear Motors + Wheels

RF Transmitter/Receiver (433 MHz) or Bluetooth HC-05 (alternative)

2x 9V Batteries or Li-ion Battery Pack

Breadboard and jumper wires

Chassis for the car

🔌 How It Works
Gesture Detection: The accelerometer mounted on your hand detects tilt/orientation.

Data Transmission: The sensor data is processed by a transmitter Arduino, which sends control signals wirelessly.

Car Control: The receiver Arduino interprets the signals and drives the motors accordingly through the motor driver.
