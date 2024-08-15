Control 8-LEDs by external interrupt INT1.

Requirements:
• Configure the μC control with internal 1Mhz Clock.
• 8-Leds are connected to PORTC.
• Connect all LEDs using Positive Logic configuration.
• A roll action is perform using the LEDs each led for half second. The first LED is lit and roll down to the last LED then back to the first LED. This operation is done continuous.
• Enable the internal pull up resistance at INT1 pin (PD3).
• When the INT1 is triggered all the LEDs flash five times in five seconds.
