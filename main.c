#include <stdio.h>

#include "blink.h"
#include "morse.h"

#define MAXSIZE 100
#define BUFSIZE MAXSIZE - 1

int main()
{
    // Input string
    const char *input = "sos";

    // Storage for the encoded string
    char morse_output[BUFSIZE] = {0};

    // Fill in the code for `encode_morse`
    encode_morse(input, morse_output, BUFSIZE);

    // morse_output should contain `sos` encoded in morse code
    printf("Morse Code: %s\n", morse_output);

    // Pass `morse_output` to the morse_blink_led function
    // Fill in the code for `morse_blink_led`
    morse_blink_led(morse_output);

    return 0;
}
