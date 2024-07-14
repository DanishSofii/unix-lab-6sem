#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

	int fd = open("q1b.txt",O_RDWR);
	if(fd == -1){
		printf("Fd error");
		return 1;
		}

	pid_t pid = fork();
	if(pid == -1){
		printf("fork error");
		return 1;
		}

	else if(pid == 0){
		char buffer[10];
		read(fd,buffer,5);
		buffer[5] = '\0';
		printf("The child has read : %s\n",buffer);
		}
	else{
		wait(NULL);
		char buffer[10];
		read(fd,buffer,5);
		buffer[5] = '\0';
		printf("The child has read : %s\n",buffer);
	}
	printf("\n");
	close(fd);
	return 0;

}
