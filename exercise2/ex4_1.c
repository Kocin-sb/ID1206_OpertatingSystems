#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int pid = fork();

	if(pid == 0){
		execlp("pwd","pwd",NULL);
		printf("this will only happen if the exec fails \n");
	} else {
		wait(NULL);
		printf("We are done %d\n", getpid());
	}
	return 0;
}

