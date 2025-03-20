# Morse Code Translator

## Introduction

This project involves creating a Morse code translator in C that controls an LED on the Milk-V Duo to blink Morse code representations of text inputs. The objective is to blend software development with hands-on hardware interaction, focusing on embedded systems programming, C language, and unit testing using Unity.

## Setup Instructions

1. Set up the Milk-V Duo embedded device.
2. Install Unity testing framework.

## Teams

You are allowed to pair up with another person or go it alone.
If you are teaming up with another person, you must email me your partner.

## Morse Code Timing

Morse code transmission is based on a standardized timing sequence which determines the length of each symbol (dot and dash) and the pauses between them. The timing is typically based on a basic unit of time, often referred to as a "dit" for the dot.

1. **Dot (Dit)**: The duration of a dot is 1 time unit.
2. **Dash (Dah)**: A dash is equal to 3 time units.
3. **Space Between Parts of the Same Letter**: The space between the dots and dashes within a letter is 1 time unit.
4. **Space Between Letters**: The space between letters is 3 time units.
5. **Space Between Words**: The space between words is 7 time units.

For example, in the transmission of the word "SOS":

- "S":
  - Dot (1 unit)
  - Space (1 unit)
  - Dot (1 unit)
  - Space (1 unit)
  - Dot (1 unit)
- Space between "S" and "O" (3 units)
- "O":
  - Dash (3 units)
  - Space (1 unit)
  - Dash (3 units)
  - Space (1 unit)
  - Dash (3 units)
- Space between "O" and "S" (3 units)
- "S":
  - Dot (1 unit)
  - Space (1 unit)
  - Dot (1 unit)
  - Space (1 unit)
  - Dot (1 unit)

This timing must be accurately implemented in the software controlling the LED on the Duo device to ensure proper Morse code transmission.

## Sample Code

### Morse Code Translator Function

This is not finished!, it doesn't handle capital letters

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "morse.h"
#include "delay.h"
#include "blink.h"

const char *char_to_morse(char c)
{
    // Define Morse code for each alphabet and digit
    static const char *morseCode[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                                        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                                        "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
                                        "...--", "....-", ".....", "-....", "--...", "---..", "----."};

    if (c >= 'a' && c <= 'z')
    {
        return morseCode[c - 'a'];
    }
    else if (c >= '0' && c <= '9')
    {
        return morseCode[c - '0' + 26];
    }
    else
    {
        return ""; // Return empty string for other characters
    }
}

// Function to convert a word to Morse code
// Use the delimiter / for any spaces between words
void encode_morse(const char *text, char *morse_output, int morse_output_size)
{
    // Loop through the text to convert each
    // character to morse code.
    // char_to_morse function is provided above but may not
    // handle all cases. (uppercase is one)
}
```

### Main Function

```c
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
```

## Testing Guidelines

1. **Unit Testing with Unity**:
   - Write unit tests for the `encode_morse` function.
   - Ensure all characters are correctly translated to Morse code.
   - Write tests for the following:
        - `test_AlphabeticInput`
        - `test_NumericInput`
        - `test_MixedAlphanumericInput`
        - `test_MixedCaseAlphanumericInput`
        - `test_CanHandleSpacesInWords`
        - `test_NonRepresentableBinaryData`
        - `test_MorseTiming`
2. **Hardware Testing**:
   - Test the LED blinking on the Duo device to match the Morse code output.
   - Verify the timing and sequence of the LED blinks.

## Sample Test Code

```c
// Include any necessary headers

#include "unity.h"
#include "delay.h"
#include "morse.h"
#include "blink.h"

extern int mock_delay_called;
extern int mock_delay_duration;

// if needed
void setUp(void)
{
    // Set up any required structures or variables before each test
}

// if needed
void tearDown(void)
{
    // Clean up after each test
}

// Test function for normal alphabetic input
void test_AlphabeticInput(void)
{
    char output[100] = {0};
    encode_morse("hello", output, sizeof(output) - 1);

    // hello
    const char *expected = ".... . .-.. .-.. ---";

    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test function for numeric input
void test_NumericInput(void)
{
    // Fill in test code
    // use test_AlphabeticInput as example
    TEST_FAIL(); // Remove after updating test
}

// Test function for mixed alphanumeric input
void test_MixedAlphanumericInput(void)
{
    // Fill in test code
    // use test_AlphabeticInput as example
    TEST_FAIL(); // Remove after updating test
}

// Test function for mixed case input
void test_MixedCaseAlphanumericInput(void)
{
    // Fill in test code
    // use test_AlphabeticInput as example
    TEST_FAIL(); // Remove after updating test
}

// Test function for words with spaces
void test_CanHandleSpacesInWords(void)
{
    // Fill in test code
    // use test_AlphabeticInput as example
    TEST_FAIL(); // Remove after updating test
}

// Test function for non-representable binary data
void test_NonRepresentableBinaryData(void)
{
    // Nothing to do here, just showing example
    char output[100] = {0};

    // Example binary data
    char binaryData[] = {0x00, 0xFF, 0x55, 0x7F};

    encode_morse(binaryData, output, sizeof(output) - 1);
    // Since Morse code is not defined for arbitrary binary data, we need to define expected behavior.
    // For example, if non-representable characters are translated as empty strings:
    TEST_ASSERT_EQUAL_STRING("", output);
}

// Test that we can blink an LED
void test_MorseTiming(void)
{
    // Initialize mock function variables
    mock_initialize();

    // Translate "SOS" to Morse code
    char output[100] = {0};
    encode_morse("SOS", output, sizeof(output) - 1);

    // Blink LED according to Morse code
    morse_blink_led(output);

    // Uncomment to see what the values are
    // printf("mock_delay_called: %d\n", mock_delay_called);
    // printf("mock_delay_duration: %d\n", mock_delay_duration);

    // Expected values
    int expected_delay_calls = 17;
    int expected_delay_duration = 27;

    // Assert the number of delay calls
    TEST_ASSERT_EQUAL(expected_delay_calls, mock_delay_called);

    // Assert the total duration of delays
    TEST_ASSERT_EQUAL(expected_delay_duration, mock_delay_duration);
}

// BONUS: Add timing test for multiple words (i.e "hello world")
// void test_MorseTimingMultipleWords(void) {}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_AlphabeticInput);
    RUN_TEST(test_NumericInput);
    RUN_TEST(test_MixedAlphanumericInput);
    RUN_TEST(test_CanHandleSpacesInWords);
    RUN_TEST(test_MixedCaseAlphanumericInput);
    RUN_TEST(test_NonRepresentableBinaryData);

#if defined(TEST)
    RUN_TEST(test_MorseTiming);

    // BONUS: Add timing test for multiple words (i.e "hello world")
    // RUN_TEST(test_MorseTimingMultipleWords);
#endif

    return UNITY_END();
}
```

## Documentation (What you turn in)

- Document your code thoroughly.
  - Include comments to explain the logic and flow of the program.
- Ensure your code checks for errors. If you use any API calls (system or library), you must check for errors. Typically negative numbers are errors if the function returns a number or `NULL` if the function returns a `char *`. You can use man pages for any libc function.
- Provide a separate file that includes a brief summary of how your code works and challenges you faced.
- Include all source/header files (all the completed stub code) in a zip archive.
- Bonus:
  - See `test.c` for details but all you need to do is add an extra test case.
  - Provide me a github link that runs your test code in a github runner. See lecture from 2/20 for an example. Make sure to include your `yml` file in the zip archive.

## TESTING on host

You can test this on the duo, by default it compiles only the test file.
This will compile a `test` binary. Run `./test` and you will see the success/fail output. You MUST pass the `TEST` flag.
Complete the empty functions so the unit tests pass.

1. Configure build (Configure only needs to be done once)
   - Create build directory: `mkdir build_host`
   - Change directory to the build folder: `cd build_host`
   - Configure cmake (notice `TEST` flag): `cmake -DCMAKE_BUILD_TYPE=TEST ..`
2. Compile (this assumes you're in the `build_host` directory)
   - `make`
3. Run the unit tests (this assumes you're in the `build_host` directory)
   - `./test`

## TESTING on the milkv duo

You can test this on the duo, by default it compiles only the test file.
This will compile a `test` binary. Run `./test` and you will see the success/fail output. You MUST pass the `TEST` flag.
Complete the empty functions so the unit tests pass.

1. Configure cmake (This only needs to be done once)
   - `docker run --rm -v $PWD:/app <username>/embedded-sdk bash -c "mkdir build_duo_test && cd build_duo_test && cmake -DCMAKE_BUILD_TYPE=TEST --toolchain ../milkv_duo.cmake .."`
2. Compile (Run anytime you make changes to your code)
   - `docker run --rm -v $PWD:/app -it <username>/embedded-sdk bash -c "cd build_duo_test && make"`
3. Push to the `test` file to the duo
   - `scp -O build_duo_test/test root@192.168.42.1:/root/`
4. Login to the duo `ssh root@192.168.42.1`
   - Make the file executable: `chmod +x test`
   - Run the test: `./test`

## Running Release or Debug on the milkv

Use your cross-compiler toolchain file as before. However you may need a slightly modified toolchain file if you're
using `wiringx` and cmake.

The steps are typically: (Notice the `RELEASE` for build type. You can change to `DEBUG` if you need to use gdb)

1. Configure cmake (This only needs to be done once)
   - `docker run --rm -v $PWD:/app <username>/embedded-sdk bash -c "mkdir build_duo && cd build_duo && cmake -DCMAKE_BUILD_TYPE=RELEASE --toolchain ../milkv_duo.cmake .."`
2. Compile (Run anytime you make changes to your code)
   - `docker run --rm -v $PWD:/app -it <username>/embedded-sdk bash -c "cd build_duo && make"`
3. Push to the `morse_blink_led` file to the duo
   - `scp -O build_duo/morse_blink_led root@192.168.42.1:/root/`
4. Login to the duo `ssh root@192.168.42.1`
   - Make the file executable: `chmod +x morse_blink_led`
   - Run the test: `./morse_blink_led`

## New Toolchain file IFF using wiringx and cmake

If you're having linking issues and you're using wiringx and cmake. Use this file instead as it correctly links the wiringx library.

milkv_duo.cmake

```cmake
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR riscv)

set(SYSROOT $ENV{SYSROOT_RISCV64})

set(CMAKE_SYSROOT ${SYSROOT})
set(CMAKE_C_COMPILER "riscv64-unknown-linux-musl-gcc")
set(CMAKE_CXX_COMPILER "riscv64-unknown-linux-musl-g++")

set(DUO_C_FLAGS "-mcmodel=medany -mabi=lp64d")
set(DUO_LINKER_FLAGS "-D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64")

set(CMAKE_C_FLAGS  "${DUO_C_FLAGS} ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${DUO_C_FLAGS} ${CMAKE_CXX_FLAGS}")

set(CMAKE_EXE_LINKER_FLAGS "${DUO_LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS}")
set(CMAKE_SHARED_LINKER_FLAGS "${DUO_LINKER_FLAGS} ${CMAKE_SHARED_LINKER_FLAGS}")
set(CMAKE_MODULE_LINKER_FLAGS "${DUO_LINKER_FLAGS} ${CMAKE_MODULE_LINKER_FLAGS}")

link_directories(".")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
```

**NOTE: if you get a `not found` error when running the binary on the duo. Run this command on the duo:**

```bash
ln -sf /lib/ld-musl-riscv64v0p7_xthead.so.1 /lib/ld-musl-riscv64xthead.so.1
```

## Troubleshooting builds

CMake doesn't always like configuration changes, you might have to delete the `build` dir and run the appropriate cmake command again.

This will delete all build dirs from the host, test, or release builds

```bash
sudo rm -rf build_*
```
