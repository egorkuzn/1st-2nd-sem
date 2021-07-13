#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int flag = 0;
typedef struct node {
    struct node* left, * right;
    char   val;
} node;

node* create_node(node* n, char val) {
    n->right = NULL;
    n->left = NULL;
    n->val = val;
    return n;
}


node* add_node(node* root, node* n, char val) {
    if (root) {
        if (root->val >= '0' && root->val <= '9') {
            flag = 0;
            return root;
        }
        flag = 0;
        root->left = add_node(root->left, n, val);
        if (flag) {
            flag = 1;
            return root;
        }
        root->right = add_node(root->right, n, val);

    }
    else {
        flag = 1;
        return create_node(n, val);
    }
    return root;
}

int calc(node* root) {
    if (root->val >= '0' && root->val <= '9') return (int)root->val - '0';
    int left = calc(root->left);
    int right = calc(root->right);
    switch (root->val) {
    case '*':
        return left * right;
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '/':
        if (right != 0)
            return left / right;
        else {
            printf("NO");
            exit(0);
        }
    }
    return 0;
}
int main() {
    char str[1001];
    scanf("%s", str);
    node* nodes = (node*)malloc(sizeof(node) * 1001);
    node* root = NULL;
    for (int i = 0; i < strlen(str); ++i) {
        root = add_node(root, &nodes[i], str[i]);
    }
    printf("%d", calc(root));
    free(nodes);
    return 0;
}