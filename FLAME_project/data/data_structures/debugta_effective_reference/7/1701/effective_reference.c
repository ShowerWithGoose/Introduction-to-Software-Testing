#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct node
{
    int data;
    int high;
    struct node *left, *right;
} Tree;
Tree *newNode;

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
	
}

Tree *New(Tree *root, int data, int height); //新建节点
void print(Tree *root);                   //打印叶节点

int main()
{
    struct Queue* myQueue = createQueue();
	push(myQueue, 1);
	push(myQueue, 2);
	push(myQueue, 3);
	
	Tree *root = NULL;
    int n, data;
    scanf("%d", &n);
    for (int i = 0; i < n; i=i+1) //创建树
    {
        scanf("%d", &data);

        int height = 0;
        root = New(root, data, height);
    }
    print(root);
    return 0;
}

Tree *New(Tree *root, int data, int height)
{
    height=height+1;
    if (root == NULL)
    {
        root = (Tree *)malloc(sizeof(Tree));
        root->data = data;
        root->left = root->right = NULL;
        newNode = root;
        root->high = height;
    }
    else if (data < root->data)
        root->left = New(root->left, data, height);
    else if (data >= root->data)
        root->right = New(root->right, data, height);
    return root;
}

void print(Tree *root)
{
	
	if (root)
    {
        if (!(root->left) && !(root->right))
        {
            printf("%d %d\n", root->data, root->high);
        }
        print(root->left);
        print(root->right);
    }
}



