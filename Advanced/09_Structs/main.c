/*
=================================================================
LEVEL 9: STRUCTS
=================================================================
*/
#include <stdio.h>

// Define the "blueprint" for a Sensor
struct Sensor {
    int id;
    float last_reading;
    int status; // 0 = OK, 1 = Error
};

int main() {
    // Create an "instance" of the struct
    struct Sensor temp_sensor;

    // Assign values using the . (dot) operator
    temp_sensor.id = 1;
    temp_sensor.last_reading = 24.5;
    temp_sensor.status = 0;

    // Print the members
    printf("Sensor ID %d (Status: %d) - Last Reading: %.1f\n",
           temp_sensor.id,
           temp_sensor.status,
           temp_sensor.last_reading
    );

    return 0;
}
