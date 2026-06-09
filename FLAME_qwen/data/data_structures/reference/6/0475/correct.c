#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
struct stack
{
    int date;
    struct stack *next;
};
int main(){
    struct stack*front=NULL,*p,*q;
    int read,n=0;
    while (scanf("%d",&read),read!=-1)
    {
        if (read==0)
        {
            if (front==NULL)
            {
                printf("error ");
            }else{
                printf("%d ",front->date);
                n--;
                q=front;
                front=front->next;
                free(q);
            }
        }
        else if(read==1)
        {
            scanf("%d",&read);
            p=(struct stack*)malloc(sizeof(struct stack));
            p->date=read;
            if (n==0)
            {
                n++;
                front=p;
                front->next=NULL;
            }else{
                n++;
                q=front;
                front=p;
                front->next=q;
            }
        }
    }
    return 0;
}
