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
void print1(node* root)
{
    if (root == NULL)
        return;
    printf("%d ", root->value);
    print1(root->left);
    print1(root->right);
}

void print2(node* root)
{
    if (root == NULL)
        return;
    print2(root->left);
    print2(root->right);
    printf("%d ", root->value);
}

int main()
{
    node* head = NULL;
    int a;
    while (scanf("%d", &a) != -1)
        head = push(head, a);
    print1(head);
    printf("\n");
    print2(head);
    return 0;
}