#include "BluetoothSerial.h"  // Include the BluetoothSerial library

BluetoothSerial SerialBT;     // Create a BluetoothSerial object

#define RELAY_PIN_1 33        // GPIO pin connected to the relay module for pump 1
#define RELAY_PIN_2 32        // GPIO pin connected to the relay module for pump 2
#define RELAY_PIN_3 25        // GPIO pin connected to the relay module for pump 3
#define RELAY_PIN_4 26        // GPIO pin connected to the relay module for pump 4

void setup() {
  // Initialize the relay pins as outputs
  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
  pinMode(RELAY_PIN_3, OUTPUT);
  pinMode(RELAY_PIN_4, OUTPUT);
  
  // Start with all relays off (HIGH)
  digitalWrite(RELAY_PIN_1, HIGH);
  digitalWrite(RELAY_PIN_2, HIGH);
  digitalWrite(RELAY_PIN_3, HIGH);
  digitalWrite(RELAY_PIN_4, HIGH);
  
  // Initialize Bluetooth serial communication
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT_Pump"); // Name of your Bluetooth device
  
  Serial.println("The device started, now you can pair it with Bluetooth!");
}

void loop() {
  if (SerialBT.available()) {
    char receivedChar = SerialBT.read();
    Serial.println(receivedChar);
    
    switch (receivedChar) {
      case 'A':
        // Turn the relay on for pump 1
        digitalWrite(RELAY_PIN_1, LOW);
        delay(2000); // Keep the pump on for 2 seconds
        digitalWrite(RELAY_PIN_1, HIGH);
        break;
        
      case 'D':
        // Turn the relay on for pump 2
        digitalWrite(RELAY_PIN_2, LOW);
        delay(2000); // Keep the pump on for 2 seconds
        digitalWrite(RELAY_PIN_2, HIGH);
        break;
        
      case 'F':
        // Turn the relay on for pump 3
        digitalWrite(RELAY_PIN_3, LOW);
        delay(2000); // Keep the pump on for 2 seconds
        digitalWrite(RELAY_PIN_3, HIGH);
        break;
        
      case 'H':
        // Turn the relay on for pump 4
        digitalWrite(RELAY_PIN_4, LOW);
        delay(2000); // Keep the pump on for 2 seconds
        digitalWrite(RELAY_PIN_4, HIGH);
        break;
        
      default:
        // Turn all relays off (safety measure)
        digitalWrite(RELAY_PIN_1, HIGH);
        digitalWrite(RELAY_PIN_2, HIGH);
        digitalWrite(RELAY_PIN_3, HIGH);
        digitalWrite(RELAY_PIN_4, HIGH);
        break;
    }
  }
}
