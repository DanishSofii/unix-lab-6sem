#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc,char* argv[]){

	if(argc != 2){
		fprintf(stderr,"Usuage %s <filename>\n",argv[0]);
		return 1;
	}

	int fd = open(argv[1],O_RDONLY);
	if(fd == -1){
		printf("open error\n");
		return 1;
	}

	char buf[21];
	if(read(fd,buf,20)!=20){
		printf("Read error\n");
		return 1;
	}
	buf[20] = '\0';

	printf("First 20 characters of file : %s\n",buf);

	lseek(fd,10,SEEK_SET);
	if(read(fd,buf,20)!=20){
		printf("Read error\n");
		return 1;
	}

	buf[20] = '\0';

	printf("20 characters after seeking to 10th byte : %s\n",buf);


	lseek(fd,10,SEEK_CUR);
	if(read(fd,buf,20)!=20){
		printf("read error\n");
		return 1;
	}

	buf[20]  = '\0';

	printf("20 characters from current offset :%s \n",buf);
	
	off_t filesize = lseek(fd,0, SEEK_END);
	if(filesize == -1){
		printf("Lseek error\n");
		return 1;
	}
	printf("File size :%lld bytes\n",(long long)filesize);
	close(fd);
	return 0;
}
