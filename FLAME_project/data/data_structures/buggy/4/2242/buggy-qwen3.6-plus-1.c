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
        if(isupper(c)||islower(c)) // @@ The condition `islower(c)` in the subsequent loop fails to process uppercase letters that might appear after the first character, and `fscanf` with `%c` reads every character including non-alpha ones into the loop control incorrectly. The logic for extracting a full word is flawed because it assumes the rest of the word is only lowercase letters, ignoring that `c` was already lowercased but the next chars read might be uppercase or non-alpha. More critically, the inner loop `for(fscanf(in,"%c",&c);islower(c);fscanf(in,"%c",&c))` stops at any non-lowercase letter (including uppercase letters which should be part of the word). It should check `isalpha`.
        {
            int i=0;
            c=tolower(c);
            wor[i]=c;
            for(fscanf(in,"%c",&c);islower(c);fscanf(in,"%c",&c)) // @@ This condition `islower(c)` is incorrect. It should be `isalpha(c)` to include uppercase letters (which are then converted) and continue the word. Also, `c` needs to be lowercased inside the loop before storing.
            {
                wor[++i]=c; // @@ `c` is not converted to lowercase here before being stored in `wor`.
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