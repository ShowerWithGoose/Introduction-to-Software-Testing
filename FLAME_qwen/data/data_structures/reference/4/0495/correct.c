#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct _wordCountGroup
{
    char* str;
    int cnt;
}
WordCount;
void count_word(WordCount**, char*);

int sort_wc(const void*, const void*);

int main()
{
    FILE *fp;
    fp = fopen("article.txt", "r");

    char ch_inp;
    char str_inp[999], *ptr_inp;
    int inputing_word;

    WordCount* word_counts[9999] = {NULL};
    WordCount** ptr_wc;
    int word_counts_len;

    inputing_word = 0;
    while (~fscanf(fp, "%c", &ch_inp))
    {
        if (isalpha(ch_inp))
        {
            if (inputing_word)
            {
                ptr_inp++;
                *ptr_inp = tolower(ch_inp);
            }
            else
            {
                inputing_word = 1;
                ptr_inp = str_inp;
                *ptr_inp = tolower(ch_inp);
            }
        }
        else
        {
            if (inputing_word)
            {
                inputing_word = 0;
                ptr_inp++;
                *ptr_inp = '\0';
                count_word(word_counts, str_inp);
            }
        }
    }

    word_counts_len = 0;
    for (ptr_wc = word_counts; *ptr_wc; ptr_wc++)
    {
        word_counts_len++;
    }
    qsort(word_counts, word_counts_len, sizeof(WordCount*), sort_wc);
    
    for (ptr_wc = word_counts; *ptr_wc; ptr_wc++)
    {
        printf("%s %d\n", (*ptr_wc)->str, (*ptr_wc)->cnt);
    }

    fclose(fp);
    return 0;
}

void count_word(WordCount** arr, char* str)
{
    for (; *arr; arr++)
    {
        if (!strcmp((*arr)->str, str))
        {
            (*arr)->cnt++;
            return;
        }
    }
    (*arr) = (WordCount*)malloc(sizeof(WordCount));
    (*arr)->str = (char*)malloc(sizeof(char) * (strlen(str) + 1));
    strcpy((*arr)->str, str);
    (*arr)->cnt = 1;
}

#define WCPTR(p) (*(WordCount**)p)
int sort_wc(const void* p1, const void* p2)
{
//    if (WCPTR(p1)->cnt > WCPTR(p2)->cnt)
//    {
//        return +1;
//    }
//    if (WCPTR(p1)->cnt < WCPTR(p2)->cnt)
//    {
//        return -1;
//    }
    return strcmp(WCPTR(p1)->str, WCPTR(p2)->str);
}

