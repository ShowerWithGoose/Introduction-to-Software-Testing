#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 32
struct node
{
    char word[MAXWORD];
    int count;
    struct node *link;
}; // 单词表结构
// 单词表头指针，使用全局变量
struct node *Wordlist = NULL;
int getWord(FILE *bfp, char *w);
int searchWord(char *w);
int insertWord(struct node *p, char *w);

int main()
{
    char filename[32], word[MAXWORD];
    FILE *bfp;
    struct node *p;

    scanf("%s", filename); // @@ [The problem requires reading from "article.txt", but this reads the filename from stdin instead of using "article.txt" directly.]
    if ((bfp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "%s can't open!\n", filename);
        return -1;
    }
    // 从文件中读入一个单词
    while (getWord(bfp, word) != EOF)
        // 在单词表中查找插入单词
        if (searchWord(word) == -1)
        {
            fprintf(stderr, "Memory is full!\n");
            return -1;
        }
    // 遍历输出单词表
    for (p = Wordlist; p != NULL; p = p->link)
        printf("%s %d\n", p->word, p->count);
    return 0;
}

int getWord(FILE *fp, char *w)
{
    int c;
    while(!isalpha(c=fgetc(fp))) // @@ [The variable 'c' is used uninitialized in the first call to isalpha if fgetc returns EOF immediately; also, isalpha expects unsigned char or EOF, passing negative char values (on platforms where char is signed) may cause undefined behavior.]
        if(c == EOF)
            return c;
        else continue;
    do
    {
        *w++ = tolower(c);
    }
    while(isalpha(c=fgetc(fp)));
    *w='\0';
    return 1;
}

int insertWord(struct node *p, char *w)
{
    struct node *q;
    q = (struct node *)malloc(sizeof(struct node));
    if (q == NULL)
        return -1; // 没有内存空间
    strcpy(q->word, w);
    q->count = 1;
    q->link = NULL;
    if (Wordlist == NULL) // 空链表
        Wordlist = q;
    else if(p == NULL)
    {
        // 插入到第一个结点前
        q->link = Wordlist;
        Wordlist = q;
    }
    else
    {
        q->link = p->link;
        p->link = q;
    }
    return 0;
}

/*在链表中查找一单词，若找到，则次数加1；否则将该
单词插入到有序表中相应位置，同时次数置1*/
int searchWord(char *w)
{
    // q为p的前序结点指针
    struct node *p, *q = NULL;
    for (p = Wordlist; p != NULL; q = p, p = p->link)
    {
        if (strcmp(w, p->word) < 0)
            break;
        else if (strcmp(w, p->word) == 0)
        {
            p->count++;
            return 0;
        }
    }
    return insertWord(q, w);
}