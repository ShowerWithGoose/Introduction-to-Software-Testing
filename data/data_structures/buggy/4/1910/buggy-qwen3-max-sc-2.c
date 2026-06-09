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
        i = Cmp(p, s_, n); // @@ [The function 'Cmp' is used before it is declared or defined. In C, functions must be declared before use unless they are defined earlier. This causes a compilation error in strict C standards (like C89/C90).]
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
    for (int i = 0; i < n + 1; i++) // @@ [Loop runs up to index 'n', but 's_' has valid characters only from 0 to n-1 (since length is 'n'). Also, 'p->s' may not be null-terminated at index 'n' if its actual length is less than 'n'. This can cause out-of-bounds read and incorrect comparison. Additionally, comparing beyond the actual string length breaks lexicographical ordering logic.]
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
    while (q->next != p) // @@ [If 'p' is not in the list starting from 'head', this loop will eventually dereference a NULL pointer (when q becomes NULL), causing undefined behavior or crash. Also, if 'p == head', then 'q->next != p' is false initially, but the loop condition assumes 'p' is not head. However, in usage, 'Front' is called only when 'result.isbe != head', so this might be safe logically, but still risky without validation. However, this is not a compilation error. The main compilation issue is the undeclared function 'Cmp'.]
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

    while ((c = fgetc(in)) != EOF)
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
                        p->next = result.isbe; // @@ [Here, 'p' is used uninitialized. If 'head' exists and we enter this branch, 'p' was never assigned a value in this scope. This leads to undefined behavior (using uninitialized pointer), but this is a runtime/logic error, not a compilation error. The primary compilation error remains the undeclared 'Cmp' function.]
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