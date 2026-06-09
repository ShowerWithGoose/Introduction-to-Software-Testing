#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct word
{
    char c[30];
    int count;
    struct word *next;
};

struct rec
{
    char c[30];
    int count;
}rec[100];

typedef struct word node;
typedef struct word *pnode;

pnode wordlist = NULL;

//插入单词
int insert(pnode p, char *w)
{
    //建立新节点q
    pnode q = (pnode)malloc(sizeof(node));
    strcpy(q->c, w);
    q->count = 1;
    q->next = NULL;
    if (wordlist == NULL)
    //判断头结点（整个链表）是否为空
    {
        wordlist = q;
    }
    //插入到头节点前
    else if(p==NULL){
        q->next = wordlist;
        wordlist = q;
    }
    else
    {
        q->next = p->next;
        p->next = q;
    }
    return 0;
}

int search(char *w)
{
    pnode p = NULL, q = NULL;
    //q记录当前p指向节点的前一个节点
    for (p = wordlist; p != NULL; q = p, p = p->next)
    {
        if (strcmp(p->c, w) == 0)
        {
            //已经存在该单词，将次数+1
            p->count++;
            return 1;
        }
        else if (strcmp(p->c, w) < 0)
        {
            //p已经移多了1位，q指向正确的插入位置之前的节点
            break;
        }
    }
    //在q后插入w
    return insert(q, w);
}
//**读取单词（标准操作）**
int getWord(FILE *fp, char *w)
{
    int c;
    while (!isalpha(c = fgetc(fp)))
        if (c == EOF)
            return c;
        else
            continue;
    do
    {
        *w++ = tolower(c);
    } while (isalpha(c = fgetc(fp)));
    *w = '\0';
    return 1;
}

int main()
{
    //打开文件
    FILE *fp;
    fp = fopen("article.txt", "r");

    char word[100];
    pnode p = NULL;

    //读入单词
    while (getWord(fp, word) != EOF)
    {
        //搜索是否已经存在单词
        search(word);
    }
    int i=0;
    for (p = wordlist; p != NULL; p = p->next)
    {
        strcpy(rec[i].c, p->c);
        rec[i].count = p->count;
        i++;
    }
    for (int j=i;j>0;j--)
    {
        printf("%s %d\n", rec[j-1].c, rec[j-1].count);
    }
    fclose(fp);
    return 0;
}
