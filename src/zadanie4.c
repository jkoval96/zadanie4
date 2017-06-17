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
	
	list->cur = NULL;
	free(list);
}

void ctwl_cur_step_right(CTWL *list){
	if(list == NULL) {
		list->cur = NULL;
	} else if(list->cur == NULL) {
		return;
	} else {
		list->cur = list->cur->next;
	}
}

void ctwl_cur_step_left(CTWL *list) {
	if(list == NULL) {
		list->cur = NULL;
	} else if(list->cur == NULL) {
		return;
	} else {
		list->cur = list->cur->prev;
	}
}

TWN *ctwl_insert_left(CTWL* list, float val){
	TWN *element;
	TWN *save;
	
	element = (TWN *)malloc(sizeof(TWN));
	element->data = val;
	
	if(list->cur == NULL) {
		element->next = element;
		element->prev = element;
		list->cur = element;
		return element;
	} else {
		save = list->cur->prev;
		list->cur->prev = element;
		element->next = list->cur;
		element->prev = save;
		save->next = element;
	}
	
	return element;
}

TWN *ctwl_insert_right(CTWL* list, float val){
	TWN *element;
	TWN *save;
	
	element = (TWN *)malloc(sizeof(TWN));
	element->data = val;
	
	if(list->cur == NULL) {
		list->cur = element;
		element->next = element;
		element->prev = element;
		return element;
	} else {
		save = list->cur->next;
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
	
	if (size == 0) {
		return ctwl_create_empty();
	}		
	random_ctwl = ctwl_create_empty();
	
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
	unsigned int i, x1, x2, x3;
	float rnd, start, value;
	CTWL * random_bi;
	
	if (size < 4) {
		return 0;
	} 
		
	random_bi = ctwl_create_empty();
	x1 = rand() % (size - 2);
	if(x1 == 0) {
		x2 = rand() % (size - 3) + 1;
		x3 = x2 + rand() % (size - x2 - 2) + 1; 
	} else if(x1 == size - 3){			
		x2 = x1 + 1;
		x3 = x2 + 1; 
	} else {
		x2 = x1 + rand() % (size - x1 - 2) + 1;
		if(x2 == size - 2) {
			x3 = x2 + 1;
		} else {
			x3 = x2 + rand() % (size - x2 - 2) + 1;
		}
	}
	rnd = rand() % 20;
	start = rnd;

	if (size == 4) {
		for(i = 0; i < size; i++) {
			rnd = rand() % 20 + rnd + 1;
			random_bi->cur = ctwl_insert_right(random_bi, rnd);
			if (i == 2) {
				value = random_bi->cur->prev->data;
				random_bi->cur->prev->data = random_bi->cur->data;
				random_bi->cur->data = value;
			}
		}
	 } else { 
		if(x1 == 0) {
			start = rnd;
			random_bi->cur = ctwl_insert_right(random_bi, rnd);
			
			for(i = x1; i < x2; i++) {
				rnd = rnd - 1;
				random_bi->cur = ctwl_insert_right(random_bi, rnd);
			}
			for(i = x2; i < x3; i++) {
				rnd = rnd + 1;
				random_bi->cur = ctwl_insert_right(random_bi, rnd);
			}
			for(i = x3; i < size - 1; i++) {
				rnd = rnd - 1;
				if((i == size - 2) && (rnd >= start)) {
					rnd = start - 1;
				}
				random_bi->cur = ctwl_insert_right(random_bi, rnd);
			}
		} else {
			for(i = 0; i < x1; i++) {
				rnd = rnd + 1;
				random_bi->cur = ctwl_insert_right(random_bi, rnd);
			}
			for(i = x1; i < x2; i++) {
				rnd = rnd - 1;
				random_bi->cur = ctwl_insert_right(random_bi, rnd);
			}
			for(i = x2; i < x3; i++) {
				rnd = rnd + 1;
				random_bi->cur = ctwl_insert_right(random_bi, rnd);
			}
			for(i = x3; i < size; i++) {
				rnd = rnd - 1;
				if((i == size - 1) && (rnd >= start)) {
					rnd = start - 1;
				}
				random_bi->cur = ctwl_insert_right(random_bi, rnd);
			}
		}
	}

	return random_bi;
}

char ctwl_delete(CTWL* list) {
	CTWL * save;
	
	if(list->cur == list->cur->next) {
		list->cur = NULL;
		free(list->cur);
		
		return CTWL_OK;
	} else if(list->cur != NULL) {
		save->cur = list->cur;
		list->cur = save->cur->next;
		list->cur->prev = save->cur->prev;
		save->cur->prev->next = list->cur;
		
		save->cur = NULL;
		free(save->cur);
		
		return CTWL_OK;
	} else {
		return CTWL_FAIL;
	}
	
	
}

int main() {
	srand(time(NULL));
	unsigned int size = 10;
	CTWL * test, * test2;

	test = ctwl_create_random_bimodal(size);
	ctwl_print(test);

	return 0;
}
