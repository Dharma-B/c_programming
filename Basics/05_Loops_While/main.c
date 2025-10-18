/*
=================================================================
LEVEL 5: LOOPS (WHILE)
=================================================================
*/
#include <stdio.h>

int main() {
    int sensor_status = 0; // 0 = Not Ready
    int checks_made = 0;

    // Loop continues AS LONG AS sensor_status is 0
    while (sensor_status == 0) {
        checks_made++;
        printf("Checking sensor... (Attempt %d)\n", checks_made);

        // Simulation logic: sensor becomes ready on the 3rd check
        if (checks_made == 3) {
            sensor_status = 1; // Set status to "Ready"
        }
    } 

    // This code is only reached AFTER the loop condition becomes false
    printf("Sensor is ready!\n");
    
    return 0;
}
