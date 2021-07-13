#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning (disable:4996)

typedef struct elem {
	int value;
	struct elem* next;
}elem;

void DelNext(elem** j, int count) {
	elem* t = (elem*)calloc(1, sizeof(elem));
	t = (*j)->next->next;
	free((*j)->next);
	(*j)->next = t;
	(*j)->value = count;
}

elem* push(elem* head, int value) {
	elem* new_elem = (elem*)calloc(1, sizeof(elem));
	new_elem->next = head;
	new_elem->value = value;
	return new_elem;
}

int main() {
	FILE* fin = fopen("input.txt", "r");
	elem* head = NULL;
	int x, count;
	fscanf(fin, "%d", &count);
	while (fscanf(fin, "%d", &x) != EOF) {
		head = push(head, x);
	}
	elem** j = &head;
	while ((*j) && (*j)->next) {
		if ((*j)->next->value == count) {
			DelNext(j, count);
			continue;
		}
		j = &(*j)->next;
	}
	fclose(fin);
	FILE* fout = fopen("output.txt", "w");
	for (elem* j = head; j; j = j->next)
		fprintf(fout, "%d ", j->value);
	fclose(fout);
	return 0;
}