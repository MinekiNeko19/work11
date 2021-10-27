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
    close (store);

    printf("reading numbers from file\n");
    int new[10];
    int temp = open("store.txt", O_RDONLY);
    read(temp,new,10*sizeof(int));
    for(i = 0; i<10;i++) {
        printf("\tr[%d]: %d\n",i,r[i]);
    }
    close(temp);

    return 0;
}