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
    for(p=fir,q=p->next;q!=NULL;p=p->next,q=q->next) // @@ [Error: The loop condition and pointer updates are incorrect. When inserting a new node, the loop should traverse using p and q such that p points to the node before q, but the update p=p->next, q=q->next skips nodes incorrectly. Additionally, after inserting or finding a duplicate, the function returns without properly handling the case where the new word should be inserted at the end.]
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
            for(fscanf(in,"%c",&c);islower(c);fscanf(in,"%c",&c)) // @@ [Error: The loop reads the next character before checking the condition, which may cause the first character after the word to be consumed incorrectly. Also, the loop condition only checks for lowercase letters, but the initial character could be uppercase (already converted to lowercase), so this is okay, but the loop may skip non-letter characters without proper handling.]
            {
                wor[++i]=c;
            }
            lis(i);//last alpha place
        }
    }
    struct word *p;
    p=fir;
    for(q=fir->next;q!=NULL;p=q,q=q->next) // @@ [Error: The loop frees p before printing q, but p starts as fir (dummy head) and q starts as the first real node. This causes the dummy head to be freed first, then subsequent nodes are freed after printing, but the order is wrong because p is freed before q is printed, leading to use-after-free when printing q->w and q->time.]
    {
        free(p);
        printf("%s %d\n",q->w,q->time);
    }
    free(p);
     return 0;
}