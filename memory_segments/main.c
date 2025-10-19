#include <stdio.h>
#include <stdlib.h>

// =================================================================
// These variables are stored in the DATA or BSS segments.
// They exist for the entire lifetime of the program.
// =================================================================

// Initialized global variable. Stored in the .data segment.
int initialized_global = 10;

// Uninitialized global variable. Stored in the .bss segment.
int uninitialized_global;

// A constant global. Often stored in a special read-only
// data segment (.rodata), near the .text segment.
const int const_global = 20;

int dummy_function() {
    // A static local variable is only initialized once.
    // Even though its scope is local to this function, its lifetime
    // is the entire program. It's stored in the .data or .bss segment.
    static int static_local = 30; // Stored in .data
    static int static_uninit_local;   // Stored in .bss
    int local_var_3 = 150;
    int local_var_4;
    const int const_local = 30;

    // =================================================================
    // This variable points to memory on the HEAP.
    // We must manage its lifetime manually.
    // =================================================================
    int* heap_var = (int*)malloc(sizeof(int));
    if (heap_var == NULL) {
        return 1; // Allocation failed
    }
    *heap_var = 60;

    printf("Address of initialised local_var_3 (on Stack):\t%p\n", (void*)&local_var_3);
    printf("Address of uninit local_var_4 (on Stack):\t%p\n", (void*)&local_var_4);
    printf("Address of const_local (on stack):\t\t%p\n", (void*)&const_local);
    // HEAP segment (dynamic memory)
    // Note: The heap address is typically between BSS and Stack.
    printf("Address of heap_var (on Heap):\t\t\t%p\n", (void*)heap_var);
    printf("Address of static_uninit_local (in .bss):\t%p\n", (void*)&static_uninit_local);
    printf("Address of static_local (in .data):\t\t%p\n", (void*)&static_local);

    // Clean up heap memory
    free(heap_var);
}

int main(int argc, char* argv[]) {
    // =================================================================
    // These variables are stored on the STACK.
    // They are created when main() is called and destroyed when main() returns.
    // =================================================================
    int local_var_1 = 40;
    int local_var_2 = 50;

    printf("--- Visualizing C Memory Segments ---\n\n");

    printf("Address of argc (function param on stack):\t%p\n", (void*)&argc);

    // STACK segment (local variables)
    // Note: Stack addresses are typically very high and grow downwards.
    printf("Address of local_var_1 (on Stack):\t\t%p\n", (void*)&local_var_1);
    printf("Address of local_var_2 (on Stack):\t\t%p\n", (void*)&local_var_2);

    dummy_function();
    printf("\n");

    // DATA and BSS segments (global/static variables)
    printf("Address of uninitialized_global (in .bss):\t%p\n", (void*)&uninitialized_global);
    printf("Address of initialized_global (in .data):\t%p\n", (void*)&initialized_global);

    // TEXT segment (where code lives)
    printf("Address of main function (in .text):\t\t%p\n", (void*)main);
    printf("Address of const_global (in .rodata):\t\t%p\n", (void*)&const_global);
    printf("\n");

    return 0;
}
