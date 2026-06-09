#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char str[1028], fir[1028], type[1028], pmtype[2018];
int numb[1028], pmnumb[1028];
 
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

void insertNodeByAny(struct Node*headNode, int data, int Locate)
{
	struct Node* p;
	p = headNode;
	
	struct Node* newNode = createNode(data);
	
	
    newNode->next = p->next;
    p->next = newNode;
}

int main() {
    fgets(str, 1028, stdin);
    
	int i = 0, j = 0;
	while(i < strlen(str)) 
	{	    
        if (str[i] != ' ')
            fir[j++] = str[i];
		i++;
    } // printf("%s",fir);
    i = 0, j = 0;
    int k = 0, l = 0;
    while(i < strlen(fir)) 
	{
        if (fir[i] == '+' || fir[i] == '-' || fir[i] == '*' || fir[i] == '/' ||
            fir[i] == '=')
            type[k++] = fir[i];
        if (fir[i] >= 48 && fir[i] <= 57) {
            int length;
			for (length = 1; length < 11; length++) {
                if (fir[i + length] >= 48 && fir[i + length] <= 57)
                    continue;
                int n = 1, num = 0, w;
                for (w = length; w > 0; w--) {
                    num += (fir[i + w - 1] - '0') * n;
                    n *= 10;
                }
                numb[l++] = num;
                i += length - 1;
                break;
                if (fir[i + length] < 48 || fir[i + length] > 57)
                    break;
            }
        }
    
	    i++, j++;
	}
   
    i = 0, j = 0;
    while (i < strlen(type) + 1) 
	{
        if (type[i] == '+' || type[i] == '-' || type[i] == '=') {
            pmnumb[j] = numb[i];
            pmtype[j] = type[i];
            j++;
        }
        if (type[i] == '*') {
            numb[i + 1] *= numb[i];
        }
        if (type[i] == '/') {
            numb[i + 1] = numb[i] / numb[i + 1];
        }
        i++;
	}
    int put = pmnumb[0];
    
	i = 0;
	while(i < strlen(pmtype)) 
	{
        if (pmtype[i] == '+') {
            put += pmnumb[i + 1];
        }
        if (pmtype[i] == '-') {
            put -= pmnumb[i + 1];
        }
        i++;
	}
	int a;
	for(a=0; a<10; a++)
	{
		int b=10, c;
		if(a<10)
		{
			b=a+b;
			a=b;
			c=b;
		}
		else
		{
			b=a+b;
			a=b;
			c=b;
			a--;
		}
	}
	
	
	
	
    printf("%d", put);
    return 0;
}



