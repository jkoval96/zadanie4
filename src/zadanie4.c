#include <stdio.h>
#include <stdlib.h>

typedef struct TWN{
	float data;
	struct TWN *prev;
	struct TWN *next;
}TWN;

typedef struct {
	TWN *cur;
}CTWL;

CTWL *ctwl_create_empty(void) {	
	CTWL* start = malloc(sizeof(*start));
	start->cur = NULL;
	free(start);
	
	return start;
};

CTWL *ctwl_create_random(unsigned int size) {
	unsigned int i, rnd, tmp;
	CTWL* random_ctwl = malloc(sizeof(*random_ctwl));
	
	for(i = 0; i < size; i++) {
		rnd = rand() % 20;
		random_ctwl->cur->data = rnd;
		tmp = random_ctwl->cur->next;
		random_ctwl->cur->next = tmp + i;
	}
	free(random_ctwl);
	
	return random_ctwl;
};

int main() {
	srand(time(NULL));
	unsigned int size = 10;
	
	CTWL *ctwl_create_empty(void);
	CTWL *Cctwl_create_random(size);
	
	return 0;
}
