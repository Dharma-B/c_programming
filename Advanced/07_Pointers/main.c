/*
=================================================================
LEVEL 7: POINTERS
=================================================================
*/
#include <stdio.h>

// The function takes an ADDRESS (a pointer to an int)
void reset_sensor(int* p_sensor_value) {
    // Dereference the pointer with *
    // "Go to the address and set the value AT THAT ADDRESS to 0"
    *p_sensor_value = 0; 
}

int main() {
    int sensor_value = 100;
    
    printf("Sensor value before: %d\n", sensor_value);
    
    // Pass the ADDRESS of sensor_value using the & operator
    reset_sensor(&sensor_value); 
    
    // The original variable in main() is now changed
    printf("Sensor value after: %d\n", sensor_value); 
    
    return 0;
}
