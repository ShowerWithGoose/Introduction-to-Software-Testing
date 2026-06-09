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
        else if(dc[i-1]>='a'&&dc[i-1]<='z') // @@ Out-of-bounds access when i==0; dc[-1] is undefined.
        {
            for(word q=list; q!=NULL; q=q->next) // @@ Should start from list->next; dummy head node has uninitialized w.
            {
                if(strcmp(q->w,dc)==0) // @@ Dummy head's w is uninitialized, causing undefined behavior.
                {
                    q->num++;
                    count++;
                }
            }
            if(count==0)
            {
                for(word r=list; r!=NULL; r=r->next) // @@ This loop modifies the list while iterating; insertion logic is fundamentally flawed.
                {
                    if(r->num==0) // @@ Treats dummy head as an empty slot; overwrites dummy head's word, corrupting the list structure.
                    {
                        strcpy(r->w,dc);
                        r->num=1;
                        for(int j=0; j<100; j++)
                            dc[j]='\0';
                    }
                    else if(strcmp(r->w,dc)<0&&r->next==NULL) // @@ r->w may be uninitialized for dummy head; logic does not guarantee correct insertion order.
                    {
                        p=(word)malloc(sizeof(node));
                        strcpy(p->w,dc);
                        p->num=1;
                        p->next=r->next;
                        r->next=p;
                        for(int j=0; j<100; j++)
                            dc[j]='\0';
                    }
                    else if(strcmp(r->w,dc)<0&&strcmp(r->next->w,dc)>0) // @@ Risks dereferencing NULL if r->next is NULL; also uninitialized dummy head word.
                    {
                        p=(word)malloc(sizeof(node));
                        strcpy(p->w,dc);
                        p->num=1;
                        p->next=r->next;
                        r->next=p;
                        for(int j=0; j<100; j++)
                            dc[j]='\0';
                    }
                    else if(strcmp(list->w,dc)>0) // @@ list->w is uninitialized; condition is unreliable and may cause incorrect list modification.
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
    for(word q=list->next; q!=NULL; q=q->next)
    {
        printf("%s %d\n",q->w,q->num);
    }
    fclose(in);
    return 0;
}