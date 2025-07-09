from pymata4 import pymata4
import threading
import FreeSimpleGUI as sg

# Initialize the Arduino board
board = pymata4.Pymata4(com_port="COM4")

# Pin configuration
BUTTON_PIN = 2  # Digital input pin for the button
LED_PIN = 4    # Digital output pin for the LED

# Global variables
button_state = "Not Pressed"
led_timer = None  # Timer object
timer_interval = 5  # Default timer interval in seconds


# Function to turn off the LED
def turn_off_led():
    global button_state
    board.digital_write(LED_PIN, 0)  # Turn off the LED
    button_state = "Not Pressed"
    window.write_event_value('-UPDATE-', "LED turned off")


# Callback function for button press
def button_callback(data):
    global button_state, led_timer
    if data[2] == 1:  # Button pressed
        button_state = "Pressed"
        board.digital_write(LED_PIN, 1)  # Turn on the LED
        window.write_event_value('-UPDATE-', "Button Pressed: LED turned on")

        # Cancel any existing timer and start a new one
        if led_timer:
            led_timer.cancel()
        led_timer = threading.Timer(timer_interval, turn_off_led)
        led_timer.start()


# Set up the button pin as a digital input with a callback
board.set_pin_mode_digital_input(BUTTON_PIN, callback=button_callback)

# Set up the LED pin as a digital output
board.set_pin_mode_digital_output(LED_PIN)

# GUI Layout
layout = [
    [sg.Text("Timer Interval (seconds):"), sg.Input(default_text=str(timer_interval), key='-TIMER-', size=(10, 1)), sg.Button("Set Timer")],
    [sg.Text("Button State:"), sg.Text(button_state, size=(15, 1), key='-STATE-')],
    [sg.Output(size=(60, 10), key='-OUTPUT-')],
    [sg.Button("Exit")]
]

# Create the window
window = sg.Window("Reacting to Button Press with Timer", layout)

# Event loop
while True:
    event, values = window.read(timeout=100)

    if event == sg.WINDOW_CLOSED or event == "Exit":
        break

    # Update the timer interval
    if event == "Set Timer":
        try:
            timer_interval = float(values['-TIMER-'])
            print(f"Timer interval set to {timer_interval} seconds.")
        except ValueError:
            sg.popup_error("Please enter a valid number for the timer interval.")

    # Update the GUI with button state or actions
    if event == '-UPDATE-':
        message = values['-UPDATE-']
        print(message)
        window['-STATE-'].update(button_state)

# Clean up
if led_timer:
    led_timer.cancel()
board.shutdown()
window.close()