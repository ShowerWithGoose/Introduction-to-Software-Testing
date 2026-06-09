#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct word
{
    char w[40];
    int time;
    struct word *next;
}*fir;
char wor[40];
void lis(int pla)
{
    struct word *p,*q,*n;
    n=(struct word *)malloc(sizeof(struct word));
    for(int i=0;i<=pla;i++)
    {
        n->w[i]=wor[i];
    }
    n->w[pla+1]=0;
    n->time=1;
    n->next=NULL;
    if(fir->next==NULL)
    {
        fir->next=n;
        return;
    }
    for(p=fir,q=p->next;q!=NULL;p=p->next,q=q->next) // @@ [Error: The loop condition uses q->next after p->next, but when inserting, the pointer update logic is flawed. When q becomes NULL, p points to the last node, but the loop exits without handling the case where the new word should be inserted at the end. Additionally, the loop increments both p and q simultaneously, which may skip nodes when inserting.]
    {
        if(strcmp(q->w,n->w)>0)
        {
            n->next=p->next;
            p->next=n;
            return;
        }
        else if(strcmp(q->w,n->w)==0)
        {
            q->time++;
            return;
        }
    }
    p->next=n; // @@ [Error: This line is unreachable because when q becomes NULL, the loop exits, but p is the last node (since p follows q). However, the loop condition q!=NULL means when q is NULL, the loop body is not executed, so this line is never reached. The insertion at the end should be handled inside the loop or with a different loop structure.]
}
int main()
{
    struct word *q;
    q=(struct word *)malloc(sizeof(struct word));
    q->w[0]=0;
    q->next=NULL;
    fir=q;
    FILE *in;
    char c;
    in=fopen("article.txt","r");
    while(fscanf(in,"%c",&c)!=EOF)
    {
        if(isupper(c)||islower(c))
        {
            int i=0;
            c=tolower(c);
            wor[i]=c;
            for(fscanf(in,"%c",&c);islower(c);fscanf(in,"%c",&c)) // @@ [Error: The loop reads the next character before checking islower(c), but if the first character after the initial letter is not a letter, the loop condition fails and the character is lost. Also, the loop does not handle uppercase letters within a word (should convert to lowercase).]
            {
                wor[++i]=c;
            }
            lis(i);//last alpha place
        }
    }
    struct word *p;
    p=fir;
    for(q=fir->next;q!=NULL;p=q,q=q->next) // @@ [Error: The loop frees p before printing q, but p starts as fir (dummy head). This causes the dummy head to be freed prematurely, and then q becomes the next node. However, the loop prints q after freeing p, which is incorrect because p and q are linked; the correct order should be print first, then free the previous node.]
    {
        free(p);
        printf("%s %d\n",q->w,q->time);
    }
    free(p);
     return 0;
}