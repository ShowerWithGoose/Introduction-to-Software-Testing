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
    char c; // @@ Should be int c to correctly store the return value of fgetc and properly compare with EOF
    while (!isalpha(c=fgetc(fp)))//跳过非字母
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
    return 0; // @@ Should return 1 to indicate a word was successfully read, otherwise the while loop in main will never execute
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
    while (getWord(in,wor)) // @@ Loop condition expects getWord to return non-zero on success, but it currently always returns 0
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