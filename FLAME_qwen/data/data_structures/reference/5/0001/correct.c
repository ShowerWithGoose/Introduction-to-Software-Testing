#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int coe;
    int ind;
    struct Node *next;
} node, *nodeptr;

int a[2][100010][2];
int cnt1, cnt2;
int getnum(char s[], int f)
{
    int len = strlen(s);
    int tmp = 0, cnt = 0;
    for(int i = 0; i < len; i++)
    {
        //printf("%c\n", s[i]);
        if(s[i] == ' ' || s[i] == '\r' || s[i] == '\n')
        {
            a[f][cnt / 2][cnt % 2] = tmp;
            tmp = 0;
            cnt++;
            if(s[i] == '\r' || s[i] == '\n') break;
            continue;
        }
        tmp = tmp * 10 + s[i] - '0';
    }
    return cnt / 2;
}
nodeptr head = NULL;
int len = 0;
void insertNode(nodeptr q)
{
    nodeptr r, p;
    for(p = head; p != NULL; r = p, p = p->next)
    {
        if(p->ind == q->ind)
        {
            p->coe += q->coe;
            free(q);
            break;
        }
        else if(p->ind < q->ind)
        {
            if(p == head)
            {
                q->next = p;
                head = q;
            }
            else
            {
                r->next = q;
                q->next = p;
            }
            break;
        }
        else if(p->ind > q->ind && p->next == NULL)
        {
            p->next = q;
            break;
        }
    }
    return;
}
void ans()
{
    nodeptr p;
    for(p = head; p != NULL; p = p->next)
    {
        printf("%d %d ", p->coe, p->ind);
    }
    printf("\n");
}
int main()
{
    
    char s1[1000010], s2[1000010];
    fgets(s1, 1000010, stdin);
    fgets(s2, 1000010, stdin);
    cnt1 = getnum(s1, 0);
    cnt2 = getnum(s2, 1);
    /*for(int i = 0; i < cnt1; i++){
        printf("%d %d ", a[0][i][0], a[0][i][1]);
    }
    printf("\n");*/
    for(int i = 0; i < cnt1; i++)
    {
        for(int j = 0; j < cnt2; j++)
        {
            nodeptr p;
            p = (nodeptr)malloc(sizeof(node));
            p->coe = a[0][i][0] * a[1][j][0];
            p->ind = a[0][i][1] + a[1][j][1];
            p->next = NULL;
            //printf("%d %d\n", p->coe, p->ind);
            if(len == 0)
            {
                len++;
                head = p;
            }
            else
            {
                insertNode(p);
            }
        }
    }
    ans();
    return 0;
}


