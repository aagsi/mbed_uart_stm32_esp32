#include <Arduino.h>

#define LED_PIN 18 // Assuming the LED is connected to GPIO 18
#define UART_BAUD_RATE 115200

// Define the RX and TX pins for the second UART
//#define RX_PIN 3
//#define TX_PIN 1

#define RX_PIN 16
#define TX_PIN 17

void setup() {
  pinMode(LED_PIN, OUTPUT); // Initialize the LED pin as an output
  Serial.begin(UART_BAUD_RATE); // Start communication on the default UART (for debugging)
  
  // Initialize Serial1 on pins 9 (RX) and 10 (TX)
  //Serial1.begin(UART_BAUD_RATE, SERIAL_8N1, RX_PIN, TX_PIN);
  Serial2.begin(UART_BAUD_RATE, SERIAL_8N1, RX_PIN, TX_PIN);
}

void loop() {

  
  // Check if data is available to read on Serial1
  if (Serial2.available()) {
    String command = Serial2.readStringUntil('\n'); // Reads the incoming data until a newline character
    
    // Echo received command back to the default Serial for debugging
    Serial.print("Received: ");
    Serial.println(command);
    command.trim(); // This will remove any whitespace or newline/carriage return characters from the start and end of the string

    
    // Process the command
    if (command == "LED ON") {
      digitalWrite(LED_PIN, HIGH); // Turn LED on
    } else if (command == "LED OFF") {
      digitalWrite(LED_PIN, LOW); // Turn LED off
    }
  }
}




/*

#include <Arduino.h>
#define LED_PIN 18 // Assuming the LED is connected to GPIO 18
#define UART_BAUD_RATE 115200
void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(UART_BAUD_RATE);
}
void loop() {
digitalWrite(LED_PIN, HIGH); // Turn LED on
  //if (Serial.available()) { // Checks if data is available to read
    String command = Serial.readStringUntil('\n'); // Reads the incoming data until a newline character is detected
    // Debugging statement: Prints the received command to the Serial Monitor
    Serial.print("Received: ");
    Serial.println(command);
    // Process the command
    if (command == "LED ON") {
      digitalWrite(LED_PIN, HIGH); // Turn LED on
    } else if (command == "LED OFF") {
      digitalWrite(LED_PIN, LOW); // Turn LED off
    }
 //}
}

*/


/*
#include <Arduino.h>

void setup() {
  pinMode(18, OUTPUT);
  Serial.begin(115200);
}




/*
#include <Arduino.h>
#define LED_PIN 18 // Assuming the LED is connected to GPIO 18
#define UART_BAUD_RATE 115200
void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(UART_BAUD_RATE);
}



void loop() {

  Serial.print("Hall ooooooooo ");
  digitalWrite(18, HIGH);
  delay(1000);
  digitalWrite(18, LOW);
  delay(1000);
}
*/