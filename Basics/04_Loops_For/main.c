/*
=================================================================
LEVEL 4: LOOPS (FOR)
=================================================================
*/
#include <stdio.h>

int main() {
    // for (initialization; condition; update)
    for(int i = 1; i <= 5; i++) {
        printf("Performing system check... %d\n", i);
    }
    
    printf("System check complete. All systems nominal.\n");
    return 0;
}
