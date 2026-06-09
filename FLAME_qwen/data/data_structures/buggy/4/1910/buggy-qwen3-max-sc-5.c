#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX_LETTER 55
#define ll long long
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

typedef struct node
{
    char s[MAX_LETTER];
    int num;
    struct node* next;
}NODE;

typedef struct code
{
    NODE* isbe;
    int issame;
}COMPARE;

NODE* Creatlist(char s_[], int n)
{
    NODE* q = (NODE*)malloc(sizeof(NODE));
    q->next = NULL; q->num = 1;
    int i = 0;
    for (; i < n; i++)
    {
        q->s[i] = s_[i];
    }
    q->s[i] = '\0';
    return q;
}

COMPARE Isfind(NODE* head, char s_[], int n)
{
    COMPARE a;
    a.isbe = NULL; a.issame = 0;
    NODE* p = head;
    int i = 0;
    while (p)
    {
        i = Cmp(p, s_, n); // @@ [Function 'Cmp' is used before it is declared/defined, causing a compilation error in strict C standards (like C90). In C99+, implicit declaration is not allowed, leading to compilation failure.]
        if (i > 0)
        {
            p = p->next;
        }
        else if (i < 0)
        {
            a.isbe = p;
            return a;
        }
        else
        {
            a.isbe = p;
            a.issame = 1;
            return a;
        }
    }
    return a;
}

int Cmp(NODE* p, char s_[], int n)
{
    for (int i = 0; i < n + 1; i++) // @@ [Loop runs up to 'n+1', which may access s_[n] and p->s[n]. Since the word length is 'n', valid indices are 0 to n-1, and s_[n] is '\0'. However, comparing beyond the actual string length can cause incorrect lexicographical comparison. Also, this may read uninitialized memory in p->s if p->s length < n+1. But more critically, the logic of comparison is flawed: standard lexicographic comparison should stop at first difference or at end of either string.]
    {
        if (p->s[i] < s_[i])
        {
            return 1;
        }
        else if(p->s[i] > s_[i])
        {
            return -1;
        }
    }
    return 0;
}

NODE* Tail(NODE* p)
{
    NODE* q = p;
    while (q->next)
    {
        q = q->next;
    }
    return q;
}

NODE* Front(NODE* head, NODE* p)
{
    NODE* q = head;
    while (q->next != p) // @@ [If 'p' is not in the list starting from 'head', this loop will run indefinitely or crash when q becomes NULL. This function assumes 'p' is always reachable from 'head', but there's no guarantee, especially during insertion logic.]
    {
        q = q->next;
    }
    return q;
}

int main()
{
    FILE* in = fopen("article.txt", "r");
    int t = 0, flag = 0, same = 0;
    char c, words[MAX_LETTER] = { 0 };
    NODE* head = NULL, * q = NULL, * p = NULL;
    COMPARE result;

    while ((c = fgetc(in)) != EOF) // @@ [Variable 'c' is declared as 'char', but fgetc returns 'int'. When EOF (typically -1) is returned, storing it in a 'char' may cause it to become a positive value (due to signed/unsigned char behavior), leading to infinite loop or missed EOF. This is a classic bug that causes undefined behavior or incorrect file reading.]
    {
        if (isalpha(c))
        {
            flag = 0;
            words[t++] = tolower(c);
        }
        else
        {
            flag++;
        }
        if (t!=0 && flag == 1)
        {
            words[t] = '\0';
            if (!head)
            {
                q = Creatlist(words, t);
                head = q;
            }
            else
            {
                result = Isfind(head, words, t);
                if (!result.isbe)
                {
                    q = Creatlist(words, t);
                    p = Tail(head);
                    p->next = q;
                }
                else if (result.issame)
                {
                    result.isbe->num++;
                }
                else
                {
                    q = Creatlist(words, t);
                    if (result.isbe == head)
                    {
                        p->next = result.isbe; // @@ [Here, 'p' is used uninitialized. In this branch, 'p' has not been assigned any value yet in this scope, leading to undefined behavior (using garbage pointer). This will likely crash or corrupt memory.]
                    }
                    else
                    {
                        p = Front(head, result.isbe);
                        q->next = p->next;
                        p->next = q;
                    }
                }
            }
            t = 0;
        }
    }

    p = head;
    while (p)
    {
        printf("%s %d\n", p->s, p->num);
    }

    fclose(in);

    return 0;
}