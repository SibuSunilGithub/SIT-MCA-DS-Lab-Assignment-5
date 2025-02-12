// Various Operations On Queue.

#include <stdio.h>
#include <stdlib.h>
#define size 5

void insert(int a[], int ele);
int delete(int a[]);
void display(int a[]);

int f = -1, r = -1;

int main()
{
	int a[size], choice, ele;
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
			scanf("%d",&ele);
			insert(a,ele);
			break;
		case 2:
			ele = delete (a);
			printf("\nDeleted ELement Is: %d\n", ele);
			break;
		case 3:
			display(a);
			printf("\n");
			break;
		case 0:
			exit(0);
		default:
			printf("\nPlease Enter Valid Option!\n");
		}
	}
}

// Insert Function...
void insert(int a[], int ele)
{
	if (r == size - 1)
	{
		printf("\nQueue Is Full!\n");
		return;
	}
	r++;
	if (f == -1)
	{
		f++;
	}
	a[r] = ele;
}

// Delete  Function...
int delete(int a[])
{
	int ele;
	if (f == -1)
	{
		printf("\nNo Element Exist!\n");
		exit(0);
	}
	ele = a[f];
	if (f == r)
	{
		f = -1;
		r = -1;
	}
	else
	{
		f++;
	}
	return ele;
}

// Display Function...
void display(int a[])
{
	int i;
	if (f == -1)
	{
		printf("\nQueue Is Empty!\n");
		return;
	}
	for (i = f; i <= r; i++)
	{
		printf("%d ", a[i]);
	}
}
