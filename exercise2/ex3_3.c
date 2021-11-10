// Orphans.c 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int pid = fork();

	if(pid == 0){
		int child = getpid();
		printf("Child : session %d, \n", getsid(child));
	} else {
		int parent = getpid();
		printf("parent: session %d\n", getsid(parent));
	}
	return 0;
}

