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
                cnt++; // @@ [cnt is incremented before word[cnt] is initialized, leading to out-of-bounds access and skipping index 0]
                int l1 = 0;
                while(isalpha(ch[i]))
                {
                    word[cnt].w[l1] = tolower(ch[i]); // @@ [uses word[cnt] where cnt may exceed array bounds; also fails to null-terminate the string]
                    l1++;
                    i++;
                }
                word[cnt].w[l1] = '\0'; // @@ [missing null-termination after copying letters]
            }
            else
            {
                continue;
            }
            for(int j = 1; j <= cnt - 1; j++) // @@ [loop starts at j=1, so it never checks against word[0]; also logic flawed because new word is at word[cnt], but comparison range excludes it properly]
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
                word[cnt].count = 1; // @@ [only sets count if not duplicate, but doesn't handle case when cnt was just decremented]
            flag = 0;
        }
    }
    for(int i = 1; i <= cnt; i++) // @@ [sorting and printing start from index 1, skipping potential valid data at index 0; also bubble sort inefficient but not incorrect per se]
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
    for(int i = 1; i <= cnt; i++) // @@ [output starts from index 1, so if any word ended up in word[0], it would be omitted]
    {
        printf("%s %d\n", word[i].w, word[i].count);
    }
    return 0;
}