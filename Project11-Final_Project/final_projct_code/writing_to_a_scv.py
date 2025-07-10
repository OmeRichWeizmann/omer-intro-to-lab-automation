import serial
import csv
import time

# Configure the serial connection
arduino_port = "COM4"  # Replace with your Arduino's COM port
baud_rate = 9600       # Match the baud rate in your Arduino code
output_file = "log.csv"

# Open the serial connection
ser = serial.Serial(arduino_port, baud_rate)
print(f"Connected to Arduino on {arduino_port}")

# Open the CSV file for writing
with open(output_file, mode='w', newline='') as file:
    writer = csv.writer(file)
    # Write the header row
    writer.writerow(["Time (ms)", "Servo Angle (degrees)", "Buzzer State"])

    try:
        while True:
            # Read a line of data from the serial port
            line = ser.readline().decode('utf-8').strip()
            print(f"Received: {line}")  # Print the received data for debugging

            # Split the data into components (time, angle, buzzer state)
            data = line.split(",")
            if len(data) == 3:  # Ensure the data has 3 components
                writer.writerow(data)  # Write the data to the CSV file

    except KeyboardInterrupt:
        print("Logging stopped by user.")
    finally:
        ser.close()
        print("Serial connection closed.")