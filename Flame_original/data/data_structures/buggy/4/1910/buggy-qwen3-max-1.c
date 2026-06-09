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
        i = Cmp(p, s_, n); // @@ [Function 'Cmp' is used before it is declared. In C, functions must be declared or defined before use unless using implicit declaration (which is invalid in modern standards). This causes a compilation error.]
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
    for (int i = 0; i < n + 1; i++) // @@ [Loop runs up to index 'n', but 's_' has valid characters only from 0 to n-1 (since length is 'n'). Also, 'p->s' may not be null-terminated beyond its actual length, leading to undefined behavior. Moreover, comparing beyond the string length can cause incorrect lexicographical comparison.]
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
    while (q->next != p) // @@ [If 'p' is not in the list or is the first node, this loop may never terminate or cause undefined behavior by dereferencing null pointers. Specifically, when 'p == head', 'q->next != p' becomes 'head->next != head', which is true, and the loop continues until q->next is null, then accessing q->next again leads to crash.]
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

    while ((c = fgetc(in)) != EOF) // @@ [Variable 'c' is declared as 'char', but 'fgetc' returns 'int'. When EOF (typically -1) is returned, storing it in a 'char' may convert it to a positive value (if char is unsigned), causing the loop to never terminate. This is a classic bug that leads to infinite loops or incorrect behavior, but more critically, if the file fails to open (in == NULL), this causes undefined behavior by dereferencing NULL. However, the immediate compilation issue is not here, but the missing check for 'in == NULL' is a runtime error. The primary compilation error is the undeclared function 'Cmp'.]
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
                        p->next = result.isbe; // @@ ['p' is uninitialized in this branch. If 'result.isbe == head', 'p' has not been assigned any value, leading to undefined behavior when dereferenced. This is a runtime error, not compilation.]
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