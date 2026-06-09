#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxn 10000

struct node
{
    long long x;
    long long a;
    struct node *nxt, *pre; 
};

struct node *hans, *eans;
struct node *ha, *hb, *ea, *eb;

char buf[maxn];
int l;

void init()
{
    memset(buf, 0, sizeof(buf));
    l = 0;
    return ;
}

void withdraw()
{
    --l;
    return;
}

char cget()
{
    return buf[l++];
}

long long llget()
{
    char c = cget();
    while(!isdigit(c))
    {
        if(c == '\n' || c == '\0' || c == '0') return 0;
        c = cget();
    }
    withdraw();
    long long res = 0;
    while(isdigit(c = cget()))
        res = (res << 3) + (res << 1) + c - '0';
    return res;
}

void read(struct node *h, struct node *e)
{
    init();
    gets(buf);
    struct node *p, *pre = h;
    long t1 = llget(), t2 = llget();
    while (t2 != 0 || t1 != 0)
    {
        p = malloc(sizeof(struct node));
        p->a = t1;
        p->x = t2;
        p->pre = pre;
        pre->nxt = p;
        pre = p;
        t1 = llget(), t2 = llget();
    }
    p->nxt = e;
    return ;
}

void insert(struct node *h, struct node *e, struct node *p)
{
    struct node *i;
    int f = 0;
    for(i = h; i != NULL; i = i->nxt)
    {
        if(i->x == p->x) f = 1;
        if(i->x < p->x) f = 2;
        if(f) break;
    }
    if(f == 1)
    {
        i->a += p->a;
        free(p);
    }
    if(f == 2)
    {
        i->pre->nxt = p;
        p->pre = i->pre;
        p->nxt = i;
        i->pre = p;
    }
    return ;
}

int main()
{
    #ifdef DBG
        freopen("in.txt", "r", stdin);
    #endif
    ha = malloc(sizeof(struct node)); ea = malloc(sizeof(struct node));
    hb = malloc(sizeof(struct node)); eb = malloc(sizeof(struct node));
    hans = malloc(sizeof(struct node)); eans = malloc(sizeof(struct node));
    ha->nxt = ea; ea->pre = ha; ha->x = 2147483647; ea->x = -1;
    hb->nxt = eb; eb->pre = hb; hb->x = 2147483647; eb->x = -1;
    hans->nxt = eans; eans->pre = hans; hans->x = 2147483647; eans->x = -1;
    read(ha, ea); read(hb, eb);
    hans->x = 2147483647; eans->x = -1;
    struct node *p;
    for(struct node *i = ha->nxt; i != ea; i = i->nxt)
    {
        for(struct node *j = hb->nxt; j != eb; j = j->nxt)
        {
            p = malloc(sizeof(struct node));
            p->x = i->x + j->x;
            p->a = i->a * j->a;
            insert(hans, eans, p);
        }
    }
    for(struct node *i = hans->nxt; i != eans; i = i->nxt)
        printf("%lld %lld ", i->a, i->x);
    for(struct node *i = hans->nxt, *pre = NULL; i != eans; pre = i, i = i->nxt)
        if(pre != NULL) free(pre);
    free(eans);
    return 0;
}
