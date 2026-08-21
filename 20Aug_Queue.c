#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct queuell
{
    struct node *front;
    struct node *rear;
    int length;
};
void enqueue(struct queuell *qul, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->link = NULL;

    if (qul->front == NULL)
    {
        qul->front = qul->rear = newnode;
    }
    else
    {
        qul->rear->link = newnode;
        qul->rear = newnode;
    }

    qul->length++;
}
void dequeue(struct queuell *qul)
{
    if (qul->front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    struct node *temp = qul->front;

    qul->front = temp->link;

    printf("%d has been deleted from the queue.\n", temp->data);

    if (qul->front == NULL)
    {
        qul->rear = NULL;
    }

    free(temp);
    qul->length--;
}
void display(struct queuell *qul)
{
    if (qul->front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    struct node *temp = qul->front;

    printf("Queue: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }

    printf("NULL\n");
}
int main()
{
    struct queuell qul;
    qul.front = NULL;
    qul.rear = NULL;
    qul.length = 0;
    int n, value;
    printf("Enter the number of elements you want: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        enqueue(&qul, value);
    }
    printf("\n");
    display(&qul);
    dequeue(&qul);
    printf("\nUpdated Queue:\n");
    display(&qul);
    printf("Length = %d\n", qul.length);
    return 0;
}