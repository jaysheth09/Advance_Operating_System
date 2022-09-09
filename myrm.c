#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    int fileStartIndex = 0;
    int flag_i = 0;

    if(argc <=1) {
        printf("Invalid Arguments...\n");
        exit(-1);
    }

    else if(argc == 2) {
        fileStartIndex = 1;
    }

    else {
        if(argv[1][0] == '-') {
            fileStartIndex = 2;
            flag_i = 1;
        } else {
            fileStartIndex = 1;
        }
    }

    // Removing files
    int status = 0;
    while(fileStartIndex < argc) {
        if(flag_i == 1) {
            printf("rm: remove file '%s'?\n",argv[fileStartIndex]);
            char ans;
            scanf("%c", &ans);
            if(! (ans == 'Y' || ans == 'y' || ans==' ')) {
                exit(0);
            }
        }
        status = remove(argv[fileStartIndex]);
        fileStartIndex++;
        if(status != 0) {
            printf("Unsuccessful...\n");
        }
    }

    return 0;
}
