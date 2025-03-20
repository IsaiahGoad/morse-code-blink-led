#include <stdio.h>

#include "blink.h"
#include "delay.h"

#if !defined(TEST)
// Leave this header here
#include "wiringx.h"

// Fill in the four functions
// 1.) enable the output mode for onboard LED
// 2.) set the led to high
// 3.) set the led to low
// 4.) parse morse string

// 1.) Write code to enable led
void initialize_led()
{
    // Code to initialize gpio port for LED
    if(wiringXSetup("milkv_duo", NULL) == -1) {
        // Release resources if there's an error
        // during intialization.
        wiringXGC();
        return -1;
    }
}

// 2.) Write code to turn led on
void turn_on_led()
{
    // Code to turn on the LED
    digitalWrite(DUO_LED, HIGH);
}

// 3.) Write code to turn led off
void turn_off_led()
{
    // Code to turn off the LED
    digitalWrite(DUO_LED, LOW);
}
#endif

// 4.) Parse the morse string
void morse_blink_led(char *morse_code)
{
    // Blink LED based on the timing needed
    // Use LED_HIGH() to turn on led
    // Use LED_LOW() to turn off led
    LED_HIGH();
    LED_LOW();

    // Use DELAY(duration) to sleep the appropriate units
    // By default 1 Unit = 0.1 seconds
    // Example:
    DELAY(1); // This will add a delay of 1 unit = 0.1 seconds
    DELAY(3); // This will add a delay of 3 unit = 0.3 seconds
    DELAY(7); // This will add a delay of 7 unit = 0.7 seconds
}

#if defined(TEST)
// This code that helps with unit testing
// No need to modify
void mock_initialize_led()
{
    printf("Mock: LED Initialized\n");
}
void mock_led_high()
{
    printf("Mock: LED ON\n");
}
void mock_led_low()
{
    printf("Mock: LED OFF\n");
}
#endif
