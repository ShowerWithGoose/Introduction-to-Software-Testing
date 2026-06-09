#include <stdio.h>
#include <math.h>
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
} // @@ [The 'type' function only checks for lowercase letters, but input may contain uppercase letters. Since 'tolower' is applied before calling 'type', this is actually okay. However, the real issue is that non-alphabetic characters after tolower() (like digits or punctuation) are not handled correctly because tolower(EOF) is undefined behavior.]
int getword(char s[])
{
    int c, i = 0;
    while (type(c = tolower(fgetc(IN))) != 1)
        if (c == EOF)
            return c;
        else
            continue;
    s[i++] = c; // 下一句的fgetc读到文件尾返回EOF
    while ((c = tolower(fgetc(IN))) != EOF)
    {
        if (type(c) != 1)
            break;
        s[i++] = c;
    }
    s[i] = '\0';
    return 1;
} // @@ [Calling tolower() on EOF is undefined behavior. fgetc returns EOF when end-of-file is reached, and passing EOF to tolower() leads to undefined behavior per the C standard. This can cause crashes or incorrect behavior.]
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
    fclose(IN); // 关闭文件
} // @@ [The file IN is closed here, but it is also closed again in main(), leading to double fclose() which is undefined behavior.]
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
    fclose(IN); // @@ [Double fclose(): 'IN' is already closed inside work(), so closing it again here results in undefined behavior.]
    return 0;
}