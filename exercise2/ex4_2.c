#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
	int pid = fork();

	if(pid == 0){
		int fd = open("quotes.txt", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
		dup2(fd, 1);
		close(fd);
		execl("boba.out","boba.out",NULL);
		printf("this will only happen if the exec fails \n");
	} else {
		wait(NULL);
		printf("We are done %d\n", getpid());
	}
	return 0;
}

