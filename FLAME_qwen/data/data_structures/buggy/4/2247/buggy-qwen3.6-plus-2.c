#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct word
{
    char str[200];
    int count;
};
char str1[10001];
char tmp[200];
struct word num[10001];
int cmp(const void *a, const void *b)
{
    return strcmp(((struct word*)a) -> str, ((struct word*)b) -> str);
}
int main()
{
    FILE *in;
    in = fopen("article.txt", "r");
    int j = 0, k = 0, flag = 0;
    while(fgets(str1, 1001, in) != NULL)
    {
        for(int i = 0; str1[i] != '\0'; i ++)
        {
            if(str1[i] <= 'z' && str1[i] >= 'a')
            {
                tmp[j] = str1[i];
                j++;
            }
            else if(str1[i] <= 'Z' && str1[i] >= 'A')
            {
                tmp[j] = str1[i] - 'A' + 'a';
                j++;
            }
            else if(str1[i] == ' ') // @@ Only spaces are treated as word delimiters. Punctuation and other non-alphabetic characters should also terminate words. This condition should be changed to handle all non-alphabetic characters, and should check if j > 0 to avoid processing empty strings.
            {
                for(int p = 0; num[p].str[0] != '\0'; p ++)
                {
                    if(strcmp(tmp,num[p].str) == 0)
                    {
                        flag = 1;
                        num[p].count++;
                        break;
                    }
                }
                if(flag == 0)
                {
                    strcpy(num[k].str,tmp);
                    num[k].count = 1;
                    k ++;
                }    
                j = 0;
                memset(tmp, 0, sizeof(tmp));
                flag = 0;
            }
            else // @@ This block is empty, so non-space non-alphabetic characters do not trigger word termination, causing words separated by punctuation to be incorrectly concatenated.
            {
                
            }
        }
        if(tmp[0] != '\0') // @@ This handles end-of-line words but duplicates logic and lacks a check for j > 0. Word termination should be handled uniformly for all non-alphabetic characters.
        {
            for(int p = 0; num[p].str[0] != '\0'; p ++)
                {
                    if(strcmp(tmp,num[p].str) == 0)
                    {
                        flag = 1;
                        num[p].count++;
                        break;
                    }
                }
                if(flag == 0)
                {
                    strcpy(num[k].str,tmp);
                    num[k].count = 1;
                    k ++;
                }    
                j = 0;
                memset(tmp, 0, sizeof(tmp));
                flag = 0;
        }
    }
    qsort(num, k, sizeof(num[0]), cmp);
    for(int i = 0;num[i].str[0] != '\0'; i ++) // @@ The loop should iterate exactly k times (i < k) to output the counted words. Relying on str[0] != '\0' may cause incorrect output if empty strings are stored.
    {
        printf("%s %d\n", num[i].str, num[i].count);
    }
    fclose(in);
    return 0;
}