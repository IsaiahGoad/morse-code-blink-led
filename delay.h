#ifndef DELAY_H
#define DELAY_H

#include <unistd.h>

#if defined(TEST)
void mock_initialize();
void mock_delay(int duration);
#define DELAY(duration) mock_delay(duration)

#else
#include "wiringx.h"
// If we define RELEASE or DEBUG our delay is 0.1 seconds
#define DELAY(duration) delayMicroseconds(duration * 100000)
#endif

#endif // DELAY_H