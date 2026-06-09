#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct infor{char word[50];
             int n;
             struct infor *next;
             };
int main()
{
    struct infor *head=NULL,*p,*q,*temp;
    char buf[50]={'\0'};
    FILE *in;
    int i,c;
    in=fopen("article.txt", "r");
    if (in == NULL)
        printf("1");
    while((c=fgetc(in))!=EOF)
    {
        if(tolower(c)<'a'||tolower(c)>'z')
            continue;
        for(i=0;tolower(c)>='a'&&tolower(c)<='z'&&c!=EOF;i++)
        {
            buf[i]=tolower(c);
            c=fgetc(in);
        }
        buf[i]='\0';
        if(head==NULL)
        {
            head=(struct infor*)malloc(sizeof(struct infor));
            strcpy((head->word),buf);
            head->n=1;
            head->next=NULL;
            continue;
        }
        if(head!=NULL)
        {
            if(strcmp((head->word),buf)>0)
            {
                temp=(struct infor*)malloc(sizeof(struct infor));
                strcpy((temp->word),buf);
                temp->n=1;
                temp->next=head;
                head=temp;
                temp=NULL;
                continue;
            }
            if(strcmp((head->word),buf)==0)
            {
                (head->n)++;
            }
            else
            {
                for(q=head,p=head->next;p!=NULL&&strcmp((p->word),buf)<0;q=p,p=p->next)
                    ;
                if(p==NULL)
                {
                    temp=(struct infor*)malloc(sizeof(struct infor));
                    strcpy((temp->word),buf);
                    temp->n=1;
                    temp->next=NULL;
                    q->next=temp;
                    temp=NULL;
                    continue;
                }
                if(p!=NULL)
                {
                    if(strcmp((p->word),buf)==0)
                        (p->n)++;
                    if(strcmp((p->word),buf)>0)
                    {
                        temp=(struct infor*)malloc(sizeof(struct infor));
                        strcpy((temp->word),buf);
                        temp->n=1;
                        temp->next=p;
                        q->next=temp;
                        temp=NULL;
                    }
                }
            }
        }
    }
    for(p=head;p!=NULL;p=p->next)
    {
        printf("%s %d\n",(p->word),(p->n));
        free(p);
    }
    fclose(in);
    return 0;
}

