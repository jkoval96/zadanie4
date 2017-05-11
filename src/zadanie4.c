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

void ctwl_destroy(CTWL* list){
	TWN * next, * start = list->cur;
	
	do {
		next = list->cur->next;
		free(list->cur);
		list->cur = next;
	} while (list->cur != start);
}


void ctwl_cur_step_right(CTWL *list){
	list->cur = list->cur->next;
}

void ctwl_cur_step_left(CTWL *list) {
	list->cur = list->cur->prev;
}

TWN *ctwl_insert_left(CTWL* list, float val){
	TWN *element;
	TWN *save = list->cur->prev;
	element = (TWN *)malloc(sizeof(TWN));
	element->data = val;
	
	list->cur->prev = element;
	element->next = list->cur;
	element->prev = save;
	save->next = element;
	
	return element;
}

TWN *ctwl_insert_right(CTWL* list, float val){
	TWN *element;
	TWN *save = list->cur->next;
	element = (TWN *)malloc(sizeof(TWN));
	element->data = val;
	
	list->cur->next = element;
	element->prev = list->cur;
	element->next = save;
	save->prev = element;
		
	return element;
}

CTWL *ctwl_create_random(unsigned int size) {
	unsigned int i;
	float rnd;
	CTWL *random_ctwl;
	TWN *element;
	
	if (size == 0) return ctwl_create_empty();
		
	element = (TWN *)malloc(sizeof(TWN));
	random_ctwl = (CTWL *)malloc(sizeof(CTWL));
	
	element->prev = element;
	element->next = element;
	random_ctwl->cur = element;
	
	for(i = 1; i < size; i++) {		
		rnd = rand() % 20;
		element->data = rnd;	
		random_ctwl->cur = ctwl_insert_right(random_ctwl, rnd);	
	}
	return random_ctwl;
}

void ctwl_print(CTWL *list) {
	TWN *start = list->cur;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    } else {	
		do {
			printf("%f\n", list->cur->data);
			ctwl_cur_step_right(list);
		} while(list->cur != start);
	}
}


int main() {
	srand(time(NULL));
	unsigned int size = 10;
	CTWL *test;
	
//	CTWL *empty_list = ctwl_create_empty();
//  ctwl_print(empty_list);
  	
  	//ctwl_destroy(empty_list);
    
    test = ctwl_create_empty();
    test = ctwl_create_random(size);
	ctwl_print(test);
	ctwl_destroy(test);
	
	return 0;
}
