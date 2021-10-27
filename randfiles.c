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
    // printf("testing randomNum: %d\n", randomNum());
    printf("Generating random numbers:\n");
    int i;
    for (i = 0; i < 10; i++) {
        r[i] = randomNum();
        printf("\tr[%d]: %d\n",i,r[i]);
    }

    printf("writing numbers into file\n");
    int store = open("store.txt",O_WRONLY | O_APPEND | O_CREAT, 0644);
    write(store,r,10*sizeof(int));

    printf("reading numbers from file\n");
    int new[10];


    close (store);

    return 0;
}