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
    char output[100] = {0};
    encode_morse("1809", output, sizeof(output) - 1);

    // hello
    const char *expected = ".... . .-.. .-.. ---";

    TEST_ASSERT_EQUAL_STRING(expected, output);
    //TEST_FAIL(); // Remove after updating test
}

// Test function for mixed alphanumeric input
void test_MixedAlphanumericInput(void)
{
    // Fill in test code
    // use test_AlphabeticInput as example
    char output[100] = {0};
    encode_morse("b47m4n", output, sizeof(output) - 1);

    // hello
    const char *expected = ".... . .-.. .-.. ---";

    TEST_ASSERT_EQUAL_STRING(expected, output);
    //TEST_FAIL(); // Remove after updating test
}

// Test function for mixed case input
void test_MixedCaseAlphanumericInput(void)
{
    // Fill in test code
    // use test_AlphabeticInput as example
    char output[100] = {0};
    encode_morse("L8g4nD13S", output, sizeof(output) - 1);

    // hello
    const char *expected = ".... . .-.. .-.. ---";

    TEST_ASSERT_EQUAL_STRING(expected, output);
    //TEST_FAIL(); // Remove after updating test
}

// Test function for words with spaces
void test_CanHandleSpacesInWords(void)
{
    // Fill in test code
    // use test_AlphabeticInput as example
    char output[100] = {0};
    encode_morse("Crazy I was crazy once They locked me in a room A rubber room A rubber room with rats And rats make me crazy Crazy I was crazy once", output, sizeof(output) - 1);

    // hello
    const char *expected = ".... . .-.. .-.. ---";

    TEST_ASSERT_EQUAL_STRING(expected, output);
    //TEST_FAIL(); // Remove after updating test
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
