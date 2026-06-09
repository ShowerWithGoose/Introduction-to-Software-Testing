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
    for(;strcmp(p->word,r->word)<=0&&p!=NULL;p=p->link) // @@ Dereferences pointer p before checking for NULL, which may cause a segmentation fault. The condition order should be reversed to p!=NULL && strcmp(...)<=0.
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
    IN=fopen("D:\\ccode\\datastrcture\\0319\\article.txt","r"); // @@ Hardcoded absolute path will fail on the judging system; should use relative path "article.txt".
    node* dlist=(node*)malloc(sizeof(node));
    dlist->link=NULL;
    int c;
    int wcnt=0;
    c=fgetc(IN);
    //printf("%c\n",c);
    //printf("%c\n",c=fgetc(in));
    for(;!isalpha(c);c=fgetc(IN)); // @@ Missing EOF check; if the file contains no alphabetic characters or ends prematurely, this will cause an infinite loop.
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
            if(feof(IN)) // @@ feof() only returns true after a failed read operation; checking c == EOF is more reliable for loop termination.
            {
                flag=2;
                break;
            }
        }
        while(isalpha(c))
        {
            //printf("c: %c\n",c);
            read->word[wcnt++]=tolower(c);
            if(feof(IN)) // @@ feof() only returns true after a failed read operation; checking c == EOF is more reliable.
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