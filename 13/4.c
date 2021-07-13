#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning (disable:4996)

typedef struct elem {
	int value;
	struct elem* next;
}elem;

elem* push(elem* head, int value) {
	elem* new_elem = (elem*)calloc(1, sizeof(elem));
	new_elem->next = head;
	new_elem->value = value;
	return new_elem;
}

void FreeList(elem* head) {
	if (head) {
		elem* l = (elem*)calloc(1, sizeof(elem));
		l = head->next;
		free(head);
		FreeList(l);
	}
}

int Compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int* MakeArr(elem* first, elem* second, short length) {
	int* arr = (int*)calloc(length, sizeof(int));
	short count = -1;
	for (elem* i = first; i; i = i->next)
		arr[++count] = i->value;
	for (elem* i = second; i; i = i->next)
		arr[++count] = i->value;
	qsort(arr, length, sizeof(int), Compare);
	return arr;
}

int main() {
	short N, M;
	scanf("%hi%hi", &N, &M);
	elem* first = NULL;
	int x;
	for (short i = 0; i < N; ++i) {
		scanf("%d", &x);
		first = push(first, x);
	}
	elem* second = NULL;
	for (short i = 0; i < M; ++i) {
		scanf("%d", &x);
		second = push(second, x);
	}
	int* arr = MakeArr(first, second, N + M);
	FreeList(first);
	FreeList(second);
	elem* head = NULL;
	for (short i = 0; i < N + M; ++i) {
		head = push(head, arr[i]);
	}
	for (elem* i = head; i; i = i->next)
		printf("%d ", i->value);
	return 0;
}