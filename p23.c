#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char * argv[]){
	if(argc != 3){
		fprintf(stderr,"Usuage %s <filename>\n",argv[0]);
		return -1;
	}
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);
	int sum = num1 + num2;

	printf("Sum is : %d\n",sum);
	return 0;

}

