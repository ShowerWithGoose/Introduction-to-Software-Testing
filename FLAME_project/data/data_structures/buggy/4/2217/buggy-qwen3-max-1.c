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
        for(int i = 0; i < l; i++)
        {
            if(isalpha(ch[i]))
            {
                cnt++; // @@ [cnt is incremented before the word is fully extracted, causing word[cnt] to be used before initialization and skipping index 0]
                int l1 = 0;
                while(isalpha(ch[i])) // @@ [This loop may go out of bounds if i reaches l without checking boundary]
                {
                    word[cnt].w[l1] = tolower(ch[i]);
                    l1++;
                    i++;
                }
                word[cnt].w[l1] = '\0'; // @@ [Missing null-terminator assignment after copying characters, leading to undefined behavior in strcmp]
            }
            else
            {
                continue;
            }
            for(int j = 1; j <= cnt - 1; j++) // @@ [Loop starts at j=1, so it never checks against word[0]; also, when cnt==1, loop doesn't run, which is okay, but indexing is off-by-one overall]
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
    for(int i = 1; i <= cnt; i++) // @@ [Sorting and printing start from index 1, skipping word[0], which may contain valid data if cnt started at 0 correctly]
    {
        for(int j = 1; j <= cnt - i; j++)
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
    for(int i = 1; i <= cnt; i++) // @@ [Printing starts from index 1, so if any word was stored at index 0, it would be omitted; also, due to incorrect cnt handling, "to" became "tou" because of missing null terminator and buffer overrun]
    {
        printf("%s %d\n", word[i].w, word[i].count);
    }
    return 0;
}