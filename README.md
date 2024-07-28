# Emotion-Based Cold Drink Dispenser System

This project combines emotion detection using OpenCV and a Convolutional Neural Network (CNN) with an ESP32 microcontroller to control pumps that dispense cold drinks based on detected emotions. The system uses a webcam to capture video, detects emotions in real-time, and sends the detected emotion to the ESP32. The ESP32 then activates one of four pumps based on the emotion detected.

## Overview

- **Emotion Detection**: Uses a pre-trained CNN model and OpenCV to classify emotions into seven categories: Angry, Disgust, Fear, Happy, Neutral, Sad, and Surprise.
- **Drink Dispensing**: An ESP32 microcontroller receives the detected emotion via Bluetooth and activates a corresponding pump for 2 seconds to dispense a cold drink.

## Hardware Requirements

- ESP32 microcontroller
- Relay modules (4)
- Pumps (4)
- Webcam
- Bluetooth terminal app (e.g., Serial Bluetooth Terminal)
- Power supply
- Connecting wires

## Software Requirements

- Python 3.x
- OpenCV
- Keras
- TensorFlow
- Arduino IDE

## Setup and Installation

### Emotion Detection

1. **Install the required Python libraries**:
    ```bash
    pip install opencv-python keras tensorflow
    ```

2. **Ensure you have the pre-trained model and Haar Cascade XML file**:
    - `model.h5` (pre-trained CNN model)
    - `haarcascade_frontalface_default.xml` (Haar Cascade for face detection)

3. **Update the paths to these files in the Python script**: `emotion_detection.py`.

### ESP32 Pump Control

1. **Connect the pumps to the ESP32**:
    - Pump 1: GPIO 33
    - Pump 2: GPIO 32
    - Pump 3: GPIO 25
    - Pump 4: GPIO 26

2. **Upload the Arduino code**: `ESP32_Bluetooth_Pump_Control.ino` to the ESP32 using the Arduino IDE.

## Usage

### Emotion Detection and Sending Data to ESP32

1. **Run the Python script**:
    ```bash
    python emotion_detection.py
    ```
    - The script will open a webcam feed and display detected emotions on the screen.
    - The detected emotion is printed and sent to the ESP32 via Bluetooth.

2. **Pair the ESP32 with a Bluetooth terminal app on your phone**.

### Drink Dispensing

- The ESP32 will receive the detected emotion and activate the corresponding pump for 2 seconds to dispense a cold drink.
    - **Angry**: Activates Pump 1
    - **Disgust**: Activates Pump 2
    - **Fear**: Activates Pump 3
    - **Happy**: Activates Pump 4
    - Other emotions will not activate any pump.

## File Structure

- `ESP32_Bluetooth_Pump_Control.ino`: Arduino code for controlling pumps via Bluetooth using ESP32.
- `emotion_detection.py`: Python script for detecting emotions using a pre-trained CNN model.

## License

This project is licensed under the MIT License.
