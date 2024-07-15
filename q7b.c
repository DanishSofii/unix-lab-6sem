#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]){

	if(argc < 3){
		fprintf(stderr,"Usuage %s\n",argv[0]);
		return -1;
	}

	int src_fd = open(argv[1],O_RDONLY);
	if(src_fd == -1){
		perror("Error opening first file\n");
		return -1;
	}

	int des_fd = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if(des_fd == -1){
		perror("error opening/creating second file\n");
		return -1;
	}
	
	char buffer[BUFFER_SIZE];
	ssize_t  bytes_read;

	while((bytes_read = read(src_fd,buffer,BUFFER_SIZE)) > 0){
		if(write(des_fd,buffer,bytes_read) != bytes_read){
			perror("write error");
			return -1;
		}
	}
	close(src_fd);
	close(des_fd);
	return  0;
}
