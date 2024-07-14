#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <utime.h>
#include <sys/stat.h>

int main(int argc,char* argv[]){

	if(argc < 3){
		fprintf(stderr,"Usuage %s <filename>\n",argv[0]);
		return 1;
	}

	struct stat fs;
	if(stat(argv[1],&fs) == -1){
		printf("Error\n");
		return 1;
	}

	struct utimbuf new_times;
	new_times.actime = fs.st_atime;
	new_times.modtime = fs.st_mtime;

	if(utime(argv[2],&new_times) == -1){
		printf("error utime");
		return 1;
	}
	return 0;
}
