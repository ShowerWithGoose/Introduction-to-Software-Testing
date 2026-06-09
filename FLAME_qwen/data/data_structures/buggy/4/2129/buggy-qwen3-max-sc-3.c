#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct node
{
    char word[20];
    int n;
    struct node *link;
} word;
void squeez(char s[])
{
    int j, i;
    for (i = 0, j = 0; s[i] != '\0'; i++)
    {
        if (isalpha(s[i]))
        {
            s[j] = tolower(s[i]);
            j++;
        }
    }
    s[j] = '\0';
}
word *insert(word *list, word *p)
{
    word *n, *fn = list;
    for (n = list; n != NULL && strcmp(p->word, n->word) > 0; n = n->link)
    {
        fn = n;
    }
    if (n == NULL)
    {
        fn->link = p;
        return list;
    }
    if (n == list)
    {
        if (strcmp(p->word, n->word) == 0)
        {
            list->n += 1;
            return list;
        }
        else
        {
            p->link = list;
            list = p;
            return list;
        }
    }

    if (strcmp(p->word, n->word) == 0)
    {
        n->n += 1;
        return list;
    }
    else
    {
        fn->link = p;
        p->link = n;
        return list;
    }
}
char type(int c) /* return type of ASCII character */
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') // 是大小写字母吗？
        return ('a');
    else if (c >= '0' && c <= '9') // 是数字吗？
        return ('0');
    else
        return (c);
}

int getword(char s[], FILE *fp)

{
    int c, i = 0;
    while (type(c = fgetc(fp)) != 'a')
    {
        if (c == EOF)
            return c;
        else
            continue;
        s[i++] = c; // @@ [This line is unreachable due to 'continue' above; also, non-alphabetic characters should not be added to the word]
    } // 下一句的fgetc读到文件尾返回EOF
    while ((c = fgetc(fp)) != EOF)
    {
        if (type(c) != 'a' || type(c) != '0') // @@ [Logical error: condition always true because a character cannot be both 'a' and '0'; should break on non-alphabetic only]
            break;
        s[i++] = c;
    }
    s[i] = '\0';
    return 1;
}

int main(int argc, char const *argv[])
{
    FILE *in;
    in = fopen("article.txt", "r");
    word *list = NULL, *p;
    char new[10]; // @@ [Buffer too small; words longer than 9 characters will overflow]
    while (getword(new, in) != EOF)
    {
        p = (word *)malloc(sizeof(word));
        p->link = NULL, p->n = 1;
        strcpy(p->word, new);
        if (list == NULL)
        {
            list = p;
        }
        else
        {
            list = insert(list, p);
        }
    }
    word *n = list;
    while (n != NULL)
    {
        printf("%s %d\n", n->word, n->n);
        n = n->link;
    }

    return 0;
}