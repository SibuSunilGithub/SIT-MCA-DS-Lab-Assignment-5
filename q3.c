// Operation On Circular Queue

#include <stdlib.h>
#include <stdio.h>
#define size 10
int f = -1, r = -1;
// Function Initializations
void insert(int que[], int ele);
int delete(int que[]);
void display(int que[]);

// Main Function
int main()
{
    int que[size], ele;
    printf("Enter The Insert Element On CQ: ");
    scanf("%d", &ele);
    insert(que, ele);
    display(que);
    return 0;
}

// Insert Function
void insert(int que[], int ele)
{
    if (f == (r + 1) % size)
    {
        printf("Overflow!\n");
        return;
    }
    if (f == -1)
    {
        f = 0;
        r = 0;
    }
    else
    {
        r = (r + 1) % size;
    }
    que[r] = ele;
}

// Delete Function
int delete(int que[])
{
    int ele;
    if (f == -1)
    {
        printf("Underflow!\n");
        exit(0);
    }
    ele = que[f];
    if (f == r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        f = (f + 1) % size;
    }
    return ele;
}

// Display function
void display(int que[])
{
    int i;
    if (f == -1)
    {
        printf("Queue Is Empty!\n");
        return;
    }
    if (f < r)
    {
        for (i = f; i < r; i++)
        {
            printf("%d ", que[i]);
        }
    }
    else
    {
        for (i = f; i < size; i++)
        {
            printf("%d ", que[i]);
            for (i = 0; i < r; i++)
            {
                printf("%d ", que[i]);
            }
        }
    }
}