#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[]){

	int fd;
	char buf[255];
	struct flock fv;

	if((fd = open(argv[1],O_RDWR)) == -1){
		fprintf(stderr,"Usuage %s",argv[0]);
		exit(0);
	}

	fv.l_type = F_WRLCK;
	fv.l_whence = SEEK_END;
	fv.l_start = SEEK_END -100;
	fv.l_len = 100;

	printf("press enter to get lock\n");
	getchar();
	printf("trying to get lock\n");

	if((fcntl(fd,F_SETLK,&fv)) == -1){
		fcntl(fd,F_GETLK,&fv);
		printf("file locked by process %d\n",fv.l_pid);
		return -1;
	}

	printf("file locked\n");
	if(lseek(fd,SEEK_END-50,SEEK_END)==-1){
		printf("seek end error\n");
		return -1;
	}

	if(read(fd,buf,100)==-1){
		printf("read error\n");
		return -1;
	}
	
	printf("data from the file : \n");
	printf("%s\n",buf);

	printf("press enter to unlock\n");
	getchar();
	
	fv.l_type = F_UNLCK;
	fv.l_whence = SEEK_SET;
	fv.l_start = 0;
	fv.l_len = 0;

	if(fcntl(fd,F_UNLCK,&fv)==-1){
		printf("Error\n");
		return -1;
	}

	printf("file unlocked\n");
	close(fd);
	return 0;
}
