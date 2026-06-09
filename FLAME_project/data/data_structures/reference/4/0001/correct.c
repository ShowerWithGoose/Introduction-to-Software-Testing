#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXW 110

struct Word{
    char w[MAXW];
    int cnt;
    struct Word *next;
};
typedef struct Word node;
typedef struct Word *nodeptr;
nodeptr head = NULL;
int getWord(char s[], FILE *fp)
{
    int i = 0;
    int c;
    while(!isalpha(c = fgetc(fp)))
    {
        //printf("%c\n", c);
        if(c == EOF) return c;
        else continue;
    }
    s[i++] = tolower(c);
    while((c = fgetc(fp)) != EOF)
    {
        //printf("%c\n", c);
        if(!isalpha(c))
            break;
        s[i++] = tolower(c);
    }
    s[i] = '\0';
    return 1;
}
void insert(char s[], nodeptr r)
{
    nodeptr q = (nodeptr)malloc(sizeof(node));
    strcpy(q->w, s);
    q->cnt = 1;
    q->next = NULL;
    if(r == NULL)
    {
        q->next = head;
        head = q;
    }
    else
    {
        q->next = r->next;
        r->next = q;
    }
}
void search(char s[])
{
    nodeptr p, r = NULL;
    if(head == NULL)
    {
        p = (nodeptr)malloc(sizeof(node));
        strcpy(p->w, s);
        p->next = NULL;
        p->cnt = 1;
        head = p;
        return;
    }
    for(p = head; p != NULL; r = p, p = p->next)
    {
        if(strcmp(s, p->w) == 0)
        {
            p->cnt++;
            return;
        }
        else if(strcmp(s, p->w) < 0)
        {
            break;
        }
    }
    insert(s, r);
}
void ans()
{
    nodeptr p;
    for(p = head; p != NULL; p = p->next)
    {
        printf("%s %d\n", p->w, p->cnt);
    }
}
int main()
{
    FILE *in;
    if((in = fopen("article.txt", "r")) == NULL)
    {
        puts("error in");
        return 1;
    }
    char s[MAXW];
    while(getWord(s, in) != EOF)
    {
        //printf("%s\n", s);
        search(s);
    }
    ans();
    fclose(in);
    return 0;
}


