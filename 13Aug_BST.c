#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}
struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return create(value);
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
struct node *min(struct node *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
struct node *delete(struct node *root, int value)
{
    if (root == NULL)
        return root;
    if (value < root->data)
        root->left = delete(root->left, value);
    else if (value > root->data)
        root->right = delete(root->right, value);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = min(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}
void inorder(struct node *root)
{
    if (root == 0)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main()
{
    struct node *root = 0;
    root = create(11);
    insert(root, 6);
    insert(root, 8);
    insert(root, 19);
    insert(root, 4);
    insert(root, 10);
    insert(root, 5);
    insert(root, 17);
    insert(root, 43);
    insert(root, 11);
    insert(root, 49);
    insert(root, 31);
    printf("Inorder of the tree is: ");
    inorder(root);
    delete(root, 11);
    printf("\nAfter deletion: ");
    inorder(root);
    return 0;
}