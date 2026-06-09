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
    in = fopen("article.txt", "r"); // @@ Missing check for NULL return, may cause segmentation fault if file not found.
    while(fgets(ch, 1999, in) != NULL)
    {
        int l = strlen(ch);
        for(int i = 0; i < l; i++)
        {
            if(isalpha(ch[i]))
            {
                cnt++; // @@ cnt may exceed array size (1000) causing out-of-bounds access.
                int l1 = 0;
                while(isalpha(ch[i]))
                {
                    word[cnt].w[l1] = tolower(ch[i]); // @@ No bounds check; word longer than 49 characters will overflow buffer.
                    l1++;
                    i++;
                } // @@ Missing null terminator '\0' for word string, causing undefined behavior in subsequent string operations.
            }
            else
            {
                continue;
            }
            for(int j = 1; j <= cnt - 1; j++)
            {
                if(strcmp(word[j].w, word[cnt].w) == 0) // @@ strcmp on strings that may not be null-terminated (missing '\0' from line 34).
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
    for(int i = 1; i <= cnt; i++)
    {
        for(int j = 1; j <= cnt - i; j++)
        {
            if(strcmp(word[j].w, word[j + 1].w) > 0) // @@ strcmp on strings that may not be null-terminated.
            {
                char t1[50];
                strcpy(t1, word[j].w); // @@ strcpy source may not be null-terminated.
                strcpy(word[j].w, word[j + 1].w); // @@ strcpy source may not be null-terminated.
                strcpy(word[j + 1].w, t1); // @@ strcpy source (t1) may not be null-terminated.
                int temp;
                temp = word[j].count;
                word[j].count = word[j + 1].count;
                word[j + 1].count = temp;
            }
        }
    }
    for(int i = 1; i <= cnt; i++)
    {
        printf("%s %d\n", word[i].w, word[i].count); // @@ printf %s on string that may not be null-terminated.
    }
    return 0;
}