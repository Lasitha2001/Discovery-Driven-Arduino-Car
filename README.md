# Discovery-Driven-Arduino-Car

This repository contains the Arduino code for controlling a **4-wheel drive car** using an **RC Receiver** and an **Arduino Uno**. The car is controlled via a **radio transmitter**, allowing smooth forward, backward, and turning movements using PWM signals.

## Features

* **Wireless Control**: The car's movement is controlled wirelessly via a transmitter.
* **Motor Control**: Left and right motors are controlled independently for accurate movement.
* **PWM Speed Control**: The car uses pulse-width modulation (PWM) to adjust the motor speed based on the input from the transmitter.

## Components

* **Arduino Uno R3**
* **RC_Receiver Library**: Used to receive signals from the RC transmitter.
* **L298N Motor Driver**
* **4-Wheel Drive Car Chassis Kit**
* **Flysky FS-i6X Transmitter and Receiver**

## Code Overview

* The **RC Receiver** reads the input from the transmitter using the **A0** and **A1** pins of the Arduino.
* The receiver's input is mapped to control the speed and direction of the car's motors using PWM signals.
* The \`mpower()\` function is responsible for setting the direction and speed of the left and right motors.
* **Digital pins** are used to control the motor direction, while **PWM** pins are used to control the motor speed.

## Wiring

* **Motor A (Left Motor)**: Connected to **pins 2, 3** for direction and **pin 5** for PWM control.
* **Motor B (Right Motor)**: Connected to **pins 4, 7** for direction and **pin 6** for PWM control.
* **RC Receiver**: Connected to **A0** and **A1** to receive the joystick inputs from the transmitter.

## How to Use

1. **Clone the repository**:

   Run the following command to clone the repository:
   ```bash
   git clone https://github.com/Lasitha2001/Discovery-Driven-Arduino-Car.git
   ```

2. **Upload the code**:
   * Open the \`.ino\` file in the Arduino IDE.
   * Connect your Arduino Uno and upload the code.

3. **Connect the hardware**:
   * Wire the motors and motor driver to the Arduino as described in the wiring section.

4. **Control the car**:
   * Use the **Flysky FS-i6X transmitter** to control the car's movement.

## Team Members

* [@Lasitha2001](https://github.com/Lasitha2001)
* [@JehanPinto](https://github.com/JehanPinto)
* [@saknarajapakshe](https://github.com/saknarajapakshe)
* [@gimhanijayamanna](https://github.com/gimhanijayamanna)
* [@VishwaJaya01](https://github.com/VishwaJaya01)

