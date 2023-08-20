#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node ->right = NULL;
    return (node);
}
void traverseInOrder(struct node *temp)
{
    if (temp !=NULL)
    {
        traverseInOrder(temp->left);
        cout <<" "<< temp->data;
        traverseInOrder(temp->right);
    }
}
void traversePreOrder (struct node *temp)
{
    if (temp != NULL)
    {
        cout <<" "<<temp->data;
        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
    }
}
void traversePostOrder(struct node *temp)
{
    if (temp != NULL)
    {
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        cout <<" "<<temp->data;
    }
}