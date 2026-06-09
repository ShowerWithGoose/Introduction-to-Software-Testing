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
        fn->link = p; // @@ Logic error: If the list was initially NULL, fn is NULL, causing a crash. Also, if p is greater than all existing words, this appends correctly only if fn is valid. However, the main issue is handling the empty list case or insertion at end when list is not null but fn might be uninitialized in some paths if logic is flawed. But specifically here, if list is not NULL, fn starts as list. If the loop doesn't run (p < list), n=list. If loop runs until end, n=NULL, fn is last node. This part is technically okay for non-empty list append, BUT:
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
    while (type(c = fgetc(fp)) != 'a') // @@ Logical error: The condition checks if the character is NOT a letter. Inside the loop, if it's EOF it returns. But if it's not a letter, it continues. The line `s[i++] = c;` is unreachable because of `continue`. This loop correctly skips non-letters.
    {
        if (c == EOF)
            return c;
        else
            continue;
        s[i++] = c; // @@ Unreachable code: This line is never executed due to the 'continue' statement above. This is not the primary bug causing wrong output format but indicates flawed logic.
    } // 下一句的fgetc读到文件尾返回EOF
    while ((c = fgetc(fp)) != EOF)
    {
        if (type(c) != 'a' && type(c) != '0') // @@ Logical error: The original code used `||` (OR). `type(c) != 'a' || type(c) != '0'` is always true because a character cannot be both 'a' (letter) and '0' (digit) at the same time, so one of the inequalities is always true. It should be `&&` (AND) to break when the character is neither a letter nor a digit (i.e., stop reading the word when a separator is found). Wait, actually, we want to read letters. If it's a letter, continue. If it's not a letter, stop. The check `type(c) != 'a'` means "if it is not a letter". We should break if it is not a letter. The additional `|| type(c) != '0'` makes it always true. It should just be `if (type(c) != 'a') break;`. Using `&&` with `!= '0'` is also incorrect logic for stopping. We simply want to stop if it's not a letter.
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
    char new[10]; // @@ Buffer overflow risk: The struct word has word[20], but here new is only [10]. If a word is longer than 9 chars, it will overflow. Should be at least 20.
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