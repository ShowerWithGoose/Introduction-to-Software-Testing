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
struct word num[10001]; // @@ Missing initialization of num array; entries contain garbage, causing later loops relying on str[0]=='\0' to behave unpredictably.
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
            else if(str1[i] == ' ') // @@ Only spaces treated as word separators; non‑letter characters (punctuation, digits, newline) should also separate words.
            {
                for(int p = 0; num[p].str[0] != '\0'; p ++) // @@ Assumes uninitialized num entries have str[0]=='\0', which is false.
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
                    strcpy(num[k].str,tmp); // @@ Copies empty string when tmp is empty (e.g., consecutive spaces), adding an empty word.
                    num[k].count = 1;
                    k ++;
                }    
                j = 0;
                memset(tmp, 0, sizeof(tmp));
                flag = 0;
            }
            else
            {
                // @@ Non‑letter characters are ignored instead of ending the current word; this merges words separated by punctuation/digits.
            }
        }
        if(tmp[0] != '\0')
        {
            for(int p = 0; num[p].str[0] != '\0'; p ++) // @@ Same uninitialized memory issue as above.
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
    for(int i = 0;num[i].str[0] != '\0'; i ++) // @@ Loop condition relies on uninitialized str[0] for entries beyond k; may print garbage or cause buffer over‑read.
    {
        printf("%s %d\n", num[i].str, num[i].count);
    }
    fclose(in);
    return 0;
}