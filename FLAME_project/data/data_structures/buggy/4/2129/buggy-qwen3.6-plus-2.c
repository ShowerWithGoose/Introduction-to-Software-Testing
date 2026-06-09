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
        fn->link = p; // @@ [Logic Error: If the loop finishes because n is NULL, it means p is lexicographically larger than all existing nodes. However, if the list was initially empty or if the loop didn't run correctly, fn might not be the correct tail. More critically, this block handles appending to the end, but fails to handle the case where the list is empty properly if called externally, though main handles NULL list. The real issue is often that fn is not updated if the list has only one element and p is greater, but here fn starts as list. If list is not null, fn is valid. But wait, if the list is empty, this function shouldn't be called based on main logic. The bigger issue is below.]
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
    while (type(c = fgetc(fp)) != 'a') // @@ [Logical Error: The condition checks if the character is NOT a letter. If it's not a letter, it continues. However, if c is EOF, type(EOF) will likely return EOF (which is not 'a'), so it stays in the loop. Inside the loop, it checks for EOF. This part is okayish, but...]
    {
        if (c == EOF)
            return c;
        else
            continue; // @@ [Logical Error: 'continue' jumps to the next iteration of the while loop. The line s[i++] = c; below is NEVER executed. This is dead code. Even if it were executed, we are skipping non-letters, so we shouldn't store them in s anyway. The main problem is the next part.]
        s[i++] = c;
    } // 下一句的fgetc读到文件尾返回EOF
    while ((c = fgetc(fp)) != EOF)
    {
        if (type(c) != 'a' || type(c) != '0') // @@ [Logical Error: This condition is always true. A character cannot be BOTH 'a' (letter) AND '0' (digit) at the same time. So type(c) != 'a' OR type(c) != '0' will always evaluate to true. For a letter, type(c) is 'a', so 'a' != '0' is true. For a digit, type(c) is '0', so '0' != 'a' is true. For others, both are true. Thus, the loop breaks immediately after reading the first character of the word. This results in only the first letter of each word being stored.]
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
    char new[10]; // @@ [Potential Buffer Overflow: The struct defines word[20], but here buffer is only 10. While unlikely to overflow with standard words, it's inconsistent. More importantly, if getword reads more than 9 chars, it overflows.]
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