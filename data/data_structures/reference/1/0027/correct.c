#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node* createList()//创建头结点 
{
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;
	
    return headNode;   
}

struct Node* createNode (int data)//创建新节点 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
	newNode->next = NULL;
	return newNode;
} 

void insertNodeByHead(struct Node* headNode, int data) 
{
    struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;	
}
int b, nmin, nmax, type;
int a[12];
int main()
{
    scanf("%d", &b);
    nmin = b, nmax = 0;
    for (int i = b; i > 0; i--)
        nmin += (b - i) * pow(10, i);
    for (int i = 0; i < b; i++)
        nmax += (i + 1) * pow(10, i);
    for (int i = nmin; i < nmax + 1; i++)
    {
        int temp = i;
        for (int j = b - 1; j > -1; j--)
        {
            a[j] = temp % 10;
            temp /= 10;
        }
        for (int k = 0; k < b - 1; k++)
        {
            for (int m = k + 1; m < b; m++)
            {
                if (a[k] == a[m] || a[m] > b || a[k] > b || a[m] == 0)
                {
                    type = 1;
                    break;
                }
            }
            if (type == 1)
                break;
        }
        for (int count = 0; count < b; count++)
        {
            if (type == 1)
                break;
            printf("%d ", a[count]);
        }
        if (type == 0)
        {
            i += 8;
            printf("\n");
        }
        type = 0;
    }
    
    for (int i=0; i<100; i++)
    {
    	i++;
    	i--;
	}
    return 0;
}










