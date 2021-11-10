#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
//	int pid1 = fork();
//	printf("First fork without if statement = %d\n", pid1);
//	printf("**********************\n");
	int pid = fork();
	if(pid == 0){
		printf("I am the child %d\n", getpid());
	}else {
		printf("I am %d .... My child is called %d\n",getpid(), pid);
	}
	printf("That's it %d\n", getpid());
	return 0;
}
