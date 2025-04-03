#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "morse.h"
#include "delay.h"
#include "blink.h"

// Maps a single alphanumeric character to its Morse code representation.
// Returns a pointer to a static Morse code string, or an empty string for unsupported characters.
const char *char_to_morse(char c)
{
    // Morse code for letters A-Z and digits 0-9
    static const char *morseCode[36] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",  // A-J
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",    // K-T
        "..-", "...-", ".--", "-..-", "-.--", "--..",                            // U-Z
        "-----", ".----", "..---", "...--", "....-",                             // 0-4
        ".....", "-....", "--...", "---..", "----."                              // 5-9
    };

    // Convert uppercase to lowercase for uniform indexing
    if (c >= 'A' && c <= 'Z')
        c = tolower(c);

    // Return Morse string for alphabetic or numeric characters
    if (c >= 'a' && c <= 'z')
        return morseCode[c - 'a'];
    else if (c >= '0' && c <= '9')
        return morseCode[c - '0' + 26];
    else
        return ""; // Return empty string for unsupported characters
}

// Encodes a null-terminated input string into Morse code,
// storing the result in 'morse_output' with a size limit of 'morse_output_size'.
// Uses "/ " as a delimiter between words.
void encode_morse(const char *text, char *morse_output, int morse_output_size)
{
    morse_output[0] = '\0'; // Initialize output as an empty string
    int len = 0;            // Initialize output as an empty string
     
    // Iterate through each character in the input text
    for (int i = 0; text[i] != '\0'; ++i)
    {
        char c = tolower(text[i]);
        // If the character is a space, insert a word delimiter and continue 
        if (c == ' ')
        {
            // Insert "/ " for word separation
            if (len + 2 < morse_output_size)
            {
                strcat(morse_output, "/ ");
                len += 2;
            }
            continue;
        }
        
        // Get Morse code equivalent of the character
        const char *morse = char_to_morse(c);
        int morse_len = strlen(morse);

        // Append Morse code and a space if it fits in the output buffer
        if (morse[0] != '\0' && len + morse_len + 1 < morse_output_size)
        {
            strcat(morse_output, morse);
            strcat(morse_output, " ");
            len += morse_len + 1;
        }
        else if (len + morse_len + 1 >= morse_output_size)
        {
            // Prevent buffer overflow; stop if output limit reached
            break;
        }
    }
  
    // Remove trailing space if present
    int output_len = strlen(morse_output);
    if (output_len > 0 && morse_output[output_len - 1] == ' ')
    {
        morse_output[output_len - 1] = '\0';
    }
    
}

