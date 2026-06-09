#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct edge{
    int num;
    struct edge *next;
}Node;
typedef struct edge *Linklist;
Linklist v[110];
int visit[110] = {0};
int n, m, x;
struct
{
    int a;
    int b;
}input[5000], temp;

void DFS(int now)
{
    if (visit[now]==0)
        printf(" %d", now);
    visit[now] = 1;
    Linklist p = v[now];
    while (p) {
        if (visit[p->num]==0)
            DFS(p->num);
        p = p->next;
    }
}

//
int line[110];
int first = 1;
int behind = 0;
void putin(int a)
{
    behind++;
    line[behind] = a;
}

int outin(void)
{
    first++;
    return line[first-1];
}
int empty(void)
{
    if (first>behind)
        return 1;
    else
        return 0;
}

void BFS(int now)
{
    if (visit[now]==0)
        printf(" %d", now);
    putin(now);
    while (empty()==0) {
        now = outin();
        Linklist p = v[now];
        while (p!=NULL) {
            if (visit[p->num]==0) {
                printf(" %d", p->num);
                putin(p->num);
                visit[p->num] = 1;
            }
            p = p->next;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    int i, j;
    for (i=1; i<=m; i++) {
        scanf("%d %d", &input[i].a, &input[i].b);
        if (input[i].a>input[i].b) {
            int t = input[i].a;
            input[i].a = input[i].b;
            input[i].b = t;
        }
    }
    for (i=1; i<=m; i++) {
        for (j=1; j<=m-i; j++) {
            if (input[j].a>input[j+1].a || (input[j].a==input[j+1].a && input[j].b>input[j+1].b)) {
                temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }
    }
    scanf("%d", &x);
    for (i=0; i<=100; i++)
        v[i] = NULL;
    
    for (i=1; i<=m; i++) {
        int a, b;
        a = input[i].a;
        b = input[i].b;
        if (v[a]==NULL) {
            v[a] = (Linklist)malloc(sizeof(Node));
            v[a]->num = b;
            v[a]->next = NULL;
        } else {
            Linklist p = v[a];
            while ((p->next)!=NULL)
                p = p->next;
            Linklist q = (Linklist)malloc(sizeof(Node));
            q->num = b;
            q->next = NULL;
            p->next = q;
        }
        a = input[i].b;
        b = input[i].a;
        if (v[a]==NULL) {
            v[a] = (Linklist)malloc(sizeof(Node));
            v[a]->num = b;
            v[a]->next = NULL;
        } else {
            Linklist p = v[a];
            while ((p->next)!=NULL)
                p = p->next;
            Linklist q = (Linklist)malloc(sizeof(Node));
            q->num = b;
            q->next = NULL;
            p->next = q;
        }
        
    }
    //  1
    for (i=0; i<n; i++)
        visit[i] = 0;
    visit[0] = 2;
    printf("0");
    for (i=0; i<n; i++) {
        if (visit[i]!=1)
            DFS(i);
    }
    printf("\n");
    
    //2
    for (i=0; i<n; i++)
        visit[i] = 0;
    visit[0] = 2;
    printf("0");
    for (i=0; i<n; i++) {
        if (visit[i]!=1)
            BFS(i);
    }
    printf("\n");
    
    // 3
    for (i=0; i<n; i++)
        visit[i] = 0;

    visit[0] = 2;
    visit[x] = 1;
    printf("0");
    for (i=0; i<n; i++) {
        if (visit[i]!=1)
            DFS(i);
    }
    printf("\n");
    
    //2
    for (i=0; i<n; i++)
        visit[i] = 0;

    visit[0] = 2;
    visit[x] = 1;
    printf("0");
    
    for (i=0; i<n; i++) {
        if (visit[i]!=1)
            BFS(i);
    }
    printf("\n");
    return 0;
}















