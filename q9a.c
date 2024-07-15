#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){

	mode_t new_umask = 0022;
	mode_t old_umask;
	char *filepath = "q9a.txt";
	mode_t new_mode = 0644;

	old_umask = umask(new_umask);

	printf("old umask wask: %03o, new umask value : %03o\n",old_umask,new_umask);
	
	int fd = open(filepath,O_CREAT | O_WRONLY,0777);
	if(fd == -1){
		printf("file open error");
		return 1;
	}

	close(fd);
	if(chmod(filepath,new_mode) == -1){
		printf("chmod error");
		return 1;
	}
	printf("changed permissions of %s to %03o\n",filepath,new_mode);
	return 0;

}
