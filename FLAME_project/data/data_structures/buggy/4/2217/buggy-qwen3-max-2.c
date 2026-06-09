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
                cnt++; // @@ [cnt is incremented before the word is fully extracted and validated; this leads to using word[cnt] before it's properly initialized and causes off-by-one errors]
                int l1 = 0;
                while(isalpha(ch[i])) // @@ [This loop may go out of bounds if i reaches l without checking boundary; also, after incrementing i past the last character, ch[i] may be undefined]
                {
                    word[cnt].w[l1] = tolower(ch[i]);
                    l1++;
                    i++;
                }
                word[cnt].w[l1] = '\0'; // @@ [Missing null-termination of the extracted word string, leading to undefined behavior in strcmp later]
            }
            else
            {
                continue;
            }
            for(int j = 1; j <= cnt - 1; j++) // @@ [Loop starts from index 1, but valid words are stored starting from index 1 only if cnt was correctly managed; however, due to earlier off-by-one, this logic is flawed]
            {
                if(strcmp(word[j].w, word[cnt].w) == 0)
                {
                    word[j].count++;
                    cnt--; // @@ [Decrementing cnt here breaks the indexing for subsequent words and causes loss of the last added word's slot]
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                word[cnt].count = 1; // @@ [If a new word is added, it's placed at index cnt, but since cnt was pre-incremented, and array is 0-indexed, this skips index 0 and misaligns storage]
            flag = 0;
        }
    }
    for(int i = 1; i <= cnt; i++) // @@ [Sorting and printing start from index 1, but if any word was stored at index 0 (which shouldn't happen due to logic), it would be skipped; more critically, due to earlier errors, the word "to" might have been corrupted or misread as "tou"]
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
    for(int i = 1; i <= cnt; i++)
    {
        printf("%s %d\n", word[i].w, word[i].count);
    }
    return 0;
}