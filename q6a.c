#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

int main(){

	int fd1,fd2;
	fd1 = open("q6a.txt",O_RDWR,0);
	fd2 = open("sample.txt",O_CREAT | O_RDWR, 0777);
	
	char buf[50];

	fd2 = dup2(fd1,fd2);

	if(fd2 < 0){
		printf("dup2 eror");
		close(fd1);
		return 1;
	}

	printf("file descriptor %d %d \n",fd1,fd2);
	
	if(read(fd1,buf,20)< 0){
		printf("read error\n");
		return 1;
	}
	if(lseek(fd2,0,SEEK_END) < 0){
		printf("Seek error");
		close(fd1);
		close(fd2);
		return 1;
	}

	if(write(fd2,buf,20)<0){
		printf("Write error");
		close(fd1);
		close(fd2);
		return 1;
	}
	printf("\n%s\n",buf);
	close(fd1);
	close(fd2);
	return 0;

}

