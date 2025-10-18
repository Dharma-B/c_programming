/*
=================================================================
LEVEL 3: CONTROL FLOW (IF/ELSE)
=================================================================
*/
#include <stdio.h>

int main() {
    int temperature = 35; // Change this value to test (e.g., 5, 20)

    if (temperature > 30) {
        printf("WARNING: Temperature is too high! (%d C)\n", temperature);
    } else if (temperature < 10) {
        printf("WARNING: Temperature is too low! (%d C)\n", temperature);
    } else {
        printf("Temperature is stable. (%d C)\n", temperature);
    }

    return 0;
}
