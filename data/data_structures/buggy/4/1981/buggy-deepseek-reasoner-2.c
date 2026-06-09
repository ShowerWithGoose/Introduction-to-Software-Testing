#include <stdio.h>
#include <math.h>  // 不需要
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *IN;
typedef struct link
{
    char x[50];
    int y;
    struct link *next, *up;
} *Nodeptr;
Nodeptr list = NULL;
int type(int c) /* return type of ASCII character */
{
    if (c >= 'a' && c <= 'z') // 是大小写字母吗？
        return 1;
    else
        return 3;
}
int getword(char s[])
{
    int c, i = 0;
    while (type(c = tolower(fgetc(IN))) != 1) // @@ 错误：先调用tolower再检查EOF，当文件结束时fgetc返回EOF，tolower(EOF)行为未定义，且条件判断错误可能导致无限循环
        if (c == EOF)
            return c;
        else
            continue;
    s[i++] = c; // 下一句的fgetc读到文件尾返回EOF
    while ((c = tolower(fgetc(IN))) != EOF) // @@ 错误：同样问题，应先检查fgetc返回值是否为EOF，再调用tolower
    {
        if (type(c) != 1)
            break;
        s[i++] = c;
    }
    s[i] = '\0';
    return 1;
}
int insertWord(Nodeptr r, char *w)
{
    Nodeptr t = NULL;
    t = (struct link *)malloc(sizeof(struct link));
    if (t == NULL)
        return -1;   // 没有内存空间
    strcpy(t->x, w); // 装填好一个初始值
    t->y = 1;        // 词频初值为1
    t->next = NULL;
    if (list == NULL) // 1:空链表,插入t结点
        list = t;
    else if (r == NULL)
    { // 2:首(头)结点前插入t
        t->next = list;
        list = t;
    }
    else
    { // 3:在r结点后插入t
        t->next = r->next;
        r->next = t;
    }
    return 0;
}
int searchWord(char *w)
{
    Nodeptr p, q = NULL; // q为p的前序结点指针
    for (p = list; p != NULL; q = p, p = p->next)
    {
        if (strcmp(w, p->x) < 0)
            break;
        else if (strcmp(w, p->x) == 0)
        {
            p->y++;
            return 0; // 找到加1,直接返回
        }
    }
    return insertWord(q, w); // 存在q为NULL
}
void work()
{
    Nodeptr p;
    for (p = list; p != NULL; p = p->next) // 遍历输出单词表
        printf("%s %d\n", p->x, p->y);
    fclose(IN); // @@ 错误：work函数中关闭了文件，main函数末尾还会再次关闭，导致重复关闭，可能引发未定义行为
}
int main()
{
    char word[50];
    IN = fopen("article.txt", "r");
    if (IN == NULL)
    {
        fprintf(stderr, "%s can't open !\n", "article");
        return -1;
    }
    while (getword(word) != EOF)
        if (searchWord(word) == -1)
        {
            fprintf(stderr, "Memory is full !\n");
            fclose(IN);
            return -1;
        }
    work();
    fclose(IN);
    return 0;
}