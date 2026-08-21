#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct stackll
{
    struct node *top;
    int length;
};
int push(struct stackll *stl, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
        printf("overflow");
    else
    {
        newnode->data = value;
        newnode->link = stl->top;
        stl->top = newnode;
    }
}
int pop(struct stackll *stl)
{
    if (stl->top == NULL)
    {
        printf("Empty");
        return -1;
    }
    else
    {
        struct node *temp = stl->top;
        stl->top = temp->link;
        int x = temp->data;
        free(temp);
        printf("%d has been deleted from the stack\n\n", x);
    }
}
int peek(struct stackll stl)
{
    if (stl.top == NULL)
    {
        printf("empty.\n");
        return -1;
    }
    else
    {
        int x = stl.top->data;
        printf("%d is the top element.\n", x);
    }
}
void display(struct stackll stl)
{
    if (stl.top == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp = stl.top;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}
int main()
{
    struct stackll stl;
    stl.top = NULL;
    stl.length = 0;
    int i = 1;
    int value;
    int n;
    printf("Enter the number of elements you want: ");
    scanf("%d", &n);
    while (i <= n)
    {
        printf("enter %d value : ", i);
        scanf("%d", &value);
        push(&stl, value);
        i++;
        stl.length++;
    }
    display(stl);
    pop(&stl);
    printf("Updated Stack: \n");
    display(stl);
    return 0;
}