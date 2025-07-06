# Project 11 - Final Project 

## Goals
1. integrate the knowledge and skills acquired throughout the course to develop a final project that encompasses all the concepts learned.
2. Learn about the accelerometer sensor and how to use it in a project.
3. Learn about the OLED display and Buzzer effector and how to use them in a project.

## Setup
1. Use the setup from Project10-Fan_Speed (you can see the setup in the Project10 README, with a link and an image. Use the "show preview" option in vscode to view the image). Add the following components:
    - Accelerometer sensor
    - OLED display
    - Buzzer effector
    - connect the servo motor to the board
2. There are two options for packages:  
- **Recommended**: Use the [Arduino SensorKit](https://sensorkit.arduino.cc/) library (this includes all the hardware in the kit).
- You can also use the grove packages as recommended in the [Grove documentation](https://wiki.seeedstudio.com/Grove-Beginner-Kit-For-Arduino/#hardware-overview),

## Requirements
Build a system that: 
1. Operates the mini fan. The fan is on the servo motor.
1. changes the angle of the servo motor (and the fan) based on the accelerometer sensor readings.
2. displays the angle in the OLED display and buzzer state.
3. if the angle exceeds a certain threshold, the buzzer should sound and the fan should stop. when returning to a valid angle, the buzzer should stop sounding and the fan should start again.
4. log the time since program start, the angle (in degrees) and the buzzer state in a csv file (where should this be done, from the Arduino or the Python code?).
4. Record a video of the system and add to the README below (by dragging it in while pressing the `shift` key).
5. develop a GUI that displays the angle in a graph or compass and the buzzer state as a LED in real-time and logs the data in a csv file.
6. Record a new video that also shows the GUI and add to the readme below
7. Make sure to handle possible errors
8. Use good programming practices:
    - Document the code (first line in file, functions, loops, code blocks)
    - Use logical names for variables constants and functions
    - use constants where possible
    - define variables and constants at the beginning of the code
    - encapsulate chunks of code that perform a single function into a function with a logical name.

## Exercises
1. paste here the videos (one fo the hardware and one of the GUI).
3. add the csv file to the project. make sure it reflects all the states of the project.
5. If you have multiple folders, write here which is the final version: 