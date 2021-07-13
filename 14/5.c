#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
typedef struct node
{
    char* value;
    struct node* left;
    struct node* right;
}node;

node* push(node* root, char* value)
{
    if (root == NULL)
    {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->value = value;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    if (strcmp(value, (root->value)) == 0)
        return root;
    if (strcmp(value, (root->value)) == 1)
        root->right = push(root->right, value);
    else
        root->left = push(root->left, value);
    return root;
}

void print2(node* root)
{
    if (root == NULL)
        return;
    print2(root->left);
    printf("%s\n", root->value);
    print2(root->right);

}
int main()
{
    int n = 0;
    scanf("%d", &n);
    node* head = NULL;
    char a[1000][1000];
    while ((scanf("%s", &a[n]) != -1)) {
        head = push(head, &a[n]);
        ++n;
    }
    print2(head);
    return 0;
}