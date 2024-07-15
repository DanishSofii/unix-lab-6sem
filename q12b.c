#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>

int main(void){

	pid_t pid = fork();
	char* env_init[] = {"USER=unknown","PATH=/temp",NULL};

	if(pid < 0){
		printf("Fork error");
		return -1;
	}
	else if(pid == 0){
		if(execle("/home/danish/EndSemUnixLab/echoall2","echoall2","myarg1","myarg2",(char*)0,env_init)<0){
			printf("Ececle error");
			exit(1);
		}
	}
	if(waitpid(pid,NULL,0)<0){
		printf("wait error");
		exit(1);
	}
	if(execlp("/home/danish/EndSemUnixLab/echoall2","echoall2","myarg1",(char*)0)<0){
		printf("execlp error");
		exit(1);
	}
	return 0;
}
