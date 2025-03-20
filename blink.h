#ifndef BLINK_H
#define BLINK_H

#if !defined(TEST)
void initialize_led();
void turn_on_led();
void turn_off_led();

#define INIT_LED() initialize_led()
#define LED_HIGH() turn_on_led()
#define LED_LOW() turn_off_led()

#else
void mock_initialize_led();
void mock_led_high();
void mock_led_low();

#define INIT_LED() mock_initialize_led()
#define LED_HIGH() mock_led_high()
#define LED_LOW() mock_led_low()
#endif

void morse_blink_led(char *morse_code);

#endif // BLINK_H