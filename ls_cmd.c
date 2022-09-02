// Program to implement ls command

#include<stdio.h>
#include<sys/dir.h>

/*
--> argc (ARGument Count) is int and stores number of command-line arguments passed by the user including the name of the program. 
So if we pass a value to a program, value of argc would be 2 

--> argv(ARGument Vector) is array of character pointers listing all the arguments.
If argc is greater than zero,the array elements from argv[0] to argv[argc-1] will contain pointers to strings.
Argv[0] is the name of the program , After that till argv[argc-1] every element is command -line arguments.
*/
int main(int argc, char *argv[2]) {
	// The DIR data type represents a directory stream
	DIR *mydir;
	// struct dirent: structure type used to return information about directory entries
	struct dirent *myfile;
	
	// The opendir() function shall open a directory stream corresponding to the directory named by the dirname argument
	// upon successful completion, opendir() shall return a pointer to an object of type DIR. Otherwise, a null pointer shall be returned and errno set to indicate the error.
	mydir = opendir(argv[1]);
	
	
	if(mydir) {
		while((myfile = readdir(mydir))) {
			printf("%s\t", myfile -> d_name);
		}
		printf("\n");
		
		closedir(mydir);
	}
	return 0;
}
