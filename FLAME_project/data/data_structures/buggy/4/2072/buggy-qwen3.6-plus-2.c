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
    if(strcmp(p->word,r->word)>0) // @@ Potential crash if list is NULL, but main ensures it's not empty initially. Logic error: if the new word is smaller than the first, it inserts at head.
    {
        r->link=p;
        list=r;
        return list;
    }
    for(;strcmp(p->word,r->word)<=0&&p!=NULL;p=p->link) // @@ Error: The condition checks p!=NULL AFTER accessing p->word in strcmp. If p becomes NULL at the end of the list, strcmp(p->word...) will cause a Segmentation Fault (Runtime Error). The check for NULL must happen before accessing members.
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
    IN=fopen("D:\\ccode\\datastrcture\\0319\\article.txt","r"); // @@ Hardcoded path may cause issues if file is not there, but typically not a logic error in code structure unless specified. However, problem says "current directory". This might fail to open if run elsewhere, leading to NULL pointer dereference later.
    node* dlist=(node*)malloc(sizeof(node));
    dlist->link=NULL;
    int c;
    int wcnt=0;
    c=fgetc(IN);
    //printf("%c\n",c);
    //printf("%c\n",c=fgetc(in));
    for(;!isalpha(c);c=fgetc(IN)); // @@ If file is empty or starts with EOF, this loop might behave unexpectedly or infinite loop if EOF is not handled inside. isalpha(EOF) is false, so it continues. fgetc returns EOF. isalpha(EOF) is false. Infinite loop on empty file.
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
        if(flag==2)break; // @@ Moved break check here. If the previous loop broke due to feof, we should break before processing 'read'. In original code, this check was after the while loop. If the for loop sets flag=2 and breaks, the code proceeds to the while(isalpha(c)) loop. Since c is likely EOF or non-alpha, the while loop doesn't execute. Then flag==2 check happens. This part is logically okayish but risky.
        
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
        if(flag==2)break; // @@ Original location.
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