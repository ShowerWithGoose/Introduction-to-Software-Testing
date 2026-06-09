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
        i = Cmp(p, s_, n); // @@ Error: Cmp is not declared before use; implicit function declaration may cause compilation error or undefined behavior
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
    for (int i = 0; i < n + 1; i++)
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
    while (q->next != p)
    {
        q = q->next;
    }
    return q;
}

int main()
{
    FILE* in = fopen("article.txt", "r"); // @@ Error: no check if fopen returns NULL; could cause segmentation fault if file not found
    int t = 0, flag = 0, same = 0; // 'same' is unused
    char c, words[MAX_LETTER] = { 0 }; // @@ Error: 'c' should be int to correctly store EOF returned by fgetc; using char may cause infinite loop if char is unsigned
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
                        p->next = result.isbe; // @@ Error: 'p' is uninitialized (set to NULL earlier and not reassigned); should be 'head = q' with proper linking
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
    // @@ Error: Missing processing of last word if file ends without a trailing non-alpha character (e.g., end of file directly after a word)

    p = head;
    while (p)
    {
        printf("%s %d\n", p->s, p->num); // @@ Error: infinite loop because p is never updated; missing 'p = p->next;' inside the loop
    }

    fclose(in);

    return 0;
}