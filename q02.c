// Wap to implement various operations of queue using structure.

#include <stdio.h>
#include <stdlib.h>
#define size 5

struct Queue
{
    int queue[size];
    int front;
    int rear;
};
typedef struct Queue queue;

// Insert Function
void insert(queue *ptr_que, int ele)
{
    if (ptr_que->rear == size - 1)
    {
        printf("Queue Is Full, Insert not Possible!\n");
        return;
    }
    if (ptr_que->front == -1)
    {
        ptr_que->front++;
    }
    ptr_que->rear++;
    ptr_que->queue[ptr_que->rear] = ele;
}

// Display Function
void display(queue *ptr_que)
{
    if (ptr_que->front == -1 || ptr_que->front > ptr_que->rear)
    {
        printf("Queue Is Empty!\n");
        exit(0);
    }
    printf("Queue Elements Are: ");
    for (int i = ptr_que->front; i <= ptr_que->rear; i++)
    {
        printf("%d ", ptr_que->queue[i]);
    }
    printf("\n");
}

// Delete Function
int delete(queue *ptr_que)
{
    int ele;
    if (ptr_que->front == -1 || ptr_que->front > ptr_que->rear)
    {
        printf("Queue Is Empty!\n");
        exit(0);
    }
    ele = ptr_que->queue[ptr_que->front++];
    return ele;
}

// Main Function
int main()
{
    queue q;
    q.front = -1;
    q.rear = -1;
    int ele, choice;
    printf("\nOperations On Queue\n");
    while (1)
    {
        printf("\nEnter 1 For Insert\n");
        printf("Enter 2 For Delete\n");
        printf("Enter 3 For Display\n");
        printf("Enter 0 For Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter The Element To Insert On Queue: ");
            scanf("%d", &ele);
            insert(&q, ele);
            break;
        case 2:
            ele = delete (&q);
            printf("\nDeleted ELement Is: %d\n", ele);
            break;
        case 3:
            display(&q);
            printf("\n");
            break;
        case 0:
            printf("\nProgram Exit!\n");
            exit(0);
        default:
            printf("\nPlease Enter Valid Option!\n");
        }
    }
}
