/*
 * main.cpp
 *
 *  Created on: Nov 11, 2024
 *      Author: mistya
 */

// Includes
#include "main.hpp"
#include "boot.hpp"
#include "gpio.hpp"


// Global GPIO pointers
GPIO_Output* GPIO_UserLED_Red = nullptr;
GPIO_Output* GPIO_UserLED_Green = nullptr;
GPIO_Input* GPIO_UserButton = nullptr;

// Function declarations
void runHeartbeat(GPIO_Output* led, uint32_t& lastToggleTime);

// Main application entry point
int main(void) {
    // System initialization
    if (SystemInitialize() == Fail) {
        while (1) {}
    }

    // Initialize GPIO objects
    GPIO_UserButton = new GPIO_Input(USERBUTTON_GPIO_PORT, USERBUTTON_GPIO_PIN);
    GPIO_UserLED_Red = new GPIO_Output(USERLED_RED_GPIO_PORT, USERLED_RED_GPIO_PIN);
    GPIO_UserLED_Green = new GPIO_Output(USERLED_GREEN_GPIO_PORT, USERLED_GREEN_GPIO_PIN);

    // Time tracking for heartbeat
    uint32_t lastHeartbeatToggleTime = HAL_GetTick();

    // Main loop
    while (1) {
        uint32_t frameStart = HAL_GetTick(); // Record start time for frame timing

        // --- Heartbeat Handling ---
        runHeartbeat(GPIO_UserLED_Green, lastHeartbeatToggleTime);

        // --- Button Handling ---
        if (GPIO_UserButton->readState()) {
            // If button is pressed, blink red LED
            GPIO_UserLED_Red->on();
            HAL_Delay(500);
            GPIO_UserLED_Red->off();
            HAL_Delay(500);
        } else {
            // If button is not pressed, keep red LED on
            GPIO_UserLED_Red->on();
        }

        // --- Frame Timing Management ---
        uint32_t frameEnd = HAL_GetTick();
        uint32_t frameTime = frameEnd - frameStart;
        if (frameTime < FRAME_DURATION_MS) {
            HAL_Delay(FRAME_DURATION_MS - frameTime); // Wait for remaining frame time
        }
    }

    // Clean up (not reached in this loop but good practice)
    delete GPIO_UserButton;
    delete GPIO_UserLED_Red;
    delete GPIO_UserLED_Green;

    return 0;
}

// Heartbeat function (non-blocking)
void runHeartbeat(GPIO_Output* led, uint32_t& lastToggleTime) {
    uint32_t currentTime = HAL_GetTick();
    if (currentTime - lastToggleTime >= HEARTBEAT_INTERVAL_MS) {
        led->toggle(); // Toggle LED state
        lastToggleTime = currentTime; // Update last toggle time
    }
}
