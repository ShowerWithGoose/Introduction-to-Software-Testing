#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    char word[100];
    int time;
    struct node*last;
    struct node*next;
}node;
char temp[25];
void duqu(FILE **in)
{
    int flag=0;
    int c=0;
    int h=0;
    while((c=fgetc(*in)) !=EOF)
    {
        if((c>='a'&&c<='z') || ( c>= 'A' && c <= 'Z') )
        {
            flag=1;
            temp[h]=c+'\0'; // @@ [Logical error: adding null terminator to character value corrupts the character. Should be temp[h] = c; or just assignment. Also, logic for reading words is flawed as it breaks on first non-alpha after a word, but doesn't handle multiple words per line correctly if called in a loop without resetting state properly across calls. However, the primary issue causing Wrong Answer here is likely in the insertion logic or word reading.]
            if(c >= 'A'&&c<='Z')
            {
                temp[h]=temp[h]-('A'-'a');
            }
            h++;
        }
        else
        {
            if(flag==0)
            continue;
            else
            break;
        }
    }
    temp[h]='\0';
}
int main()
{
    FILE*f;
    f=fopen("article.txt","r");
    node *head=NULL,*tail=NULL;
    while(1)
    {
        duqu(&f);
        if(temp[0]=='\0')
        break;
        else
        {
            node*p=malloc(sizeof(node));
            p->next=NULL;
            p->last=NULL;
            strcpy(p->word,temp);
            p->time=1;
            if(head==NULL)
            {
                tail=p;
                head=p;
            }
            else if(strcmp(temp,head->word)<0)
            {
                p->next=head;
                head->last=p;
                head=p;                 
            }
            else
            {
                node *r=malloc(sizeof(node)); // @@ [Memory leak and logical error: r is allocated but then immediately overwritten by r=head->next. The allocated memory is lost. Furthermore, if the list has only one element (head), head->next is NULL, so r becomes NULL. The subsequent while(r!=NULL) loop will not execute. If the word is greater than head->word, it should be appended. But if r is NULL initially, the code falls through to if(r==NULL). However, if there are more elements, r points to head->next. The logic inside the loop handles insertion before r. But what if the word belongs at the end? The loop exits when r becomes NULL. Then if(r==NULL) handles appending. BUT, there is a critical flaw: if the word already exists in the list, we free(p). But if the word is new and needs to be inserted, we use p. The variable r is used for traversal. The allocation of r here is unnecessary and incorrect.]
                r->last=NULL;
                r->next=NULL;
                r=head->next;
                while(r!=NULL)
                {
                    if(strcmp(temp,r->word)>0)
                    {
                        r=r->next;
                    }
                    else if(strcmp(temp,r->word)==0)
                    {
                        r->time=r->time+1;
                        free(p);
                        break;
                    }
                    else
                    {
                        p->last=r->last;
                        r->last->next=p;
                        r->last=p;
                        p->next=r;
                        break;
                    }
                }
                if(r==NULL)
                {
                    p->last=tail;
                    tail->next=p;
                    tail=p;
                }
            }
            temp[0]='\0';
        }
    }
    node *p=head;
    while(p!=NULL)
    {
        printf("%s %d\n",p->word,p->time);
        p=p->next;
    }
    return 0;
}