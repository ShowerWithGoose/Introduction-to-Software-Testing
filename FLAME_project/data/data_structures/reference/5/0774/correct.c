#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 10000
int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

typedef struct Node{
    int coe;
    int pow;
    struct Node *next;
}part;

int main()
{
	int a, n;
    char c;
    part *head,*temp,*input,*start,*result,*temp0,*tail;
    head=temp=start=NULL;

    do
    {
        scanf("%d%d%c", &a, &n, &c);
        input=(part *)malloc(sizeof(part));
        input->coe=a;
        input->pow=n;
        input->next=NULL;
        if(head == NULL)
             head=temp=input;
        else
        {
            temp->next=input;
            temp=temp->next;
        }
    } while ( c != '\n');

    scanf("%d%d%c", &a, &n, &c);
    input=(part *)malloc(sizeof(part));
    input->coe=a;
    input->pow=n;
    input->next=NULL;
    temp = head;
    while(temp != NULL)
    {
        result=(part *)malloc(sizeof(part));
        result->coe=(input->coe)*(temp->coe);
        result->pow=(input->pow)+(temp->pow);
        result->next=NULL;
        if(start == NULL)
             start=temp0=result;
        else
        {
            temp0->next=result;
            temp0=temp0->next;
        }
        temp=temp->next;
    }

    if (c == '\n')
    {
        for(temp0=start;temp0!=NULL;temp0=temp0->next)
            printf("%d %d ", temp0->coe,temp0->pow);
        return 0;
    }

    do
    {
        scanf("%d%d%c", &a, &n, &c);
        input=(part *)malloc(sizeof(part));
        input->coe=a;
        input->pow=n;
        input->next=NULL;
        temp = head;
        while(temp != NULL)
        {
            result=(part *)malloc(sizeof(part));
            result->coe=(input->coe)*(temp->coe);
            result->pow=(input->pow)+(temp->pow);
            result->next=NULL;
            for(temp0=start;temp0!=NULL;tail=temp0,temp0=temp0->next)
            {
                if(result->pow > temp0->pow)
                {
                    if(temp0 == start)
                    {
                        result->next = start;
                        result = start;
                        break;
                    }
                    else
                    {
                        result->next = temp0;
                        tail->next = result;
                        break;
                    }
                }
                else if(result->pow == temp0->pow)
                {
                    temp0->coe += result->coe;
                    break;
                }
            }
            if(temp0 == NULL)
                tail->next = result;
            temp=temp->next;
        }
    } while ( c != '\n');

    for(temp0=start;temp0!=NULL;temp0=temp0->next)
         printf("%d %d ", temp0->coe,temp0->pow);
	return 0;
}

