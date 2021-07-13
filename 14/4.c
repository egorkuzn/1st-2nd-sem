#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
typedef struct node
{
    int value;
    struct node* left;
    struct node* right;
}node;

node* push(node* root, int value)
{
    if (root == NULL)
    {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->value = value;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    if (value == root->value)
        return root;
    if (value > root->value)
        root->right = push(root->right, value);
    else
        root->left = push(root->left, value);
    return root;
}
int vertexCount(node* root, int level) {
    if (root == NULL || level < 1)
    {
        return 0;
    }
    if (level == 1)
    {
        return 1;
    }
    return vertexCount(root->left, level - 1) + vertexCount(root->right, level - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    node* head = NULL;
    int a;
    while (scanf("%d", &a) != -1)
        head = push(head, a);
    printf("%d", vertexCount(head, n + 1));
    return 0;
}