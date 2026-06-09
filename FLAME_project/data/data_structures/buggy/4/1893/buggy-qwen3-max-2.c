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
    memset(w, 0, sizeof w); // @@ [sizeof w is size of pointer, not array; should be sizeof(char)*32 or strlen-based clearing]
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
        return 0; // @@ [Should return 1 on success to match loop condition in main expecting non-EOF; currently returns 0 which causes infinite loop or early exit]
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
    while (getWord(in,word)!= EOF) // @@ [getWord returns -1 or 0, never EOF; loop condition should check for != -1 instead]
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