#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TWN{
	float data;
	struct TWN *prev;
	struct TWN *next;
}TWN;

typedef struct {
	TWN *cur;
}CTWL;

CTWL *ctwl_create_empty(void) {	
	CTWL *start;
	start = (CTWL *)malloc(sizeof(CTWL));
	start->cur = NULL;
	
	return start;
}

void ctwl_cur_step_right(CTWL *list){
	list = (CTWL *)malloc(sizeof(CTWL));
	list->cur = list->cur->next;
}

void ctwl_cur_step_left(CTWL *list) {
	list = (CTWL *)malloc(sizeof(CTWL));
	list->cur = list->cur->prev;
}

TWN *ctwl_insert_left(CTWL* list, float val){
	TWN *value;
	list = (CTWL *)malloc(sizeof(CTWL));
	value->data = val;
	list->cur->prev = value;
	
	return value;
}

TWN *ctwl_insert_right(CTWL* list, float val){
	TWN *value;
	list = (CTWL *)malloc(sizeof(CTWL));
	value->data = val;
	list->cur->next = value;
	
	return value;
}

//CTWL *ctwl_create_random(unsigned int size) {
//	unsigned int i, tmp;
//	float rnd;
//	CTWL *random_ctwl;
//	random_ctwl = (CTWL *)malloc(sizeof(CTWL));
//	
//	for(i = 0; i < size; i++) {
//		rnd = rand() % 20;
//		random_ctwl->cur->data = rnd;
//		tmp = random_ctwl->cur->next;
//		random_ctwl->cur->next = tmp + i;
//	}
//	
//	return random_ctwl;
//};

void ctwl_print(CTWL *list) {
	TWN *start = list->cur;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    } else{	
		do {
			printf("%f\n", list->cur->data);
			list->cur = list->cur->next;
		} while(list->cur != start);
	}
}


int main() {
//	srand(time(NULL));
//	unsigned int size = 10;
//	CTWL *test;
	
	CTWL *empty_list = ctwl_create_empty();
    ctwl_print(empty_list);
	return 0;
}
