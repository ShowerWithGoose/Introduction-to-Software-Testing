#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//在此单词为仅由字母组成的字符序列。包含大写字母的单词应将大写字母转换为小写字母后统计
#define LETTER 'a'
#define DIGIT '0'
#define MAXWORDLEN 50
char string[MAXWORDLEN];
typedef struct node
{
    /* data */
    char word[MAXWORDLEN];
    int ans;
    struct node *link;
} Keynode, *linklist;
linklist list = NULL;
int getword(char *s, FILE *fp);
int FIND(char *w);
int insert(linklist p,char *w);

void DESTROY(linklist list)
{
    linklist p = list;
    while (p != NULL)
    {
        list = p->link;
        free(p);
        p = list;
    }
}
int main()
{
    FILE *fp;
    fp = fopen("article.txt", "r");
    if (fp == NULL)
    {
        perror("error when iniatiating the file");
        return -1;
    }
    
    linklist p, r;
    int cnt = 0;
    r = list;
    while (getword(string, fp) != EOF)
    {

        if(FIND(string)==-1)
        return -1;
    }
    for(p=list;p!=NULL;p=p->link)
    {
        printf("%s %d\n",p->word,p->ans);
    }
    DESTROY(list);
    return 0;
}
int getword(char *s, FILE *fp)
{
    int c;
    while (!isalpha(c = fgetc(fp)))
        if (c == EOF)
            return c;
        else
            continue;
    do
    {
        *s++ = tolower(c);//转换为小写
    } while (isalpha(c = fgetc(fp)));
    *s = '\0';
    return 1;
}
int FIND(char *w)
{
    linklist p, q = NULL; // q为前继
    for (p = list; p != NULL; q = p, p = p->link)
    {
        if (strcmp(w, p->word) < 0)
            break;
        else if (strcmp(w, p->word) == 0)
        {
            p->ans++;
            return 0;
        }
    }

    return insert(q, w);
}
int insert(linklist p,char *w)
{
    linklist q;
    q=(linklist)malloc(sizeof(Keynode));
    if(q==NULL) return -1;
    strcpy(q->word,w);
    q->ans=1;//第一次出现
    q->link=NULL;//插入最后
    if(list==NULL)
    list=q;
    else if(p==NULL)
    {
        q->link=list;
        list=q;
    }
    else
    {
        q->link=p->link;
        p->link=q;

    }
    return 0;
}
