#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(){
	int fd1 = 0;
	int fd2 = 0;

	char buf[10] = "abcdef";

	fd1 = open("q11a.txt",O_RDWR,0);

	fd2 = dup(fd1);

	printf("fd1 : %d , fd2 : %d\n",fd1,fd2);

	write(fd2,buf,6);

	return 0;
}

