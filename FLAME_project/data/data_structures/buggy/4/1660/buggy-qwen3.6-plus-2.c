#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
    char word[100];
    int num;
    struct node* next;
};
struct node *list=NULL;

struct node *creatNode(char *w)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    strcpy(p->word,w);
    p->num=1;
    p->next=NULL;
    return p;
}
int getWord(FILE *fp,char *w)
{
    char c;
    while (!isalpha(c=fgetc(fp)))//跳过非字母 @@ [The variable 'c' is used in the condition before being initialized or assigned a valid value from fgetc if the loop body isn't entered correctly, but more importantly, if fgetc returns EOF immediately, isalpha(EOF) behavior is undefined or false. However, the critical bug is that if the file starts with non-alpha characters, it skips them. If it hits EOF inside the loop, it returns 0. But if the first character read is EOF, isalpha(EOF) is called. The main logical error here is that the function returns 0 on success (finding a word) and 0 on EOF? No, it returns 0 when EOF is encountered. But the while loop in main checks `while(getWord(in,wor))`. Since getWord always returns 0 (either explicitly or by falling off the end if we ignore the explicit return 0), the loop in main will never execute. The function should return 1 on success and 0 on EOF.]
    {
        if(c==EOF)
        {
            return 0;
        }
        continue;
    }

    do
    {
        *w++=tolower(c);
    } while (isalpha(c=fgetc(fp)));
    *w='\0';
    return 0; // @@ [This function always returns 0. The main loop `while (getWord(in,wor))` expects a non-zero value (true) to continue processing words. It should return 1 (or any non-zero value) when a word is successfully read, and 0 only when EOF is reached without reading a word.]
}
void chaRu(struct node *p,struct node *q)
{
    if(p==NULL)
    {
        q->next=list;
        list=q;
        return;
    }
    q->next=p->next;
    p->next=q;
}
void find_creat_chaRu(char *w)
{
    struct node *q,*last=NULL;
    for(q=list;q!=NULL;last=q,q=q->next)
    {
        if(strcmp(w,q->word)<0)
        {
            break;
        }
        else if(strcmp(w,q->word)==0)
        {
            q->num++;
            return;
        }
    }
    q=creatNode(w);
    chaRu(last,q);
}
int main()
{
    FILE *in;
    in = fopen("article.txt","r");
    char wor[100];
    while (getWord(in,wor)) // @@ [Because getWord always returns 0, this loop never executes, resulting in no output. getWord needs to return 1 on success.]
    {
        find_creat_chaRu(wor);
    }

    struct node* p=list;
    while (p!=NULL)
    {
        printf("%s %d\n",p->word,p->num);
        struct node* q=p;
        p=p->next;
        free(q);
    }
    
    fclose(in);
    return 0;
    
}