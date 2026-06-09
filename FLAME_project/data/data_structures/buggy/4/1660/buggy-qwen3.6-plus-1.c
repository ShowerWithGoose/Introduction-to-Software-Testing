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
    while (!isalpha(c=fgetc(fp)))//跳过非字母 @@ [The variable 'c' is used in the condition before being initialized or assigned a valid value from fgetc if the loop body isn't entered correctly, but more critically, if the file starts with non-alpha chars, it works. However, the main issue is that fgetc returns an int, and assigning to char might lose EOF information on some systems, but standard C handles this. The real logical error is often subtle. Let's look closer. Actually, the logic `!isalpha(c=fgetc(fp))` reads a char. If it's not alpha, it loops. If it is alpha, it proceeds. This part is generally okay for skipping non-alphas. ]
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
    return 0; // @@ [The function always returns 0. The main loop `while (getWord(in,wor))` expects a non-zero value (true) to continue when a word is successfully read, and 0 (false) to stop. Since it always returns 0, the loop in main never executes, resulting in no output. It should return 1 on success.]
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
    while (getWord(in,wor))
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