#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int randomNum() {
    int file = open("/dev/urandom",O_RDONLY);
    int * buffer = malloc(sizeof(int));
    read(file,buffer,sizeof(int));
    close(file);
    return *buffer;
}

int main() {
    int r[10];
    printf("testing randomNum: %d\n", randomNum());
    printf("Generating random numbers:\n");
    int i;
    for (i = 0; i < 10; i++) {
        r[i] = randomNum();
        printf("\tr[%d]: %d\n",i,r[i]);
    }
    // r[0] = randomNum();
    // printf("\tr[%d]: %d\n",0,r[0]);
    // r[1] = randomNum();
    // printf("\tr[%d]: %d\n",1,r[1]);
    // r[2] = randomNum();
    // printf("\tr[%d]: %d\n",2,r[2]);
    // r[3] = randomNum();
    // printf("\tr[%d]: %d\n",3,r[3]);
    // r[4] = randomNum();
    // printf("\tr[%d]: %d\n",4,r[4]);
    // r[5] = randomNum();
    // printf("\tr[%d]: %d\n",5,r[5]);
    // r[6] = randomNum();
    // printf("\tr[%d]: %d\n",6,r[6]);
    // r[7] = randomNum();
    // printf("\tr[%d]: %d\n",7,r[7]);
    // r[8] = randomNum();
    // printf("\tr[%d]: %d\n",8,r[8]);
    // r[9] = randomNum();
    // printf("\tr[%d]: %d\n",9,r[9]);
    

    return 0;
}