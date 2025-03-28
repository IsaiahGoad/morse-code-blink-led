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
    // Verify the pin is available
    if(wiringXValidGPIO(DUO_LED) != 0) {
        printf("Invalid GPIO %d\n", DUO_LED);
        wiringXGC();
        return -1;
    }


    // Initialize the GPIO pin as PINMODE_OUTPUT
    pinMode(DUO_LED, PINMODE_OUTPUT);

}

// 2.) Write code to turn led on
void turn_on_led()
{
    // Code to turn on the LED
    printf("Duo LED GPIO (wiringX) %d: High\n", DUO_LED);
    digitalWrite(DUO_LED, HIGH);
}

// 3.) Write code to turn led off
void turn_off_led()
{
    // Code to turn off the LED
    printf("Duo LED GPIO (wiringX) %d: Low\n", DUO_LED);
        digitalWrite(DUO_LED, LOW);
}
#endif

// 4.) Parse the morse string
void morse_blink_led(char *morse_code)
{
    INIT_LED();
    // Blink LED based on the timing needed
    // Use LED_HIGH() to turn on led
    // Use LED_LOW() to turn off led
    //LED_HIGH();
    //LED_LOW();
for (int i; i < strlen(morse_code); i++)
{
    replacesubstring(morse_code, " / ", "/");
    if (morse_code[i] == '.') //this if statement provide the led blink and delay for fots
    {
        LED_HIGH();
        DELAY(1);
        LED_LOW();
        if(morse_code[i+1] == '.')
        {
            DELAY(1);
        }
        if(morse_code[i+1] ==  '-')
        {
            DELAY(1);
        }
    }
    if (morse_code[i] == '-') // if statement provide led blink and delay for dashes
    {
        LED_HIGH();
        DELAY(3);
        LED_LOW();
        if(morse_code[i+1] == '.')
        {
            DELAY(1);
        }
        if(morse_code[i+1] ==  '-')
        {
            DELAY(1);
        }
    }
    if (morse_code[i] == '/') // provide delay for going to a different word
    { 
        DELAY(7); 
    }
    else // provide delay for moving to different letters
    {
        DELAY(3);
    }
}
    // Use DELAY(duration) to sleep the appropriate units
    // By default 1 Unit = 0.1 seconds
    // Example:
   // DELAY(1); // This will add a delay of 1 unit = 0.1 seconds
    //DELAY(3); // This will add a delay of 3 unit = 0.3 seconds
    //DELAY(7); // This will add a delay of 7 unit = 0.7 seconds
}

void replacesubstring(char *morse_code, const char *input, const char *output)
{
char buffer[1024];
char *pos, *start = morse_code;
int inputlen = strlen(input);
int outplen = strlen(output);


buffer[0] = '\0';
while ((pos = strstr(start, input) ) != NULL)
{

    strncat(buffer, start,pos - start);

    strcat(buffer, output);

    start = pos + inputlen;
}
strcat(buffer, start);

strcpy(morse_code, buffer);
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
