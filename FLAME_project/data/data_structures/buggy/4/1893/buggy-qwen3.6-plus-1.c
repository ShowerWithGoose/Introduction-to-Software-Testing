#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>


typedef struct NODE {
    char word[32];
    int num;
    struct NODE* next;
}NODE;
struct NODE* h;
int getWord(FILE*in,char* w)
{
    memset(w, 0, sizeof w); // @@ [sizeof w returns the size of the pointer (4 or 8 bytes), not the array size. Should be sizeof(char)*32 or just rely on manual null termination. However, the critical logic error is below.]
    int i = 0, flag = 0;
    char c;
    while ((c = fgetc(in)) != EOF)
    {
        if ((c>= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            if (c >= 'A' && c <= 'Z')
            {
                w[i] = c + 'a' - 'A';
                i++;
            }
            else if (c >= 'a' && c <= 'z')
            {
                w[i] = c;
                i++;
            }
            while ((c = fgetc(in)) != EOF)
            {
                if (c >= 'A' && c <= 'Z')
                {
                    w[i] = c + 'a' - 'A';
                    i++;
                }
                else if (c >= 'a' && c<= 'z')
                {
                    w[i] = c;
                    i++;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1)
            break;
    }
    if (i == 0)
        return -1;
    else
        return 0; // @@ [The function returns 0 on success and -1 on failure/EOF. The main loop checks for EOF (-1 typically, but here it's checking against EOF which is -1). If getWord returns 0, the loop continues. If it returns -1, the loop stops. This part is technically okay if main checks correctly, but see main.]
}
int insertWord(NODE* p, char* w)
{
    NODE* q = (NODE*)malloc(sizeof(NODE));
    if (q == NULL) 
        return -1;
    strcpy(q->word, w);
    q->num = 1;
    q->next = NULL;
    if (h == NULL)
        h = q;
    else if (p == NULL)//?
    {
        q->next = h;
        h = q;
    }
    else
    {
        q->next = p->next;
        p->next = q;
    }
    return 0;
}
int searchWord(char* w)
{
    NODE* p = NULL, * q = NULL;
    for (p = h; p != NULL; q = p, p = p->next)
    {
        if (strcmp(w, p->word) < 0)
            break;
        else if (strcmp(w, p->word) == 0)
        {
            p->num++;
            return 0;
        }
    }
    return insertWord(q, w);
}
char word[32],c[32];
int main()
{
    FILE* in;
    NODE* p;
    in = fopen("article.txt", "r");
    while (getWord(in,word)!= EOF) // @@ [getWord returns 0 on success and -1 on failure. EOF is usually -1. So this loop condition is effectively while(getWord(...) != -1). This is correct for stopping at EOF. However, the logic inside getWord is flawed because it doesn't reset 'flag' to 0 after processing a word, causing subsequent words to be truncated or missed if the previous iteration set flag=1. Also, the inner while loop consumes the non-alpha character but doesn't push it back, which is standard, but the 'flag' variable persists across outer loop iterations incorrectly.]
    {
        searchWord(word);
    }
    for (p = h; p != NULL; p = p->next)
    {
        printf("%s %d\n", p->word, p->num);
    }
    fclose(in);
    return 0;
}