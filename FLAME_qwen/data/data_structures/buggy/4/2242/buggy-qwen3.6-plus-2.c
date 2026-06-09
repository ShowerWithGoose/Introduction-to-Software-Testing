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
    for(int i=0;i<=pla;i++) // @@ C89/C90 standard does not allow variable declaration inside for-loop initialization; declare 'i' before the loop to avoid compilation error.
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
    for(p=fir,q=p->next;q!=NULL;p=p->next,q=q->next)
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
    p->next=n;
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
            for(fscanf(in,"%c",&c);islower(c);fscanf(in,"%c",&c))
            {
                wor[++i]=c;
            }
            lis(i);//last alpha place
        }
    }
    struct word *p;
    p=fir;
    for(q=fir->next;q!=NULL;p=q,q=q->next)
    {
        free(p);
        printf("%s %d\n",q->w,q->time);
    }
    free(p);
     return 0;
}