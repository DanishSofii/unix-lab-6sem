#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <setjmp.h>
static int gv;
static void f1(int,int,int,int);
static void f2(void);
static jmp_buf jb;

int main(void){

	int av = 2;
	register int rv = 3;
	volatile int vv = 4;
	static int sv = 5;
	gv = 1;

	if(setjmp(jb) != 0){
		printf("av = %d rv = %d vv = %d sv = %d  gv = %d\n",av,rv,vv,sv,gv);
		exit(0);
	}
	av = 95;
	rv = 96;
	vv = 97;
	sv = 98;
	gv = 99;
	f1(av,rv,vv,sv);
	exit(0);
}

static void f1(int i , int j ,int k , int l){

	printf("In f1()\n");
	printf("av = %d rv = %d vv = %d sv = %d\n",i,j,k,l);
	f2();
}

static void f2(void){
	longjmp(jb,1);
}
