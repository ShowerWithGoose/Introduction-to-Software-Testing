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
            return 0; // @@ [This should return EOF to signal end of file, not 0. Returning 0 causes the main loop to continue indefinitely or process garbage.]
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
    while (getWord(in,wor)) // @@ [The loop condition is wrong: getWord returns 0 on success and 0 on EOF (due to the error above), so this loop never runs. It should loop while getWord returns 0 (success), not while it's non-zero.]
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