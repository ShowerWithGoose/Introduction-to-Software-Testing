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
            temp[h]=c+'\0'; // @@ [Adding '\0' to a character is incorrect; it overwrites the letter with a null terminator. Should assign 'c' directly, then convert case if needed.]
            if(c >= 'A'&&c<='Z')
            {
                temp[h]=temp[h]-('A'-'a'); // @@ [Because temp[h] was set to '\0' above, this becomes '\0' - ('A'-'a'), which is negative and wrong. The case conversion logic is applied after corrupting the character.]
            }
            h++;
        }
        else
        {
            if(flag==0)
            continue;
            else
            break; // @@ [This breaks after the first non-letter character, so only the first word in the file is ever read. The function returns immediately after reading one word, ignoring the rest of the file.]
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
                node *r=malloc(sizeof(node)); // @@ [Unnecessary malloc: 'r' is used as a traversal pointer, not a new node. This leaks memory and causes undefined behavior when r is reassigned to head->next.]
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