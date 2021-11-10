#include <stdio.h>

int main() {
	foo:
	printf("the code : %p .... %p\n", &&foo, &&foo);
	fgetc(stdin);
	return 0;
}
