#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void zot(unsigned long *stop);

void foo(unsigned long *stop);

int main() {
//	char *heap = malloc(20);
//	*heap = 0x61;
//	printf("Heap pointing to : 0x%x  at %p \n", *heap, heap);
//	free(heap);

//	char *foo = malloc(20);
//	*foo = 0x62;
//	printf("foo poijnting to : 0x%x\n", *foo);

//	*heap = 0x63;
//	printf("or is it pointing to : 0x%x\n", *foo);

	long *heap = (unsigned long*)calloc(40, sizeof(unsigned long));
	free (heap);
	printf("heap[2]: 0x%lx\n", heap[2] );
	printf("heap[1]: 0x%lx\n", heap[1] );
	printf("heap[0]: 0x%lx\n", heap[0] );
	printf("heap[-1]: 0x%lx\n", heap[-1] );
	printf("heap[-2]: 0x%lx\n", heap[-2] );


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
