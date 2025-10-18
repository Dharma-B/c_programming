/*
=================================================================
LEVEL 10: POINTERS TO STRUCTS
=================================================================
*/
#include <stdio.h>

struct Sensor {
    int id;
    float last_reading;
    int status; // 0 = OK, 1 = Error
};

// Function takes a POINTER to a struct
void update_sensor_reading(struct Sensor* s, float new_reading) {
    // Use the -> (arrow) operator to access members from a pointer
    // This is a shortcut for (*s).last_reading
    s->last_reading = new_reading;
    
    if (new_reading > 50.0) {
        s->status = 1; // Set status to Error
    } else {
        s->status = 0; // Set status to OK
    }
}

int main() {
    struct Sensor temp_sensor = {1, 25.0, 0}; // Initializer list

    printf("[BEFORE] ID %d: %.1f (Status: %d)\n",
           temp_sensor.id,
           temp_sensor.last_reading,
           temp_sensor.status
    );

    // Pass the ADDRESS of the struct
    update_sensor_reading(&temp_sensor, 55.2);

    printf("[AFTER]  ID %d: %.1f (Status: %d)\n",
           temp_sensor.id,
           temp_sensor.last_reading,
           temp_sensor.status
    );
    
    return 0;
}
