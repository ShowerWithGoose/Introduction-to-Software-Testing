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
    in=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgetc(in) leads to undefined behavior. The program should check if 'in' is NULL before proceeding.]
    word p,list=NULL;
    list=(word)malloc(sizeof(node));
    list->next=NULL;
    list->num=0;
    while((ch=fgetc(in))!=EOF) // @@ [The variable 'ch' is declared as char, but fgetc returns an int. When EOF (typically -1) is returned, storing it in a char may cause it to become positive due to sign extension or truncation, leading to an infinite loop. Declare 'ch' as int instead of char.]
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
        else if(dc[i-1]>='a'&&dc[i-1]<='z') // @@ [When i is 0 (e.g., at start or after non-letter), dc[i-1] accesses dc[-1], which is out-of-bounds and causes undefined behavior. This condition should only trigger when i > 0.]
        {
            for(word q=list; q!=NULL; q=q->next)
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
                    if(r->num==0)
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
                    else if(strcmp(list->w,dc)>0)
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
    for(word q=list->next; q!=NULL; q=q->next) // @@ [The initial dummy node (list) is never filled with a real word unless r->num==0 branch is taken, but even then, the output skips list itself by starting at list->next. However, if the first word is inserted into the dummy node (when r->num==0), it will be skipped in output because the loop starts from list->next. This causes missing output for the first inserted word.]
    {
        printf("%s %d\n",q->w,q->num);
    }
    fclose(in);
    return 0;
}