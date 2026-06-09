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
    in = fopen("article.txt", "r"); // @@ [If the file "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent operations on 'in' will cause undefined behavior (e.g., segmentation fault). The program does not check if 'in' is NULL before using it.]
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
            else if(str1[i] == ' ')
            {
                for(int p = 0; num[p].str[0] != '\0'; p ++) // @@ [This loop assumes that all entries from num[0] to num[k-1] are valid and non-empty, but if a word was previously added and then overwritten or corrupted, this may skip valid entries or access uninitialized memory. Also, it stops at the first empty string, which may occur before index k if words were inserted non-contiguously (though current logic inserts contiguously). However, more critically: if tmp is empty (j==0), it still tries to process it as a word.]
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
                    strcpy(num[k].str,tmp); // @@ [If tmp is empty (i.e., j==0, so tmp[0]=='\0'), this copies an empty string into num[k].str. Later, during sorting and printing, empty strings may be output or interfere with lexicographical order. Also, the problem defines a word as a sequence of letters — empty string is not a word and should not be counted.]
                    num[k].count = 1;
                    k ++;
                }    
                j = 0;
                memset(tmp, 0, sizeof(tmp));
                flag = 0;
            }
            else
            {
                
            }
        }
        if(tmp[0] != '\0')
        {
            for(int p = 0; num[p].str[0] != '\0'; p ++) // @@ [Same issue as above: relies on contiguous non-empty entries and may miss matches if an earlier entry is empty due to prior insertion of empty string. Also, if k is large, this loop could go beyond initialized entries if some num[p].str[0] happens to be '\0' before p reaches k.]
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
    for(int i = 0;num[i].str[0] != '\0'; i ++) // @@ [This loop stops at the first entry where str[0] is '\0', but after sorting with qsort, empty strings (if any were inserted) may appear at the beginning (since '\0' is smallest lexicographically), causing the loop to terminate immediately and skip all real words. Also, if no empty strings were inserted, but k > 0, it may still work — but if an empty string was inserted (e.g., due to consecutive delimiters), output will be incomplete. Moreover, the loop condition should be i < k, not checking for empty string, because qsort sorted only the first k elements, and all of them should be valid (but aren't, due to possible empty string insertion).]
    {
        printf("%s %d\n", num[i].str, num[i].count);
    }
    fclose(in);
    return 0;
}