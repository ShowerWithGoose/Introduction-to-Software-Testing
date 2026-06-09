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
            else if (s[i] == ' '||s[i]=='.'||s[i]==';')
            {
                a[k].num += 1; // @@ [The word is not null-terminated before incrementing count, and initial num value is uninitialized (garbage). Also, words at end of line without delimiter may be missed.]
                cnt += 1;
                k += 1;
                j = 0;
            }
            else
                continue;
        }
        memset(s, 0, sizeof(s));
    }
    for (i = 0; i < cnt; i++)
    {
        for (j = cnt ; j > i; j--) // @@ [Loop condition should be j >= i+1 or similar; using j = cnt as starting index accesses out-of-bounds array element a[cnt], which is invalid since valid indices are 0 to cnt-1.]
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
    fclose(p); // @@ [Missing return statement; though not strictly an error in C89/C90, it's good practice and may cause warnings. However, the main issue is that the program doesn't handle file open failure. If fopen fails, p is NULL and fgets causes undefined behavior.]
}