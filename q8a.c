#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	struct stat fs;

	lstat(argv[1],&fs);

	if(S_ISREG(fs.st_mode))
		printf("Regular");
	else if(S_ISDIR(fs.st_mode))
		printf("Directory");
	else if(S_ISCHR(fs.st_mode))
		printf("Character Special");
	else if(S_ISFIFO(fs.st_mode))
		printf("Fifo");
	else if(S_ISBLK(fs.st_mode))
		printf("Block special");
	else if(S_ISLNK(fs.st_mode))
		printf("Symbolic link");
	else if(S_ISSOCK(fs.st_mode))
		printf("Socket");
	else
		printf("** Unknown Mode **");
return 0;


}
