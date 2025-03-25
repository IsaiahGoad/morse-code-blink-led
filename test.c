#include "unity.h"
#include "delay.h"
#include "morse.h"
#include "blink.h"

extern int mock_delay_called;
extern int mock_delay_duration;

void setUp(void) {}
void tearDown(void) {}

// Test for alphabetic input
void test_AlphabeticInput(void)
{
    char output[100] = {0};
    encode_morse("hello", output, sizeof(output) - 1);
    const char *expected = ".... . .-.. .-.. ---";
    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test for numeric input
void test_NumericInput(void)
{
    char output[100] = {0};
    encode_morse("1809", output, sizeof(output) - 1);
    const char *expected = ".---- ---.. ----- ----.";
    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test for mixed alphanumeric input
void test_MixedAlphanumericInput(void)
{
    char output[100] = {0};
    encode_morse("b47m4n", output, sizeof(output) - 1);
    const char *expected = "-... ....- --... -- ....- -.";
    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test for mixed case alphanumeric input
void test_MixedCaseAlphanumericInput(void)
{
    char output[100] = {0};
    encode_morse("L8g4nD13S", output, sizeof(output) - 1);
    const char *expected = ".-.. ---.. --. ....- -. -.. .---- ...-- ...";
    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test for handling spaces between words
void test_CanHandleSpacesInWords(void)
{
    char output[300] = {0};
    encode_morse("Crazy I was crazy once They locked me in a room A rubber room", output, sizeof(output) - 1);

    // Just check for a partial start string to avoid writing the full Morse sentence
    TEST_ASSERT_TRUE_MESSAGE(strstr(output, "-.-. .-. .- --.. -.-- / .. / .-- .- ...") != NULL, "Expected phrase not found");
}

// Test for binary or unsupported input
void test_NonRepresentableBinaryData(void)
{
    char output[100] = {0};
    char binaryData[] = {0x00, 0xFF, 0x55, 0x7F};
    encode_morse(binaryData, output, sizeof(output) - 1);
    TEST_ASSERT_EQUAL_STRING("", output);
}

// Test for correct Morse timing using "SOS"
void test_MorseTiming(void)
{
    mock_initialize();
    char output[100] = {0};
    encode_morse("SOS", output, sizeof(output) - 1);
    morse_blink_led(output);
    TEST_ASSERT_EQUAL(17, mock_delay_called);
    TEST_ASSERT_EQUAL(27, mock_delay_duration);
}

// BONUS: Test Morse timing with multiple words
void test_MorseTimingMultipleWords(void)
{
    mock_initialize();
    char output[100] = {0};
    encode_morse("hello world", output, sizeof(output) - 1);
    morse_blink_led(output);
    TEST_ASSERT_EQUAL(51, mock_delay_called);       // Estimate based on total blink steps
    TEST_ASSERT_EQUAL(87, mock_delay_duration);     // Estimate based on timing units
}

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
    RUN_TEST(test_MorseTimingMultipleWords);  // Bonus test enabled
#endif

    return UNITY_END();
}
