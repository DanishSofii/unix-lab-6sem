#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char* argv[]){

	struct dirent *entry;
	struct stat fs;

	DIR *dp = opendir(argv[1]);
	
	if(dp){
		while(entry = readdir(dp)){
			stat(entry->d_name,&fs);
			printf("%s %ld %ld %ld %ld %ld\n",entry->d_name,fs.st_ino,fs.st_blksize,fs.st_nlink,fs.st_atime,fs.st_size);
			}
		}
}
