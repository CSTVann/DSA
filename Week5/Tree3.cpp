#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *newNode(char data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node -> data = data;
    node ->  left = NULL;
    node ->  right = NULL;
    return (node);
};

void traverseInOrder(struct node *temp)
{
    if(temp != NULL)
    {
        traverseInOrder(temp -> left);
        cout << " " << temp ->  data;
        traverseInOrder(temp -> right);
    }
   
};

void traversePreOrder(struct node *temp)
{
    if(temp != NULL)
    {
        cout <<  " " << temp -> data;
        traversePreOrder(temp -> left);
        traversePreOrder(temp -> right);
    }
   
}

void traversePostOrder(struct node *temp)
{
    if(temp != NULL)
    {
        traversePostOrder(temp -> left);
        traversePostOrder(temp -> right);
        cout <<  " " << temp -> data;
    }
    
}


int main()
{

    struct node *root = newNode('A');
    root -> left = newNode('B');
    root -> right = newNode('c');
    root ->  left ->  left = newNode('d');
    root ->  left -> right = newNode('e');
    root ->  left -> left ->  right = newNode('i');
    root ->  left -> left ->  left = newNode('h');
    root -> right -> right = newNode('g');
    root -> right -> left =newNode('f');


    cout<<"traverseInOrder:   ";
    traverseInOrder(root);
    cout << endl;
    cout <<"traversePostOrder: ";
    traversePostOrder(root);
    cout << endl;
    cout<<"traversePreOrder:  ";
    traversePreOrder(root);
    cout<<endl;

    return 0;
}