#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int r[10];
    printf("Generating random numbers: \n");
    for (int i = 0; i<10; i++) {
        r[i] = rand();
        printf("\tr[%d]: %d\n",i,r[i]);
    }



    return 0;
}