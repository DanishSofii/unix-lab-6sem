#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	pid_t pid = fork();
	if(pid < 0){
		printf("error fork");
	}
	else if(pid == 0){
		if(execl("textinterpreter","test","myarg1","myarg2","myarg4",(char*)0)<0){
			printf("error");
		}
		if(waitpid(pid,NULL,0)<0)
			printf("error");
	}
	return 0;

}
