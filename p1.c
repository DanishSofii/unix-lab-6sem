#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc,char * argv[]){

	char * filename = argv[1];
	if(access(filename,F_OK) == 0){
		printf("FIle %s is aval and accesible\n",filename);
	}
	else{
		printf("File %s is not aval or accesible\n",filename);
	}
	return 0;


}
