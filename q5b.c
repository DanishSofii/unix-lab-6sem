#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

void s_h(int sn){

	printf("\nCaught sigint %d\n",sn);
	struct sigaction sa;
	sa.sa_handler = SIG_DFL;
	sa.sa_flags = 0;

	sigemptyset(&sa.sa_mask);
	
	if(sigaction(SIGINT,&sa,NULL) == -1){
		printf("error\n");
		exit(EXIT_FAILURE);
	}
}

int main(){

	struct sigaction sa;
	sa.sa_handler = s_h;
	sa.sa_flags = 0;

	sigemptyset(&sa.sa_mask);
	if(sigaction(SIGINT,&sa,NULL) == -1){

		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	while(1){
		printf("press ctrl+c to trigger\n");
		pause();
	}
	return 0;
}
