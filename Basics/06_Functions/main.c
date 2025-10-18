/*
=================================================================
LEVEL 6: FUNCTIONS
=================================================================
*/
#include <stdio.h>

// Function definition (the "blueprint")
// It takes one 'int' parameter named 'temp_value'
void check_temperature(int temp_value) {
    if (temp_value > 30) {
        printf("WARNING: Temperature is too high! (%d C)\n", temp_value);
    } else if (temp_value < 10) {
        printf("WARNING: Temperature is too low! (%d C)\n", temp_value);
    } else {
        printf("Temperature is stable. (%d C)\n", temp_value);
    }
}

int main() {
    printf("Checking sensor readings:\n");
    
    // Function calls
    check_temperature(25); // Will print "Stable"
    check_temperature(5);  // Will print "Too low"
    check_temperature(40); // Will print "Too high"
    
    return 0;
}
