// Program to implement cat command

// fcntl.h - file control options 
#include<fcntl.h>
#include<stdio.h>

// standard symbolic constants and types 
#include<unistd.h>

int main(int argc, char *argv[2]) {
	int fd, i;
	char buf[8];
	
	// O_RDONLY
	// Open for reading only.
	// The open() function establishes the connection between a file and a file descriptor
	// Upon successful completion, the function will open the file and return a non-negative integer representing the lowest numbered unused file descriptor.
	fd = open(argv[1], O_RDONLY, 0777);
	if(fd < 0) {
		printf("Error in opening file");
		return 0;
	}
	// The read() function attempts to read nbyte bytes from the file associated with the open file descriptor, fildes, into the buffer pointed to by buf.
	while((i = read(fd, buf, 8)) > 0)
		printf("%s", buf);
	
	close(fd);
	return 0;
}
