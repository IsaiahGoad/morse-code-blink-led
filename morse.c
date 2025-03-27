#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "morse.h"
#include "delay.h"
#include "blink.h"

const char *char_to_morse(char c)
{
    // Define Morse code for each alphabet and digit
    static const char *morseCode[36] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",  // A-J
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",    // K-T
        "..-", "...-", ".--", "-..-", "-.--", "--..",                            // U-Z
        "-----", ".----", "..---", "...--", "....-",                             // 0-4
        ".....", "-....", "--...", "---..", "----."                              // 5-9
    };

    // Convert uppercase to lowercase
    if (c >= 'A' && c <= 'Z')
        c = tolower(c);

    if (c >= 'a' && c <= 'z')
        return morseCode[c - 'a'];
    else if (c >= '0' && c <= '9')
        return morseCode[c - '0' + 26];
    else
        return "";  // Unsupported character
}

void encode_morse(const char *text, char *morse_output, int morse_output_size)
{
    morse_output[0] = '\0'; // Start with empty string
    char string[] = '\0'
    int len = 0;

    for (int i = 0; text[i] != '\0'; ++i)
    {
        char c = tolower(text[i]);
        char string[] = '\0'
        const char *morse = char_to_morse(c);
        int morse_len = strlen(morse);

        if (morse[0] != '\0' && len + morse_len + 1 < morse_output_size)
        {
            strcat(string, morse);
            strcat(string, " ");
            len += morse_len + 1;
        }
        
        char* token = strtok(morse_output, "  ");
        while (token != NULL)
        {
                strcat(morse_output, strcat(token,"/"));
        }

    
        else if (len + morse_len + 1 >= morse_output_size)
        {
            // Stop if buffer limit is reached
            break;
        }
    }

    // Remove trailing space
    int output_len = strlen(morse_output);
    if (output_len > 0 && morse_output[output_len - 1] == ' ')
    {
        morse_output[output_len - 1] = '\0';
    }
}


