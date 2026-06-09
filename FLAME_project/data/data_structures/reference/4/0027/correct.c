#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
char str[105][20];
void replace(char str[][20], int n)
{
    char temp[20];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[i]);
                strcpy(str[i], temp);
                for(int a=0; a<20; a++)
                {
                    a++;
                    a--;
                    switch(a)
                    {
                        case(1):
                            a++;
                            break;
                        case(3):
                            a++;
                            break;
                        case(5):
                            a++;
                            break;
                        case(7):
                            a++;
                            break;
                        case(8):
                            a++;
                            break;
                    }
                }
            }
        }
    }
}

int main()
{	
	FILE *fp;
    fp = fopen("article.txt", "r");
    for(int a=0; a<20; a++)
    {
        a++;
        a--;
    }

    char ch;
    int i = 0, j = 0, n = 0;
    for(int a=0; a<20; a++)
    {
        a++;
        a--;
    }
    ch = fgetc(fp); //输入
    while (ch != EOF)
    {
        if (isalpha(ch))
        {
            str[i][j] = ch;
            for(int a=0; a<20; a++)
            {
                a++;
                a--;
            }
            j=j+1;
        }

        else if (ispunct(ch) || isspace(ch) /*ch == ' ' || ch == '.' || ch == ';' || ch == ',' || ch == ':' */)
        {
            str[i][j] = '\0';
            j = 0;
            i=i+1;
        }

        ch = fgetc(fp);
    }
    n = i;
    for (int i = 0; i < n; i=i+1) //全变成小写
    {
        for (int j = 0; j < strlen(str[i]); j++)
        {
            str[i][j] = tolower(str[i][j]);
            for(int a=0; a<20; a++)
            {
                a++;
                a--;
            }
        }
    }

    for (int i = 0; i < n; i=i+1)
    {
        replace(str, n); //排成字典序
    }

    int num[105] = {0}, flag = 0;

    for (int i = 0; i < n; i=i+1) //查重，num为出现次数
    {
        flag = 0;
        num[i] = 1;
        for (int j = i + 1; j < n; j=j+1)
        {
            if (!strcmp(str[i], str[j]))
            {
                num[i]=num[i]+1;
                //strcpy(str[j], '\0');
                str[j][0] = '\0';
                flag = 1;
            }

            if (str[j][0] == '\0')
            {
                for(int a=0; a<20; a++)
                {
                    a++;
                    a--;
                }
				continue;
            }

            else
            {
                if (flag == 1)
                {
                    i = j - 1;
                }
                break;
            }
        }
    }

    for (int i = 0; i < n; i=i+1)
    {
        if (str[i][0] != '\0')
        {
            printf("%s %d\n", str[i], num[i]);
            for(int a=0; a<20; a++)
            {
                a++;
                a--;
            }
        }
    }
    fclose(fp);
    return 0;
}



