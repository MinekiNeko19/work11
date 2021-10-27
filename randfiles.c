#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int randomNum() {
    int file = open("dev/random",O_RDONLY,0);
    int * num;
    read(file,num,sizeof(int));
    close(file);
    return *num;
}

int main() {
    int r[10];
    printf("testing randomNum: %d\n", randomNum());
    // open(dev/random,O_RDONLY,0);
    // printf("Generating random numbers:\n");
    // for (int i = 0; i < 10; i++) {
    //     read(dev/random,r[i],8);
    //     printf("\tr[%d]: %d\n",i,r[i]);
    // }
    // printf("%d\n",r[0]);
    // close(dev/random);

    return 0;
}