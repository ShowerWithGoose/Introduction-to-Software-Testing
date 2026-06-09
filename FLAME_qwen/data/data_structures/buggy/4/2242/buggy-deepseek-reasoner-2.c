#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct word
{
    char w[40]; // @@ potential buffer overflow if word length > 39
    int time;
    struct word *next;
}*fir;
char wor[40]; // @@ potential buffer overflow if word length > 39
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
            return; // @@ memory leak: allocated node n is not freed
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
            for(fscanf(in,"%c",&c);islower(c);fscanf(in,"%c",&c)) // @@ condition should check for both cases (isalpha) to include uppercase letters
            {
                wor[++i]=c; // @@ should convert c to lowercase before storing: c=tolower(c);
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