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
        fn->link = p; // @@ [Error: When list is not NULL and n becomes NULL, fn points to the last node, but if list is NULL initially, fn is also NULL, causing a segmentation fault. Additionally, this case should handle the scenario where the new word is greater than all existing words, but the function does not check if list is NULL before accessing fn->link.]
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
        s[i++] = c; // @@ [Error: This line is unreachable because the continue statement above will always skip it. The logic is flawed: the while loop should skip non-letter characters, but the assignment to s[i++] is placed after continue, so it never executes. This results in an empty string s being returned.]
    } // 下一句的fgetc读到文件尾返回EOF
    while ((c = fgetc(fp)) != EOF)
    {
        if (type(c) != 'a' || type(c) != '0') // @@ [Error: The condition is always true because if type(c) is 'a', then type(c) != '0' is true; if type(c) is '0', then type(c) != 'a' is true; for other characters, both are true. This means the loop breaks immediately after reading the first character of a word, so only the first letter is stored. The correct condition should be if (type(c) != 'a' && type(c) != '0') to continue reading letters and digits, but the problem only requires letters.]
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
    char new[10]; // @@ [Error: The buffer size is too small (10 characters) to hold words like "roughage" or "remember", causing buffer overflow and undefined behavior.]
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