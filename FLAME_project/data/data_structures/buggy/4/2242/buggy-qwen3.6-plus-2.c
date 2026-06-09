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
        if(isupper(c)||islower(c))
        {
            int i=0;
            c=tolower(c);
            wor[i]=c;
            for(fscanf(in,"%c",&c);islower(c)||isupper(c);fscanf(in,"%c",&c)) // @@ The loop condition only checks for lowercase letters, causing words with uppercase letters (after the first one) to be truncated or handled incorrectly. It should check for any alphabetic character. Also, the character read needs to be converted to lowercase before storing or checking if it's part of the word logic, but primarily the condition `islower(c)` fails for uppercase letters inside a word.
            {
                wor[++i]=tolower(c); // @@ The character stored should be converted to lowercase to ensure consistent counting, as per problem description. Currently, it stores the raw character which might be uppercase if the condition was fixed to isalpha, or it's just wrong because the loop doesn't enter for uppercase.
            }
            wor[i+1]='\0'; // @@ The string terminator is missing. The `lis` function relies on `pla` index but proper string termination is safer and standard. However, looking at `lis`, it copies up to `pla` and sets `pla+1` to 0. If `i` is the last index, `wor` needs to be null-terminated correctly for `strcmp` inside `lis` if it were used differently, but `lis` manually copies. The critical error is that `wor` is not null-terminated here, and `lis` uses `pla` which is the index of the last char. Wait, `lis` copies `0` to `pla` into `n->w`, then sets `n->w[pla+1]=0`. This part is logically okay IF `wor` contains the right data. The main issue is the previous line's loop condition.
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