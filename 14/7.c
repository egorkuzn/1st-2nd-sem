#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
typedef struct node
{
    char value;
    struct node* left;
    struct node* right;
}node;


node* push(node* root, char value)
{
    if (root == NULL)
    {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->value = value;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    if (value >= root->value)
        root->right = push(root->right, value);
    else
        root->left = push(root->left, value);
    return root;
}
void print1(node* root)
{
    if (root == NULL)
        return;
    printf("%c", root->value);
    print1(root->left);
    print1(root->right);
}

void print2(node* root)
{
    if (root == NULL)
        return;
    print2(root->left);
    print2(root->right);
    printf("%c", root->value);
}
int main()
{
    node* head = NULL;
    char string[30][30];
    int i = 0;
    node* nodes = (node*)malloc(sizeof(node) * 30);
    while ((i == 0) || ((i < 30) && ((string[i - 1][0] >= 'A') && (string[i - 1][0] <= 'Z')))) {
        if (!scanf("%s", string[i]))
            return 0;
        ++i;
    }
    for (int ii = i - 2; ii >= 0; --ii)
        for (int j = 0; string[ii][j] != '\0'; ++j)
            head = push(head, string[ii][j]);

    print1(head);
    return 0;
}