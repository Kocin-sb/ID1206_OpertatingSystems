#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

char global[] = "This is the Global variable";
const int readonly = 12345;

int main() {
	int pid = getpid();
    foo:
	printf("Process ID is %d \n", pid);
	printf("Global sting : %p \n", &global);
	printf("The code : %p \n", &&foo);
	printf("read only : %p\n", &readonly);

	printf("\n\n /proc/%d/maps  \n\n", pid);
	char command[50];
	sprintf(command, "cat /proc/%d/maps",pid);
	system(command);

	return 0;
}
