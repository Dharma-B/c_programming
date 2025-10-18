/*
=================================================================
LEVEL 11: CONST AND VOLATILE
(No single runnable program, these are concepts)
=================================================================
*/
#include <stdio.h>
#include <stdint.h> // For uint8_t

// Concept 1: const
// The compiler will produce an error if you try to change this.
const int SENSOR_ID = 123;
// SENSOR_ID = 456; // <-- This would cause a compile-time error

// Concept 2: volatile
// Tells the compiler "this value can change at any time"
// This prevents optimizations.
// This example points to a "fake" hardware address.
volatile uint8_t* SOME_HARDWARE_REGISTER = (uint8_t*)0x40001000;

int main() {
    printf("SENSOR_ID is: %d\n", SENSOR_ID);

    // When reading a volatile variable, the compiler is forced
    // to generate code that reads from the memory address
    // every single time, not just once.
    
    // Example: wait for hardware to set a "ready" bit (Bit 0)
    // while ((*SOME_HARDWARE_REGISTER & 1) == 0) {
    //     // Wait...
    //     // Without 'volatile', this could be an infinite loop
    //     // as the compiler might optimize the read away.
    // }
    
    printf("Hardware register (simulated) is ready.\n");
    
    return 0;
}
