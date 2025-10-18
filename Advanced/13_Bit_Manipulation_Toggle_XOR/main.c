/*
=================================================================
LEVEL 13: BIT MANIPULATION (TOGGLE/XOR)
=================================================================
*/
#include <stdio.h>
#include <stdint.h>

// 3. TOGGLE a bit (using XOR)
// Flips a bit, leaves others untouched.
// (bit ^ 1) = !bit (flipped)
// (bit ^ 0) = bit
#define LED_MASK (1 << 0) // Bit 0, the LSB

int main() {
    uint8_t led_reg = 0b00000000; // LED is OFF
    
    printf("LED state: 0b%08b\n", led_reg);

    // Toggle the LED
    led_reg ^= LED_MASK;
    printf("LED state: 0b%08b\n", led_reg); // LED is ON

    // Toggle it again
    led_reg ^= LED_MASK;
    printf("LED state: 0b%08b\n", led_reg); // LED is OFF
    
    return 0;
}
