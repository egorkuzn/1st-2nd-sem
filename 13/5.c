#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

typedef struct elem {
	char word[8];
	struct node* next;
	struct node* end;
}elem;

typedef struct node {
	char word[8];
	struct node* next;
};

void push(elem** head) {
	elem* t = (elem*)calloc(1, sizeof(elem));
	scanf("%7s", t->word);
	t->next = NULL;
	*head = t;
}


int main() {
	int N;
	scanf("%d", &N);
	elem* arr = (elem*)calloc(1000001, sizeof(elem));
	for (int i = 0; i < N; ++i) {
		int k;
		scanf("%d", &k);
		if (arr[k].word[0] == '\0') {
			scanf("%7s", (arr[k]).word);
			arr[k].next = NULL;
			arr[k].end = NULL;
		}
		else if (!arr[k].next) {
			push(&arr[k].next);
			arr[k].end = arr[k].next;
		}
		else {
			push(&arr[k].end->next);
			arr[k].end = arr[k].end->next;
		}
	}
	for (int i = 0; i < 1000001; ++i) {
		if (arr[i].word[0] != '\0') {
			printf("%d %s\n", i, arr[i].word);
			for (elem* j = arr[i].next; j; j = j->next)
				printf("%d %s\n", i, j->word);
		}
	}
	return 0;
}