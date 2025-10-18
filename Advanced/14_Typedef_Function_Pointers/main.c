/*
=================================================================
LEVEL 14: TYPEDEF & FUNCTION POINTERS
=================================================================
*/
#include <stdio.h>

// 1. Define a new TYPE for a function pointer
// This type is a pointer to a function that takes (void)
// and returns (int).
typedef int (*read_func_t)(void);

// 2. Use typedef for a struct to create a 'Device' type
typedef struct {
    int id;
    read_func_t read; // A member that IS a function pointer
} Device_t;

// 3. Implement functions that match the signature
int read_temperature(void) {
    printf("Reading temperature...\n");
    return 25; // Fake sensor value
}

int read_humidity(void) {
    printf("Reading humidity...\n");
    return 60; // Fake sensor value
}

int main() {
    // 4. Create devices and assign their function pointers
    Device_t temp_sensor;
    temp_sensor.id = 1;
    temp_sensor.read = &read_temperature; // Store address of function

    Device_t hum_sensor;
    hum_sensor.id = 2;
    hum_sensor.read = &read_humidity;

    // 5. Call the functions *through* the struct members
    int temp = temp_sensor.read();
    int hum = hum_sensor.read();

    printf("Sensor %d returned: %d\n", temp_sensor.id, temp);
    printf("Sensor %d returned: %d\n", hum_sensor.id, hum);
    
    return 0;
}
