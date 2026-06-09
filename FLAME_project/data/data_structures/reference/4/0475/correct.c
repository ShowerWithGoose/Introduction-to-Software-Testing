#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
struct wf
{
    char word[100];
    int time;
    struct wf *next;
    struct wf *previous;
};
struct wf *first;
int n = 0;
int getin(char *, FILE *);   //读入字母字符串
void process(char *);  //词频处理
int main()
{
    char read[100];
    struct wf *p;
    FILE *in;
    in = fopen("article.txt", "r");
    while (getin(read, in) == 1)
    {
        if (n == 0)
        {
            p = (struct wf *)malloc(sizeof(struct wf));
            // p->word = read;
            strcpy(p->word, read);
            p->time = 1;
            p->next = NULL;
            p->previous = NULL;
            first = p;
            n++;
        }
        else
        {
            process(read);
        }
    }
    p = first;
    while (p != NULL)
    {
        printf("%s %d\n", p->word, p->time);
        p = p->next;
    }
    fclose(in);
    return 0;
}
void process(char *read)
{
    struct wf *temp = first, *p;
    while (1)
    {
        if (strcmp(temp->word, read) > 0) //已有的数据按字典顺序排，从上到下找，遇到比起小的直接插入
        {
            p = (struct wf *)malloc(sizeof(struct wf));
            strcpy(p->word, read);
            n++;
            p->time = 1;
            if (temp == first)
            {
                p->next = temp;
                p->previous = NULL;
                temp->previous = p;
                first = p;
            }
            else
            {
                p->next = temp;
                p->previous = temp->previous;
                temp->previous = p;
                p->previous->next = p;
            }
            break;
        }
        else if (strcmp(temp->word, read) == 0)
        {
            temp->time++;
            break;
        }
        if ((temp->next) == NULL)
        {
            p = (struct wf *)malloc(sizeof(struct wf));
            strcpy(p->word, read);
            n++;
            p->time = 1;
            p->previous = temp;
            p->next = NULL;
            temp->next = p;
            break;
        }
        temp = temp->next;
    }
}
int getin(char *read, FILE *in)
{
    int i = 0;
    char a;
    memset(read, '\0', 100);
    while (isalpha(a = fgetc(in)) == 0)
    {
        if (a == EOF)
        {
            return 0;
        }
    }
    while (isalpha(a) != 0)
    {
        *(read + i) = tolower(a);
        a = fgetc(in);
        i++;
    }
    return 1;
}

