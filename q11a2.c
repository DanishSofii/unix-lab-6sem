#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

int main(){

	int fd1 = 0;
	int fd2 = 0;

	fd1 = open("q11a.txt",O_RDWR,0);

	dup2(fd1,fd2);


	printf("fd1 : %d , fd2 : %d\n",fd1,fd2);

	char buf[10] = "abcdefghi";

	write(fd2,buf,9);

	return 0;
}
