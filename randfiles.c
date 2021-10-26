#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int r[10];
    int * p = r;
    open("dev/random",O_RDONLY,0);
    read("dev/random",r[0],8);
    printf("%d\n",r[0]);
    close("dev/random");

    return 0;
}