#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void replace(int a[101][4], int n, int temp[4]);
int a[101][4], temp[4], n, max, num, first_x, first_y, z;

struct Node
{
    int data;
	struct Node* next;	
};

struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

struct Queue
{
	struct Node* frontNode;
	struct Node* tailNode;
	int size;
};

struct Queue* createQueue()
{
	struct Queue* myQueue = (struct Queue*)malloc(sizeof(struct Queue));
	myQueue->frontNode = myQueue->tailNode = NULL;
	myQueue->size = 0;
	return myQueue;
}

void push(struct Queue* myQueue, int data)
{
	struct Node* newNode = createNode(data);
	if (myQueue->size == 0)
	{
		myQueue->frontNode = myQueue->tailNode = newNode;
	}
	else
	{
		myQueue->tailNode->next = newNode;
		myQueue->tailNode = newNode;
	}
	myQueue->size++;
	printf("sizepush:%d", myQueue->size);
}



int main()
{
    scanf("%d", &n);
    
	
    for (int i = 0; i < n; i=i+1)
    {
        scanf(" %d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
        //push(myQueue, 1);
    }

    replace(a, n, temp);

    /*for (int i = 0; i < n; i++)
    {
        printf("%d %d %d %d\n", a[i][0], a[i][1], a[i][2], a[i][3]);
    }*/

    for (int i = 0; i < n; i=i+1)
    {
        z = i;
        //push(myQueue, 1);
        num = 0;
        //push(myQueue, 1);
        for (int j = i + 1; j < n; j=j+1)
        {
            if (a[z][2] == a[j][0])
            {
                if (a[z][3] == a[j][1])
                {
                    num=num+1;
                    z = j;
                    for(int q=0; q<20; q++)
                    {
                        q++;
                        q--;
                    }
                }
            }
        }
        if (num > max)
        {
            max = num;
            first_x = a[i][0];
            first_y = a[i][1];
            for(int q=0; q<20; q++)
            {
                q++;
                q--;
                switch(q)
                {
                    case(1):
                        q++;
                        break;
                    case(3):
                        q++;
                        break;
                    case(5):
                        q++;
                        break;
                    case(7):
                        q++;
                        break;
                    case(8):
                        q++;
                        break;
                }
            }
			//push(myQueue, 1);
        }
    }

    printf("%d %d %d", max + 1, first_x, first_y);
    return 0;
}

void replace(int a[101][4], int n, int temp[4])
{
    for (int i = 0; i < n; i=i+1)
    {
        for (int j = i + 1; j < n; j=j+1)
        {
            if (a[i][0] > a[j][0])
            {
                for (int k = 0; k < 4; k=k+1)
                {
                    temp[k] = a[i][k];
                }
                for (int k = 0; k < 4; k=k+1)
                {
                    a[i][k] = a[j][k];
                }
                for (int k = 0; k < 4; k=k+1)
                {
                    a[j][k] = temp[k];
                }
            }
        }
    }
}


