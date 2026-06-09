#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

FILE *in;

struct
{
    char w[50];
    int count;
}word[1000];

char ch[2000];

int main()
{
    int cnt = 0, flag = 0;
    in = fopen("article.txt", "r");
    while(fgets(ch, 1999, in) != NULL)
    {
        int l = strlen(ch);
        for(int i = 0; i < l; i++) // @@ Variable declaration inside 'for' loop initialization is not supported in C89 standard, which may cause a compilation error.
        {
            if(isalpha(ch[i]))
            {
                cnt++;
                int l1 = 0;
                while(isalpha(ch[i]))
                {
                    word[cnt].w[l1] = tolower(ch[i]);
                    l1++;
                    i++;
                } // @@ Missing null terminator '\0' assignment for word[cnt].w, causing strcmp and printf to read out of bounds and produce incorrect results or crash.
            }
            else
            {
                continue;
            }
            for(int j = 1; j <= cnt - 1; j++) // @@ Variable declaration inside 'for' loop initialization is not supported in C89 standard, which may cause a compilation error.
            {
                if(strcmp(word[j].w, word[cnt].w) == 0)
                {
                    word[j].count++;
                    cnt--;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                word[cnt].count = 1;
            flag = 0;
        }
    }
    for(int i = 1; i <= cnt; i++) // @@ Variable declaration inside 'for' loop initialization is not supported in C89 standard, which may cause a compilation error.
    {
        for(int j = 1; j <= cnt - i; j++) // @@ Variable declaration inside 'for' loop initialization is not supported in C89 standard, which may cause a compilation error.
        {
            if(strcmp(word[j].w, word[j + 1].w) > 0)
            {
                char t1[50];
                strcpy(t1, word[j].w);
                strcpy(word[j].w, word[j + 1].w);
                strcpy(word[j + 1].w, t1);
                int temp;
                temp = word[j].count;
                word[j].count = word[j + 1].count;
                word[j + 1].count = temp;
            }
        }
    }
    for(int i = 1; i <= cnt; i++) // @@ Variable declaration inside 'for' loop initialization is not supported in C89 standard, which may cause a compilation error.
    {
        printf("%s %d\n", word[i].w, word[i].count);
    }
    return 0;
}