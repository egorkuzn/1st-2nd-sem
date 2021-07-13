#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning (disable:4996)

typedef struct elem {
	short value;
	struct elem* prev;
	struct elem* next;
}elem;

void MakeCycle(elem** head, short N) {
	elem** j = head;
	short count = 1;
	while (count != N) {
		elem* new_elem = (elem*)calloc(1, sizeof(elem));
		(*j)->next = new_elem;
		new_elem->prev = *j;
		++count;
		new_elem->value = count;
		j = &(*j)->next;
	}
	(*j)->next = *head;
	(*head)->prev = *j;
}

elem* Del(elem* j) {
	elem* t = (elem*)calloc(1, sizeof(elem));
	t->prev = j->prev;
	t->next = j->next->next;
	t->value = j->next->value;
	free(j);
	return t;
}

int main() {
	FILE* fin = fopen("input.txt", "r");
	short N, K;
	fscanf(fin, "%hi %hi", &N, &K);
	fclose(fin);
	elem* head = (elem*)calloc(1, sizeof(elem));
	head->value = 1;
	MakeCycle(&head, N);
	elem** j = &head;
	while ((*j)->prev->value != (*j)->value) {
		for (short i = 0; i < K - 1; ++i) {
			j = &(*j)->next;
		}
		*j = Del(*j);
	}
	FILE* fout = fopen("output.txt", "w");
	fprintf(fin, "%hi", (*j)->value);
	fclose(fout);
	return 0;
}