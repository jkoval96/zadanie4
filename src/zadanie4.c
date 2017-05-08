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
	CTWL *start = malloc(sizeof(CTWL *));
	start->cur = NULL;
	free(start);
	
	return start;
};

void ctwl_cur_step_right(CTWL *list){
	list = malloc(sizeof(CTWL *));
	list->cur = list->cur->next;
	free(list);
};

void ctwl_cur_step_left(CTWL *list) {
	list = malloc(sizeof(CTWL *));
	list->cur = list->cur->prev;
	free(list);
};

TWN *ctwl_insert_left(CTWL* list, float val){
	list = malloc(sizeof(CTWL *));
	ctwl_cur_step_left(list);
	list->cur->data = val;
	free(list);	
	
	//return list->cur->data = val;
};

TWN *ctwl_insert_right(CTWL* list, float val){
	list = malloc(sizeof(CTWL *));
	list->cur = list->cur->next;
	list->cur->data = val;
	free(list);	
};

CTWL *ctwl_create_random(unsigned int size) {
	unsigned int i, tmp;
	float rnd;
	CTWL *random_ctwl = malloc(sizeof(CTWL *));
	
	for(i = 0; i < size; i++) {
		rnd = rand() % 20;
		random_ctwl->cur->data = rnd;
		tmp = random_ctwl->cur->next;
		random_ctwl->cur->next = tmp + i;
	}
	free(random_ctwl);
	
	return random_ctwl;
};

void ctwl_print(CTWL *list) {
	int i;
	
};


int main() {
	srand(time(NULL));
	unsigned int size = 10;
	
	CTWL *ctwl_create_empty(void);
	CTWL *ctwl_create_random(size);
	
	return 0;
}
