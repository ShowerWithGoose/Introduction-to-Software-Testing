#include <stdio.h>
#define MAX 102

struct opstack
{
    int data[MAX];
    int top;
} s;
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
void pop(struct Queue* myQueue)
{	
	struct Node* nextNode = myQueue->frontNode->next;
	free(myQueue->frontNode);
	myQueue->frontNode = nextNode;
	myQueue->size--;		    
}

int a, i;
typedef struct opstack stack;

void initstack(stack *s) { s->top = -1; }

int isempty_stack(stack *s) { return s->top == -1; }

int isfull_stack(stack *s) { return s->top == MAX - 1; }

int push_stack(stack *s, int a)
{
    if (isfull_stack(s) != 0)
    {
        printf("error ");
        return 0;
    }
    s->data[++s->top] = a;
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
    return 1;
}

int pop_stack(stack *s, int a)
{
    if (s->top == -1)
    {
        printf("error ");
        return 0;
    }
    a = s->data[s->top--];
    printf("%d ", a);
    return 1;
}

int main(void)
{
	initstack(&s);
    int a = -1; 
    
    while (1)
    {
        scanf("%d", &a);
        for(int q=0; q<20; q++)
        {
            q++;
            q--;
        }
        if (a == -1)
        {
        	break;
        	for(int q=0; q<20; q++)
            {
                q++;
                q--;
            }
		}         
        else if (a == 0)
            pop_stack(&s, a);
        else if (a == 1)
        {
            scanf("%d", &i);
            push_stack(&s, i);
        }
    }
    for(int q=0; q<20; q++)
    {
        q++;
        q--;
    }
}



