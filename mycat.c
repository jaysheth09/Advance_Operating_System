#include<stdio.h>
#include<stdlib.h>

// header for file handling
#include<fcntl.h>

// function for reading file
void mycat(int fd) {
    if (fd < 0) {
        printf("Error while Opening file...");
        return;
    }

    char buf[1];
    int i;
    while((i = read(fd, buf, sizeof(buf)) > 0))
        printf("%s", buf);
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Invalid arguments...");
        exit(0);
    }

    int fd;

    if(argc == 2) {
        fd = open(argv[1], O_RDONLY, 0777);
        mycat(fd);
    }
    else {
        for(int i=1; i<argc; i++) {
            fd = open(argv[i], O_RDONLY, 0777);
            mycat(fd);
        }
    }
    close(fd);
    return 0;
}

/*
How to Compile and Run file
-> To compile > gcc cat_cmd.c -o cat_cmd
-> To run > ./cat_cmd <filename>
*/

