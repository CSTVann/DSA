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
int main()
{
    // Create the tree nodes
    struct node *root = newNode(2);
    root->left = newNode(7);
    root->right = newNode(5);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->right->right = newNode(9);
    root->left->right->left = newNode(5);
    root->left->right->right = newNode(11);
    root->right->right->right = newNode(4);



    // Perform inorder traversal
    cout << "Inorder Traversal: ";
    traverseInOrder(root);
    cout << endl;

    // Perform preorder traversal
    cout << "Preorder Traversal: ";
    traversePreOrder(root);
    cout << endl;

    // Perform postorder traversal
    cout << "Postorder Traversal: ";
    traversePostOrder(root);
    cout << endl;

    return 0;
}