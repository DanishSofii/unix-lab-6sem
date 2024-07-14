#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
	if(argc != 2){
		fprintf(stderr,"Usuage : %s \n",argv[0]);
		return 1;
		}

	struct stat fs;
	stat(argv[1],&fs);

	printf("File : %s\n",argv[1]);
	printf("Inode Number : %ld\n",(long)fs.st_ino);
	printf("File size : %ld\n",(long)fs.st_size);
	printf("Block size : %lld\n",(long long)fs.st_blksize);
	printf("Number of links : %ld\n",(long)fs.st_nlink);
	printf("Access time : %ld\n",(long)fs.st_atime);
	printf("\n");
	return 0;
}
