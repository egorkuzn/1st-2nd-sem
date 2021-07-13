#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define max(a, b) (a>b?a:b)
#define N (100000)                      // 10^5

typedef struct actor_bio {
    int birth;
    char* name;
    char* country;
} actor_bio;

typedef struct actor_movie {
    char* name;
    char* films;
    struct actor_movie* next;
} actor_movie;

typedef struct node {
    struct node* l, * r;
    actor_movie* val;
    int h;
} node;

void push(actor_movie* head, actor_movie* nw) {
    nw->next = head->next;
    head->next = nw;
}

int TakeHeight(node* n) {
    return (n) ? n->h : 0;
}

int TakeWeight(node* n) {
    return TakeHeight(n->r) - TakeHeight(n->l);
}

void update_TakeHeight(node* n) {
    int l = TakeHeight(n->l);
    int r = TakeHeight(n->r);

    n->h = max(l, r) + 1;
}

node* r_rotate(node* a, node** root) {

    node* b = a->l;
    a->l = b->r;
    b->r = a;

    update_TakeHeight(a);
    update_TakeHeight(b);

    if ((*root) == a)
        (*root) = b;

    return b;
}

node* l_rotate(node* b, node** root) {

    node* a = b->r;
    b->r = a->l;
    a->l = b;

    update_TakeHeight(b);
    update_TakeHeight(a);

    if ((*root) == b)
        (*root) = a;

    return a;
}

node* l_r_rotate(node* n, node** root) {
    n->l = l_rotate(n->l, root);
    return r_rotate(n, root);
}

node* r_l_rotate(node* n, node** root) {
    n->r = r_rotate(n->r, root);
    return l_rotate(n, root);
}

node* balance(node* n, node** root) {

    update_TakeHeight(n);

    if (TakeWeight(n) == 2) {
        if (TakeWeight(n->r) < 0)
            return r_l_rotate(n, root);
        else
            return l_rotate(n, root);
    }

    if (TakeWeight(n) == -2) {
        if (TakeWeight(n->l) > 0)
            return l_r_rotate(n, root);
        else
            return r_rotate(n, root);
    }

    return n;
}

node* create_node(node* n, actor_movie* val) {

    n->h = 1;
    n->val = val;

    n->l = NULL;
    n->r = NULL;

    return n;
}

node* add_node(node* n, node* newn, actor_movie* val, node** root) {

    if (n) {
        int eq = strcmp(val->name, n->val->name);
        if (eq > 0)
            n->r = add_node(n->r, newn, val, root);
        else if (eq < 0)
            n->l = add_node(n->l, newn, val, root);
        else {
            push(n->val, val);
            return n;
        }
    }
    else {
        return create_node(newn, val);
    }
    return balance(n, root);
}

void print_tree(node* root, actor_bio actor)
{
    if (root) {
        int eq = strcmp(actor.name, root->val->name);
        if (eq > 0)
            print_tree(root->r, actor);
        else if (eq < 0)
            print_tree(root->l, actor);
        else {
            actor_movie* data = root->val;
            while (data != NULL) {
                printf("\"%s\" %d \"%s\" \"%s\" \"%s\"\n", actor.name, actor.birth, actor.country, actor.name, data->films);
                data = data->next;
            }
        }
    }
}

int main(void) {
    actor_bio* actors = (actor_bio*)calloc(100000, sizeof(actor_bio));
    actor_movie* movies = (actor_movie*)calloc(100000, sizeof(actor_movie));

    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i)
    {
        getchar();

        char* s = (char*)calloc(31, 1);
        scanf("%[^\"]s", s);
        actors[i].name = s;

        getchar();

        int y;
        scanf("%d", &y);
        actors[i].birth = y;

        getchar(); getchar();

        s = (char*)calloc(11, 1);
        scanf("%[^\"]s", s);
        actors[i].country = s;

        getchar(); getchar();
    }

    int m;
    scanf("%d", &m);
    getchar();

    for (int i = 0; i < m; ++i)
    {
        getchar();

        char* s = (char*)calloc(31, 1);
        scanf("%[^\"]s", s);
        movies[i].name = s;

        getchar(); getchar(); getchar();

        s = (char*)calloc(21, 1);
        scanf("%[^\"]s", s);
        movies[i].films = s;
        movies[i].next = NULL;

        getchar(); getchar();
    }

    node* nodes = (node*)malloc(sizeof(node) * N);
    node* root = NULL;

    for (int i = 0; i < m; ++i) {
        root = add_node(root, &nodes[i], &movies[i], &root);
    }

    //printf("%d", root->h);

    for (int i = 0; i < n; ++i) {
        print_tree(root, actors[i]);
    }

    return EXIT_SUCCESS;
}