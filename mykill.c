#include<stdio.h>
#include<stdlib.h>

// provide acess to possixs operation ?
#include<unistd.h>

// to use signal methods
#include<signal.h>

int main(int argc, char *argv[]) {
    pid_t pid;

    int sig = 0;

    if(argc <= 1) {
        printf("Invalid Argumants...\n");
        exit(-1);
    }

    int fileNameIdx = 1;
    // checking if -f or else signal exsist or not
    if(argv[1][0] == '-') {
        int k = 0;
        while(argv[0][k]) {
            sig = (sig*10) + ((char)argv[1][k] - '0');
            k++;
        }
        fileNameIdx = 2;
    } else {
        fileNameIdx = 1;
        sig = SIGKILL;
    }

    // killing all the pids
    while(fileNameIdx < argc) {
        pid = atoi(argv[fileNameIdx]);
        int i;
        if((i= kill(pid, sig)) == 0){
			printf("process with %d id is killed\n", pid);
		} else {
            printf("Failed to kill");
        }
        fileNameIdx++;
    }
    return 0;
}
