#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){

	int st;
	pid_t pid1 = fork();
	pid_t pid2 = fork();

	if(pid1 == 0){
		printf("First pid :%d\n",getpid());
		sleep(2);
		exit(0);
	}
	if(pid2 == 0){
		printf("Second pid : %d\n",getpid());
		sleep(4);
		exit(0);
	}
	wait(&st);
	printf("First wait\n");
	waitpid(pid2,&st,0);
	printf("second wait\n");
	return 0;
}
