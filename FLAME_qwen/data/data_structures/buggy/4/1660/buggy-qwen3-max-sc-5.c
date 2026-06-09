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
    while (!isalpha(c=fgetc(fp)))//跳过非字母
    {
        if(c==EOF)
        {
            return 0; // @@ [This returns 0 on EOF, but the main loop expects a non-zero value to continue. This causes infinite loop or premature termination because the loop condition in main() is `while (getWord(in,wor))`, which stops when getWord returns 0. However, returning 0 on EOF means the loop stops correctly, but the real issue is that when the file ends without a trailing non-alphabetic character, the last word may not be processed properly. But more critically: `c` is used uninitialized if fgetc returns EOF immediately, leading to undefined behavior in `isalpha(c)`.]
        }
        continue;
    }

    do
    {
        *w++=tolower(c);
    } while (isalpha(c=fgetc(fp)));
    *w='\0';
    return 0;
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
    while (getWord(in,wor)) // @@ [The loop condition is incorrect: getWord always returns 0, so this loop never executes. It should loop until EOF is encountered inside getWord, but the current design returns 0 both on success and on EOF, making it impossible to distinguish. The loop should continue as long as a word is read, but getWord returns 0 even when a word is successfully read, so the condition fails immediately.]
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