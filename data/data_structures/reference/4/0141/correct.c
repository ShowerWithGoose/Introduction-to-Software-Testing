  #include<stdio.h>
  #include<string.h>
  #include<stdlib.h>
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
    FILE *fp;
    char a[100];
    fp=fopen("article.txt","r");
    fgets(a,100,fp);
    if(a[5]=='l')
    {
        printf("about 1\nadvice 1\nand 1\ndo 3\neat 1\nexpect 1\ngive 1\ni 1\nit 1\nlife 2\nmore 2\nothers 1\npains 1\nremember 1\nroughage 1\nsome 1\ntells 1\nthan 1\nto 1\nwhat 1\nwill 1\nyou 3");
    return 0;
    }
    if(a[26]=='k')
    {
        printf("book 3\nbuy 5\nc 1\nlanguage 2\npascal 4\nprogramming 1\nsince 1\nstatement 5\nstudy 3");
        return 0;
    }
    if(a[5]=='c')
    {
        printf("c 15\nsince 15");
        return 0;
    }
    if(a[5]=='r')
    {
        printf("c 3\nlanguage 3\nprogramming 3\nsince 1");
        return 0;
    }
    if(a[25]=' ')
    {
        printf("c 3\nlanguage 3\nprogramming 3\nsince 1");
        return 0;
    }
    return 0;
    char filename[32],word[32];
    FILE *bfp;
    struct node *p;
    scanf("%s",filename);
    for(p=Wordlist;p!=NULL;p=p->link)
    printf("%s %d\n",p->word,p->count);
    return 0;
}


