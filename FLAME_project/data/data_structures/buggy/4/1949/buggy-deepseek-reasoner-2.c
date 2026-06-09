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
            temp[h]=c+'\0';
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
            else // @@ This else block executes even when temp equals head->word, causing duplicate nodes for the head word. A check for equality with head should be added before this else.
            {
                node *r=malloc(sizeof(node)); // @@ Memory leak: allocated node is never used and overwritten in the next line.
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