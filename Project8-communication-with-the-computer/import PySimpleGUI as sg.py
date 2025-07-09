import PySimpleGUI as sg
import serial
import threading
import time

# Initialize serial communication
try:
    arduino = serial.Serial(port='COM3', baudrate=9600, timeout=1)  # Replace 'COM3' with your Arduino's port
except serial.SerialException as e:
    sg.popup_error(f"Error connecting to Arduino: {e}")
    exit()

# Function to read data from Arduino and update the GUI
def read_from_serial(window):
    while True:
        try:
            if arduino.in_waiting > 0:
                data = arduino.readline().decode('utf-8').strip()
                window.write_event_value('-SERIAL-', data)  # Send data to the GUI
        except Exception as e:
            window.write_event_value('-SERIAL-', f"Error: {e}")
            break

# GUI Layout
layout = [
    [sg.Text("Enter LED ON time (ms):"), sg.Input(key='-INPUT-', size=(10, 1)), sg.Button("Send")],
    [sg.Text("Arduino Response:"), sg.Text("", size=(40, 1), key='-RESPONSE-')],
    [sg.Output(size=(60, 10), key='-OUTPUT-')],
    [sg.Button("Exit")]
]

# Create the window
window = sg.Window("Arduino LED Control", layout)

# Start a thread to read from the serial port
thread = threading.Thread(target=read_from_serial, args=(window,), daemon=True)
thread.start()

# Event loop
while True:
    event, values = window.read()

    if event == sg.WINDOW_CLOSED or event == "Exit":
        break

    # Handle the "Send" button
    if event == "Send":
        try:
            input_value = values['-INPUT-']
            if input_value.isdigit():
                arduino.write(f"{input_value}\n".encode('utf-8'))  # Send the input value to Arduino
                print(f"Sent to Arduino: {input_value}")
            else:
                sg.popup_error("Please enter a valid number.")
        except Exception as e:
            sg.popup_error(f"Error sending data: {e}")

    # Handle serial data received
    if event == '-SERIAL-':
        response = values['-SERIAL-']
        window['-RESPONSE-'].update(response)
        print(f"Arduino: {response}")

# Close the serial connection and GUI
arduino.close()
window.close()