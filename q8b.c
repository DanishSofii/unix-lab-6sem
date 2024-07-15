#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/wait.h>
int main(){

	pid_t pid;
	int status;
	pid_t parent_pid = getpid();
	
	pid = fork();
	if(pid == -1){
		printf("fork error");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0){
		pid_t child_pid = getpid();
		printf("child process executing PID:%d\n",child_pid);
		execl("./p1.c","p1","q8b.txt",(char*)NULL);
		perror("Execl");
		exit(EXIT_FAILURE);
	}
	else{
		printf("Parent process executing PID:%d\n",parent_pid);
		waitpid(pid,&status,0);
		printf("Parent process: child process (PID:%d) has exited\n",pid);
	}
	return 0;

}
