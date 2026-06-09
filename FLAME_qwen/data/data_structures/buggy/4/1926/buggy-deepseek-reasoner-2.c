#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char w[20];
    int num;
    struct node *next;
} node;
typedef struct node* word;

int main()
{
    int i=0,count=0;
    char dc[100]= {'\0'},ch;
    FILE *in;
    in=fopen("article.txt","r");
    word p,list=NULL;
    list=(word)malloc(sizeof(node));
    list->next=NULL;
    list->num=0;
    while((ch=fgetc(in))!=EOF)
    {
        if(ch>='A'&&ch<='Z')
        {
            ch='a'+ch-'A';
            dc[i]=ch;
            i++;
        }
        else if(ch>='a'&&ch<='z')
        {
            dc[i]=ch;
            i++;
        }
        else if(dc[i-1]>='a'&&dc[i-1]<='z') // @@ accesses dc[-1] when i==0; undefined behavior; also fails to handle last word if file ends without a non-letter
        {
            for(word q=list; q!=NULL; q=q->next) // @@ includes dummy head node with uninitialized word, causing undefined behavior in strcmp
            {
                if(strcmp(q->w,dc)==0)
                {
                    q->num++;
                    count++;
                }
            }
            if(count==0)
            {
                for(word r=list; r!=NULL; r=r->next)
                {
                    if(r->num==0) // @@ incorrectly uses head node to store a word, causing the first word to be lost from output
                    {
                        strcpy(r->w,dc);
                        r->num=1;
                        for(int j=0; j<100; j++)
                            dc[j]='\0';
                    }
                    else if(strcmp(r->w,dc)<0&&r->next==NULL)
                    {
                        p=(word)malloc(sizeof(node));
                        strcpy(p->w,dc);
                        p->num=1;
                        p->next=r->next;
                        r->next=p;
                        for(int j=0; j<100; j++)
                            dc[j]='\0';
                    }
                    else if(strcmp(r->w,dc)<0&&strcmp(r->next->w,dc)>0)
                    {
                        p=(word)malloc(sizeof(node));
                        strcpy(p->w,dc);
                        p->num=1;
                        p->next=r->next;
                        r->next=p;
                        for(int j=0; j<100; j++)
                            dc[j]='\0';
                    }
                    else if(strcmp(list->w,dc)>0) // @@ condition does not depend on loop variable; may trigger multiple insertions at head for every node
                    {
                        p=(word)malloc(sizeof(node));
                        strcpy(p->w,dc);
                        p->num=1;
                        p->next=list;
                        list=p;
                        for(int j=0; j<100; j++)
                            dc[j]='\0';
                    }
                }
                for(int j=0; j<100; j++)
                    dc[j]='\0';
            }
            i=0;
            count=0;
        }
    }
    for(word q=list->next; q!=NULL; q=q->next) // @@ skips head node; if first word was stored in head (due to earlier error), it will not be printed
    {
        printf("%s %d\n",q->w,q->num);
    }
    fclose(in);
    return 0;
}