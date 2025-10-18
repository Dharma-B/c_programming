/*
=================================================================
LEVEL 15: CALLBACK FUNCTIONS
=================================================================
*/
#include <stdio.h>

// 1. Define a function pointer type for our callback
typedef void (*event_callback_t)(int event_id);

// 2. Create the "event loop" function
// This function takes a POINTER to a callback function as an argument
void process_events(event_callback_t callback) {
    printf("Event loop started...\n");
    // Simulate finding 3 events
    for (int i = 1; i <= 3; i++) {
        int event_id = i; // A new event is "detected"
        
        // 3. "Call back" to the function the user provided
        printf("Event %d detected, calling callback...\n", event_id);
        callback(event_id);
    }
}

// 4. Implement two different callback handlers
void handle_sensor_event(int event_id) {
    printf("  -> SENSOR HANDLER: Processing event %d\n", event_id);
}

void handle_network_event(int event_id) {
    printf("  -> NETWORK HANDLER: Processing event %d\n", event_id);
}

int main() {
    // 5. Run the event loop, "registering" the sensor handler
    printf("--- Processing Sensor Events ---\n");
    process_events(&handle_sensor_event);

    // 6. Run the same loop, but "registering" the network handler
    printf("\n--- Processing Network Events ---\n");
    process_events(&handle_network_event);

    return 0;
}
