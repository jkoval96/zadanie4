#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CTWL_OK 1
#define CTWL_FAIL 0

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
	if(start) {
		start->cur = NULL;
	} else {
		return 0;
	}
	
	return start;
}

void ctwl_destroy(CTWL* list){
	TWN * next, * start = list->cur;
	
	if (list == NULL) {
		return;
	} 
	do {
		next = list->cur->next;
		free(list->cur);
		list->cur = next;
	} while (list->cur != start);
	
	free(list);
}

void ctwl_cur_step_right(CTWL *list){
	if(list == NULL) {
		list->cur = NULL;
	} else {
		list->cur = list->cur->next;
	}
}

void ctwl_cur_step_left(CTWL *list) {
	if(list == NULL) {
		list->cur = NULL;
	} else {
		list->cur = list->cur->prev;
	}
}

TWN *ctwl_insert_left(CTWL* list, float val){
	TWN *element;
	TWN *save = list->cur->prev;
	
	element = (TWN *)malloc(sizeof(TWN));
	element->data = val;
	element->next = element;
	element->prev = element;
	
	if(list->cur == NULL) {
		element->next = element;
		element->prev = element;
		list->cur = element;
		return element;
	} else {
		list->cur->next = element;
		element->next = list->cur;
		element->prev = save;
		save->next = element;
	}
	
	return element;
}

TWN *ctwl_insert_right(CTWL* list, float val){
	TWN *element;
	TWN *save = list->cur->next;
	
	element = (TWN *)malloc(sizeof(TWN));
	element->data = val;
	
	if(list->cur == NULL) {
		element->next = element;
		element->prev = element;
		list->cur = element;
		return element;
	} else {
		list->cur->next = element;
		element->prev = list->cur;
		element->next = save;
		save->prev = element;
	}
	return element;
}

CTWL *ctwl_create_random(unsigned int size) {
	unsigned int i;
	float rnd;
	CTWL * random_ctwl;
//	TWN * element;
	
	if (size == 0) {
		return ctwl_create_empty();
	}	
//	element = (TWN *)malloc(sizeof(TWN));
	random_ctwl = (CTWL *)malloc(sizeof(CTWL));
//	element->prev = element;
//	element->next = element;
//	random_ctwl->cur = element;
//	
//	rnd = rand() % 20;
//	element->data = rnd;
	for(i = 0; i < size; i++) {		
		rnd = rand() % 20;	
		random_ctwl->cur = ctwl_insert_right(random_ctwl, rnd);	
	}
	return random_ctwl;
}

void ctwl_print(CTWL *list) {
	TWN * start = list->cur;
	
	if (list == 0) {
		printf("List is empty or could not be constructed\n");
        return;
	}
    if (start == NULL) {
        printf("List is empty or could not be constructed\n");
        return;
    } else {	
		do {
			printf("%f\n", list->cur->data);
			ctwl_cur_step_right(list);
		} while(list->cur != start);
	}
}


CTWL * ctwl_create_random_bimodal(unsigned int size) {
	unsigned int i, j;
	float rnd, value;
	CTWL * random_bi;
	TWN * element;
	
	if (size < 4) {
		return 0;
	} 
		
	element = (TWN *)malloc(sizeof(TWN));
	random_bi = (CTWL *)malloc(sizeof(CTWL));
	
	element->prev = element;
	element->next = element;
	random_bi->cur = element;	
	
	rnd = rand() % 20;
	element->data = rnd;
	j = rand() % (size - 3) + 2;
	
	if (size == 4) {
		for(i = 1; i < size; i++) {
			rnd = rand() % 20 + rnd + 1;
			random_bi->cur = ctwl_insert_right(random_bi, rnd);
			if (i == 2) {
				value = random_bi->cur->prev->data;
				random_bi->cur->prev->data = random_bi->cur->data;
				random_bi->cur->data = value;
			}
		}
	 }else {
		for(i = 1; i < size; i++) {		
			rnd = rand() % 20 + rnd + 1;
			random_bi->cur = ctwl_insert_right(random_bi, rnd);	
			if (i == j) {
				value = random_bi->cur->prev->data;
				random_bi->cur->prev->data = random_bi->cur->data;
				random_bi->cur->data = value;
			}
		}
	}
	return random_bi;
}

char ctwl_delete(CTWL* list) {
	CTWL * save;
	save = (CTWL *)malloc(sizeof(CTWL));
	if(list->cur != NULL) {
		save->cur = list->cur;
		list->cur = save->cur->next;
		list->cur->prev = save->cur->prev;
		save->cur->prev->next = list->cur;
		
		save->cur = NULL;
		free(save);
		return CTWL_OK;
	} else {
		
		return CTWL_FAIL;
	}
	
	
}

int main() {
	srand(time(NULL));
	unsigned int size = 10;
	CTWL * test, * test2;

//	test = ctwl_create_empty();
//	test = ctwl_create_random_bimodal(size);
//	ctwl_print(test);
	
	test2 = ctwl_create_empty();
	test2->cur = ctwl_insert_right(test2,10);
	//test2 = ctwl_create_random(10);
	ctwl_print(test2);
	return 0;
}
