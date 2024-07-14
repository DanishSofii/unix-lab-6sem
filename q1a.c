#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){

	if(argc < 2){
		fprintf(stderr,"Usuage : %s\n",argv[0]);
		return 1;
		}
	
	int fd = open(argv[1],O_RDONLY);
	if(fd == -1){
		perror("Open error");
		return 1;
		}
	int filesize = lseek(fd,0,SEEK_END);
	if(filesize == -1){
		perror("lseek error");
		return 1;
 		}

	for(int i = 1; i<=filesize;i++){
		lseek(fd,-i,SEEK_END);
		char c;
		if(read(fd,&c,1) !=1){
			perror("read error");
			return 1;
			}
		putchar(c);
		}
	printf("\n");
	close(fd);
	return 0;

}
