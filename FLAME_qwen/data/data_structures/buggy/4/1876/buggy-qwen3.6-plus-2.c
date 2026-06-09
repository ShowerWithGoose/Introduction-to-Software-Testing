#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#include<string.h>
#include <stdio.h>
struct word {
    char name[100];
    int num;
    int turn;
}a[1000];
char s[100];   char ss[100];
int main()
{
    FILE* p;
    p = fopen("article.txt", "r");
    int l1, i, j = 0, k = 0, cnt = 0, t;
    while (fgets(s,sizeof(s),p) != NULL)
    {
        l1 = strlen(s);
        for (i = 0; i < l1; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 'a' - 'A';
        }
        for (i = 0; i < l1; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                a[k].name[j] = s[i];
                j++;
            }
            else if (s[i] == ' '||s[i]=='.'||s[i]==';') // @@ Logical error: Only checks specific punctuation. Should handle any non-alphabetic character to correctly terminate words as per problem definition.
            {
                a[k].num += 1; // @@ Logical error: `a[k].num` is not explicitly initialized to 1 for a new word. Relies on global zero-initialization, which is unsafe.
                cnt += 1;
                k += 1;
                j = 0; // @@ Logical error: Missing null-terminator assignment `a[k-1].name[j] = '\0';` before resetting `j`. Causes undefined behavior in `strcmp` and `printf`.
            }
            else
                continue;
        }
        memset(s, 0, sizeof(s));
    }
    for (i = 0; i < cnt; i++)
    {
        for (j = cnt ; j > i; j--) // @@ Runtime error: Array index out of bounds. Valid indices are `0` to `cnt-1`. Accessing `a[cnt]` reads uninitialized memory. Should start from `j = cnt - 1`.
        {
            if (strcmp(a[i].name, a[j].name) == 0)
            {
                a[i].num += a[j].num;
                a[j].num = 0;
            }
        }
    }
    for (j = 0; j < cnt; j++)
    {
        for (i = 0; i < cnt - 1; i++)
        {
            if (strcmp(a[i].name, a[i + 1].name) > 0)
            {
                strcpy(ss, a[i].name);    t = a[i].num;
                strcpy(a[i].name, a[i + 1].name);    a[i].num = a[i + 1].num;
                strcpy(a[i + 1].name, ss);    a[i + 1].num = t;
            }
        }
    }
    for (i = 0; i < cnt; i++)
    {
        if (a[i].num != 0)
            printf("%s %d\n", a[i].name, a[i].num);
    }
    fclose(p);
}