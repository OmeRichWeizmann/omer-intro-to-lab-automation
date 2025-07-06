# Project 9  - Latency

## Goals
1. Understand the concept of latency and its importance in real-time systems.
2. Measure the latency (reaction time) of yourself using the Arduino board and log the data into a file
3. Graphing and logging data in realtime.

## Requirements
1. Develop an Arduino sketch that uses a button to trigger the turning on of an LED for a random amount of time between 500 and 3000 milliseconds. The user should hold the button pressed until the LED turns off. The program than finds the time it took the user to react to the LED turning off in ms and send this value to the computer. Use MsTimer2 library.

2. Develop a Python script that communicates with the Arduino board via a serial port. The script should display a histogram of the reaction times of the user to the LED turning off. The histogram should be updated in real-time as new reaction times are received from the Arduino board and the results should be saved into a csv file. Use the pandas library to save the data into a csv file.

## Computer side
1. Develop a Python script that communicates with a device via a serial port using the pyserial library.
2. The script should use PySimpleGUI to build a GUI. The GUI should have a number input, a button, and a matplotlib canvas for displaying a histogram.
3. The script should define a function named read_serial that continuously reads data from the serial port.
6. The script should use threading to run the read_serial function in parallel with the main GUI loop.
7. The script should handle any exceptions or errors that might occur during the communication with the device.
8. The script should include comments explaining the functionality of each part of the code.
10. The script receives the latency between when the light goes out and the time it takes the user to react. This latency should be displayed in real-time on the histogram in the GUI. The histogram should be updated every time a new latency measurement is received.

## Exercises
1. Paste here the screenshot of the GUI that shows the histogram of the reaction times of the user to the LED turning off.
2. Add the corresponding csv files of your reaction times to the project folder.
3. What can you say about the reaction times of the user? What do you think is the uncertainty in the measurements of a single reaction time?

