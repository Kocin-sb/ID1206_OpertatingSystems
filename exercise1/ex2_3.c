#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void zot(unsigned long *stop);

void foo(unsigned long *stop);

int main() {
	int pid = getpid();
	unsigned long p = 0x1;
      ok:
	foo(&p);

     back:
	printf("  p :  %p \n", &p);
	printf("  back: %p  \n" , &&back);
	printf("  ok : %p  \n" , &&ok);

	printf("\n\n /proc/%d/maps \n\n", pid);
	char command[50];
	sprintf(command, "cat /proc/%d/maps", pid);
	system(command);

	return 0;
}

void zot(unsigned long *stop){
	unsigned long r = 0x3;

	unsigned long *i;
	for(i = &r - 1; i <= stop+5; i++){
		printf("%p      0x%lx \n", i, *i);
	}
}

void foo(unsigned long *stop) {
	unsigned long q = 0x2;

	zot(stop);
}
