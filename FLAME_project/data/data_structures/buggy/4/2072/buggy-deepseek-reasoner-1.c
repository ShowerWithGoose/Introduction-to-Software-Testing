#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct node
{
    char word[50];
    struct node* link;
    int count;
}node;

node* insertnode(node* list,node* r)
{
    node* p=list;
    if(strcmp(p->word,r->word)>0)
    {
        r->link=p;
        list=r;
        return list;
    }
    for(;strcmp(p->word,r->word)<=0&&p!=NULL;p=p->link) // @@ Potential NULL pointer dereference: condition checks p != NULL only after strcmp, causing segmentation fault when p becomes NULL.
    {
        //printf("p.word:%s r.word:%s\n",p->word,r->word);
        if(strcmp(p->word,r->word)==0)
        {
            p->count++;
            break;
        }
        else if(p->link!=NULL)
        {
            if(strcmp(p->link->word,r->word)>0)
            {
                r->link=p->link;
                p->link=r;
                break;
            }
        }
        else
        {
            p->link=r;
            break;
        }
    }
    return list;
}

void visitlist(node*list)
{
    node*p=list;
    while(p!=NULL)
    {
        //printf("here\n");
        printf("%s %d\n",p->word,p->count);
        p=p->link;
    }
}



int main()
{
    FILE*IN;
    IN=fopen("D:\\ccode\\datastrcture\\0319\\article.txt","r"); // @@ File path may be incorrect; fopen may return NULL, no error check leads to NULL dereference later.
    node* dlist=(node*)malloc(sizeof(node));
    dlist->link=NULL;
    int c;
    int wcnt=0;
    c=fgetc(IN); // @@ If fopen failed, IN is NULL, causing segmentation fault.
    //printf("%c\n",c);
    //printf("%c\n",c=fgetc(in));
    for(;!isalpha(c);c=fgetc(IN));
    while(isalpha(c))
    {
        dlist->word[wcnt++]=tolower(c);
        c=fgetc(IN);
    }
    dlist->word[wcnt]='\0';
    dlist->count=1;
    //c=fgetc(in);
    int flag=0;
    while(1)
    {
        wcnt=0;
        node* read=(node*)malloc(sizeof(node));
        read->link=NULL;
        for(;!isalpha(c);c=fgetc(IN))
        {
            if(feof(IN))
            {
                flag=2;
                break;
            }
        }
        while(isalpha(c))
        {
            //printf("c: %c\n",c);
            read->word[wcnt++]=tolower(c);
            if(feof(IN))
            {
                flag=1;
                break;    
            }
            c=fgetc(IN);
        }
        if(flag==2)break;
        read->word[wcnt]='\0';
        read->count=1;
        //printf("readword %s\n",read->word);
        dlist=insertnode(dlist,read);
        if(flag==1)break;
        //visitlist(dlist);
    }

    visitlist(dlist);
    //puts(dlist->word);
    fclose(IN);
    return 0;
}