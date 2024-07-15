#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){

	pid_t pid,pid2,pid3;
	pid = fork();
	if(pid < 0){
		printf("fork error");
		return 1;
	}
	else if(pid == 0){
		if((pid3 = fork()) < 0){
			printf("fork error");
		}
		else if(pid3 == 0){
			sleep(5);
			printf("child pid : %d\n",getpid());
			printf("Second child, parent pid :%d\n",getppid());
			exit(0);
		}
		else{
			printf("Child pid : %d\n",getpid());
			exit(0);
		}
	}
	if((pid2 = waitpid(pid , NULL, 0))!=  pid){
		printf("waitpid error");
	}
	printf("terminated child process is : %d\n",pid2);
	return 0;
}
