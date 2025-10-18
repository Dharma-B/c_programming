/*
=================================================================
LEVEL 12: BIT MANIPULATION (SET/CLEAR)
=================================================================
*/
#include <stdio.h>
#include <stdint.h> // For uint8_t

// 1. SET a bit (using OR)
// Turns a bit ON, leaves others untouched.
// (bit | 1) = 1
// (bit | 0) = bit
#define SENSOR_ENABLE_MASK (1 << 3) // 0b00001000

// 2. CLEAR a bit (using AND & NOT)
// Turns a bit OFF, leaves others untouched.
// (bit & 0) = 0
// (bit & 1) = bit
#define HIGH_SPEED_MASK (1 << 5)    // 0b00100000

int main() {
    uint8_t control_reg = 0b00100000; // Bit 5 is ON
    
    printf("Original: 0b%08b\n", control_reg); // GNU extension

    // 1. Set Bit 3 (Sensor Enable)
    control_reg |= SENSOR_ENABLE_MASK;
    printf("After SET:  0b%08b\n", control_reg); // 0b00101000

    // 2. Clear Bit 5 (High-Speed Mode)
    control_reg &= ~HIGH_SPEED_MASK; // Note the ~ (NOT)
    printf("After CLR:  0b%08b\n", control_reg); // 0b00001000
    
    return 0;
}
