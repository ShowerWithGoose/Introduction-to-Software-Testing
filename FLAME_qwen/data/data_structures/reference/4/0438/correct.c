#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct word
{
    char *word;
    int cnt;
    struct word * next;
} Word;

void insertWord(Word * head, char word[]);
char * splitWord(char line[], int start, int len);

int main()
{
    FILE * in;
    in = fopen("article.txt", "r");
    char getLine[500];
    Word * head = malloc(sizeof(Word));
    head->next = NULL;
    while (fgets(getLine, 500, in) != NULL)
    {
        int lineLen = strlen(getLine);
        for (int i = 0; i < lineLen; i++)
        {
            if (isalpha(getLine[i]))
            {
                int last = i+1;
                while (last < lineLen && isalpha(getLine[last]))
                {
                    last++;
                }
                insertWord(head, splitWord(getLine, i, last-i));
                i = last;
            }
        }
    }
    
    Word * p = head->next;
    while (p != NULL)
    {
        printf("%s %d\n", p->word, p->cnt);
        p = p->next;
    }
    // system("pause");
    return 0;
}

char * splitWord(char line[], int start, int len)
{
    char * rt = malloc(sizeof(char)*(len+1));
    for (int i = 0; i < len; i++)
    {
        rt[i] = tolower(line[start+i]);
    }
    rt[len] = '\0';

    return rt;
}

void insertWord(Word * head, char word[])
{
    Word * pre = head;
    Word * p =  head->next;

    while (p != NULL && strcmp(word, p->word) > 0)
    {
        pre = p;
        p = p->next;
    }

    if (p == NULL)
    {
        pre->next = malloc(sizeof(Word));
        p = pre->next;
        p->cnt = 1;
        p->word = word;
        p->next = NULL;
    }
    else
    {
        if (strcmp(word, p->word) == 0)
        {
            p->cnt++;
        }
        else
        {
            pre->next = malloc(sizeof(Word));
            pre = pre->next;
            pre->word = word;
            pre->cnt = 1;
            pre->next = p;
        }
    }
}
