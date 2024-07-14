#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int my_sys(const char* cm){
	if(cm == NULL){
		printf("No command");
		return -1;
	}

	pid_t pid = fork();
	if(pid == -1){
		printf("Fork error\n");
		return -1;
	}
	else if(pid == 0){
		execl("/bin/sh","sh","-c",cm,(char*)NULL);
		printf("errrorrr\n");
		exit(EXIT_FAILURE);
	}
	else{
		int st;
		if(waitpid(pid,&st,0) == -1){
			return -1;
		}
		if(WIFEXITED(st)){
			return WEXITSTATUS(st);
		}
		else{
			return -1;
		}
	}
	
}
int main(){

	printf("\n Execution ls -li command\n");
	int res = my_sys("ls -li");
	if(res == -1){
		printf("Error\n");
	}
	else{
		printf("Exited with status %d\n",res);
	}

}
