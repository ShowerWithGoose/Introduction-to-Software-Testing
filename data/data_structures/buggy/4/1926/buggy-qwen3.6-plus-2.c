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
        else if(dc[i-1]>='a'&&dc[i-1]<='z') // @@ Array index out of bounds when i=0 (if file starts with a non-letter), causing undefined behavior.
        {
            for(word q=list; q!=NULL; q=q->next) // @@ Should iterate from list->next to skip the dummy head; comparing with uninitialized list->w causes undefined behavior. Also, declaring variable inside for loop is C99 and may cause compilation error in C89.
            {
                if(strcmp(q->w,dc)==0)
                {
                    q->num++;
                    count++;
                }
            }
            if(count==0)
            {
                for(word r=list; r!=NULL; r=r->next) // @@ Missing break statement after successful insertion causes the loop to continue, potentially inserting the same word multiple times and corrupting the linked list. Also C99 declaration.
                {
                    if(r->num==0)
                    {
                        strcpy(r->w,dc); // @@ Buffer overflow risk: dc can hold up to 100 characters, but r->w is only 20 bytes.
                        r->num=1;
                        for(int j=0; j<100; j++) // @@ C99 variable declaration inside for loop may cause compilation error if compiled with C89/C90 standard.
                            dc[j]='\0';
                    }
                    else if(strcmp(r->w,dc)<0&&r->next==NULL)
                    {
                        p=(word)malloc(sizeof(node));
                        strcpy(p->w,dc); // @@ Buffer overflow risk.
                        p->num=1;
                        p->next=r->next;
                        r->next=p;
                        for(int j=0; j<100; j++) // @@ C99 variable declaration inside for loop may cause compilation error if compiled with C89/C90 standard.
                            dc[j]='\0';
                    }
                    else if(strcmp(r->w,dc)<0&&strcmp(r->next->w,dc)>0) // @@ Potential null pointer dereference if r->next is NULL; condition should explicitly check r->next != NULL before accessing r->next->w.
                    {
                        p=(word)malloc(sizeof(node));
                        strcpy(p->w,dc); // @@ Buffer overflow risk.
                        p->num=1;
                        p->next=r->next;
                        r->next=p;
                        for(int j=0; j<100; j++) // @@ C99 variable declaration inside for loop may cause compilation error if compiled with C89/C90 standard.
                            dc[j]='\0';
                    }
                    else if(strcmp(list->w,dc)>0)
                    {
                        p=(word)malloc(sizeof(node));
                        strcpy(p->w,dc); // @@ Buffer overflow risk.
                        p->num=1;
                        p->next=list;
                        list=p;
                        for(int j=0; j<100; j++) // @@ C99 variable declaration inside for loop may cause compilation error if compiled with C89/C90 standard.
                            dc[j]='\0';
                    }
                }
                for(int j=0; j<100; j++) // @@ C99 variable declaration inside for loop may cause compilation error if compiled with C89/C90 standard.
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