/*
=================================================================
LEVEL 8: ARRAYS AND POINTERS
=================================================================
*/
#include <stdio.h>

// When passed, 'arr' decays to a pointer to the first element
int sum_array(int* arr, int size) {
    int total = 0;
    for(int i = 0; i < size; i++) {
        // arr[i] is syntactic sugar for *(arr + i)
        total += arr[i]; 
    }
    return total;
}

int main() {
    int sensor_readings[] = { 22, 25, 19, 23, 28 };
    
    // Calculate the size of the array
    // sizeof(sensor_readings) = 5 * sizeof(int)
    // sizeof(sensor_readings[0]) = sizeof(int)
    // Result is 5
    int size = sizeof(sensor_readings) / sizeof(sensor_readings[0]);

    // Pass the array (which acts as a pointer) and its size
    int total = sum_array(sensor_readings, size);
    
    printf("Total of sensor readings: %d\n", total); 
    
    return 0;
}
