
//c:/Users/Ahmed/Mbed Programs/mbed-os-example-blinky/main.cpp

#include "mbed.h"
// Define TX and RX pins for UART communication
#define TX_PIN PD_8
#define RX_PIN PD_9
// Initialize a BufferedSerial object for communication with specific pins
BufferedSerial esp32(TX_PIN, RX_PIN);
// Initialize a DigitalOut object to control an LED
DigitalOut led(LED3);
int main() {
    esp32.set_baud(115200); // Set baud rate for communication with ESP32
    char ledOnMsg[] = "LED ON\r\n";
    char ledOffMsg[] = "LED OFF\r\n";
    while (true) {
        // Turn the LED on
        led = 1; // LED is ON
        esp32.write(ledOnMsg, sizeof(ledOnMsg) - 1); // Send the "LED ON" message to ESP32
        ThisThread::sleep_for(1s); // Wait for 1 second
        // Turn the LED off
        led = 0; // LED is OFF
        esp32.write(ledOffMsg, sizeof(ledOffMsg) - 1); // Send the "LED OFF" message to ESP32
        ThisThread::sleep_for(1s); // Wait for 1 second
    }
}


/*
#include "mbed.h"

// Define TX and RX pins for UART communication
#define TX_PIN PD_8
#define RX_PIN PD_9

// Initialize a BufferedSerial object for communication with specific pins
BufferedSerial esp32(TX_PIN, RX_PIN);

// Initialize DigitalOut objects to control LEDs
DigitalOut led(LED3);
DigitalOut led2(LED2); // Assuming LED2 is defined and accessible

int main() {
    esp32.set_baud(115200); // Set baud rate for communication

    char recvBuffer[10]; // Buffer to hold received messages
    ssize_t numReceived; // Number of bytes received

    while (true) {
        // Check if there is data available to read
        if((numReceived = esp32.read(recvBuffer, sizeof(recvBuffer)-1)) > 0) {
            recvBuffer[numReceived] = '\0'; // Null-terminate the string

            // Turn LED2 on or off based on the received message
            if(strcmp(recvBuffer, "LED2ON") == 0) {
                led2 = 1; // LED2 is ON
            } else if(strcmp(recvBuffer, "LED2OFF") == 0) {
                led2 = 0; // LED2 is OFF
            }
        }

        // Additional functionality can be added here
    }
}
*/


/*
#include "mbed.h"
// Define TX and RX pins for UART communication
#define TX_PIN PD_8
#define RX_PIN PD_9
// Initialize a BufferedSerial object for communication with specific pins
BufferedSerial esp32(TX_PIN, RX_PIN);
// Initialize a DigitalOut object to control an LED
DigitalOut led(LED3);
int main() {
    esp32.set_baud(115200); // Set baud rate for communication with ESP32
    char ledOnMsg[] = "LED ON\r\n";
    char ledOffMsg[] = "LED OFF\r\n";
    while (true) {
        // Turn the LED on
        led = 1; // LED is ON
        esp32.write(ledOnMsg, sizeof(ledOnMsg) - 1); // Send the "LED ON" message to ESP32
        ThisThread::sleep_for(1s); // Wait for 1 second
        // Turn the LED off
        led = 0; // LED is OFF
        esp32.write(ledOffMsg, sizeof(ledOffMsg) - 1); // Send the "LED OFF" message to ESP32
        ThisThread::sleep_for(1s); // Wait for 1 second
    }
}

*/

/*
#include "mbed.h"

// Initialize a BufferedSerial object for communication
BufferedSerial pc(USBTX, USBRX); // TX, RX

//https://github.com/ARMmbed/mbed-os/blob/master/targets/TARGET_STM/TARGET_STM32F2/TARGET_STM32F207xG/TARGET_NUCLEO_F207ZG/PinNames.h
//    CONSOLE_TX = PD_8,
//    CONSOLE_RX = PD_9,
// Initialize a DigitalOut object to control an LED
DigitalOut led(LED2); // Adjust LED1 to your specific target board's LED pin if necessary
int main() {
    pc.set_baud(115200); // Set baud rate

    char ledOnMsg[] = "LED ON\n";
    char ledOffMsg[] = "LED OFF\n";

    while (true) {
        // Turn the LED on
        led = 1; // LED is ON
        pc.write(ledOnMsg, sizeof(ledOnMsg) - 1); // Send the "LED ON" message
        
        ThisThread::sleep_for(1s); // Wait for 1 second
        
        // Turn the LED off
        led = 0; // LED is OFF
        pc.write(ledOffMsg, sizeof(ledOffMsg) - 1); // Send the "LED OFF" message
        
        ThisThread::sleep_for(1s); // Wait for 1 second
    }
}
*/

/*
#include "mbed.h"

// Initialize a BufferedSerial object for communication
BufferedSerial pc(USBTX, USBRX); // TX, RX

// Initialize a DigitalOut object to control an LED
DigitalOut led(LED2); // Adjust LED1 to your specific target board's LED pin if necessary

int main() {
    pc.set_baud(115200); // Set baud rate

    while (true) {
        char msg[] = "welcome to BinaryUpdates1\n\r";
        pc.write(msg, sizeof(msg)); // Send the message
        
        // Turn on the LED to indicate transmission
        led = 1; // LED is ON
        ThisThread::sleep_for(500ms); // 500 ms delay
        
        // Turn off the LED
        led = 0; // LED is OFF
        ThisThread::sleep_for(500ms); // Additional delay to make it 1 second from the start of the transmission
    }
}

*/


/*
#include "mbed.h"

// Initialize a BufferedSerial object for communication
BufferedSerial pc(USBTX, USBRX); // TX, RX

// Initialize a DigitalOut object to control an LED
DigitalOut led(LED1); // Change LED1 to the correct LED pin for your board

int main() {
    pc.set_baud(115200); // Set baud rate

    while (true) {
        char msg[] = "welcome to BinaryUpdates1\n\r";
        pc.write(msg, sizeof(msg)); // Send the message
        
        // Blink the LED
        led = !led; // Toggle the LED state
        ThisThread::sleep_for(500ms); // 500 ms delay
    }
}

*/

/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */
/*
#include "mbed.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms


int main()
{
    // Initialise the digital pin LED1 as an output
#ifdef LED1
    DigitalOut led(LED1);
#else
    bool led;
#endif

    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}
*/