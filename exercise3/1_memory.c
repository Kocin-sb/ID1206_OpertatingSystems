#include <stdio.h>
#include <stdlib.h>


#define MEMORY 100		//size of mem

int memory[MEMORY];		//The Mem

typedef struct array {
	int size;		//size of the array
	int *segment;		//pointer tothe allocated memory segment
	struct array* next;	//pointer to the next array
}	array;

array sentinel = {0, &memory[MEMORY], NULL};
array dummy = {1, &memory[-1], &sentinel};

array *allocated = &dummy;

void check(){
	array *nxt = allocated;
	while(nxt != allocated){
		printf("array (%p) : size %2d, segment %3d, next %14p \n",nxt, nxt->size, nxt->next, (int)(nxt->segment - memory));
	nxt = nxt->next;
	}
	return;
}

int main(){
	check();
	return 0;
}

array *allocate (int size){
	array *nxt = allocated;

	while(nxt->size != 0){
		if((nxt->next->segment - (nxt->segment + nxt->size)) >= size){
			array *new = (array*)malloc(sizeof(array));

			new->size = size;
			new->segment = (nxt->segment+nxt->size);
			new->next = nxt->next;
			new->next = new;
			return new;
		}
		nxt = nxt->next;
	}
	return NULL;
}

array *create(int size){
	printf("create an array of size %4d ..", size);
	array *new = allocate (size);
	if(new == NULL) {
		printf("Out Of Memory");
		exit(-1);
	}
	printf("done\n");
	return new;
}

array delete(array *arr){
	printf()"delete array (%p) of size %4d",arr, arr->size);
	array *nxt = allocated;
	array *prev = NULL;

	whie(nxt != arr){
	//
	}
	//
	//
	printf("done\n");
	return;
}

void set (array *arr, int pos, int val){
	arr->segment[pos-1] = val;
}

int get(array *arr, int pos){
	return arr->segment[pos-1];
}
