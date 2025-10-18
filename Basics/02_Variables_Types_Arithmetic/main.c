/*
=================================================================
LEVEL 2: VARIABLES, DATA TYPES & ARITHMETIC
=================================================================
*/
#include <stdio.h>

int main() {
    int temperature = 23;
    float humidity = 55.2;
    
    // The 'int' is promoted to a 'float' for the calculation
    float comfort_index = temperature + humidity; 
    
    // Use %d for int, %f for float. %.1f prints to 1 decimal place.
    printf("Temperature: %d, Humidity: %.1f, Comfort Index: %.1f\n", 
           temperature, 
           humidity, 
           comfort_index);
    
    return 0;
}
