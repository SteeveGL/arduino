#include <jled.h>

#define ledRed 16
#define ledGreen 4
#define ledBlue 5

JLed leds[] = {
    JLed(ledRed).Breathe(10000).DelayAfter(2000).Forever(),
    JLed(ledGreen).Breathe(20000).DelayAfter(3000).Forever(),
    JLed(ledBlue).Breathe(30000).DelayAfter(1000).Forever(),
};

JLedSequence sequence(JLedSequence::eMode::PARALLEL, leds);

void setup() { }

void loop() {
    sequence.Update();
    delay(1);
}
