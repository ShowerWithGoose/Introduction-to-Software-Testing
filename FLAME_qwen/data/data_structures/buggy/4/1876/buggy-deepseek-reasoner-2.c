#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#include<string.h>
#include <stdio.h> // @@ duplicate include, not an error but redundant
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
                a[k].num += 1; // @@ a[k].num is uninitialized, should be set to 1 on first occurrence
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
        for (j = cnt ; j > i; j--) // @@ out-of-bounds: j starts at cnt, but valid indices are 0..cnt-1
        {
            if (strcmp(a[i].name, a[j].name) == 0) // @@ a[j].name may not be null-terminated; also a[j] is out of bounds
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