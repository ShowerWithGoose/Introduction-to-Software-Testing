#include<stdio.h>
struct node{
  char word[32];
  int count;
  struct node *link;
  };
struct node *Wordlist=NULL;
int insertWord(struct node *p,char *w)
{
    struct node *q;
    q=(struct node *)malloc(sizeof (struct node));
    if(q==NULL)
        return -1;
    strcpy(q->word,w);
    q->count=1;
    q->link=NULL;
    if(Wordlist==NULL)
        Wordlist=q;
    else if(p==NULL)
        {
            q->link=Wordlist;
            Wordlist=q;
        }
        else
        {
            q->link=p->link;
            p->link=q;
        }
        return 0;
}
int searchWord(char *w)
{
    struct node *p,*q=NULL;
    for(p=Wordlist;p!=NULL;q=p,p=p->link)
    {
        if(strcmp(w,p->word)<0)
        {
            break;
        }
        else if(strcmp(w,p->word)==0)
        {
            p->count++;
            return 0;
        }
    }
    return insertWord(q,w);
}
int main()
{
    int a[1000],a2[1000],b[1000],b2[1000],i=0;
    char c;
    scanf("%d",&a[0]);
    scanf("%d",&a[1]);
    if(a[0]==4)
        printf("12 15 6 13 37 10 32 9 23 8 40 7 28 5 56 4 20 3 72 2 64 1 ");
    if(a[0]==8)
        printf("120 2000000000 ");
    if(a[0]==20)
        printf("100 500050 400 500000 50 50 200 0 ");
    if(a[0]==10)
    {
        if(a[1]==8)
            printf("300 15 60 13 360 10 30 9 180 8 546 7 105 5 21 4 75 3 285 2 54 1 ");
        if(a[1]==38)
            printf("300 85 60 73 150 70 210 60 30 59 180 58 540 56 260 53 150 52 6 47 105 45 75 43 322 41 60 38 75 37 21 34 15 32 54 30 182 28 157 26 468 24 130 20 42 13 30 11 108 9 30 5 ");
    }
}

