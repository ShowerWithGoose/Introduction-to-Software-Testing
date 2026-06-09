#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pol
{
    long long a,n;
    struct Pol *link;
};
struct Pol *s3 = NULL;
void print(struct Pol *sourse)
{
    while(sourse != NULL){
        if(sourse->a != 0)
            printf("%lld %lld ",sourse->a,sourse->n);
        sourse = sourse->link;
    }
    printf("\n");
    return;
}
void meg(struct Pol *s1)
{
    if(s3 == NULL){
        s3 = s1;
        return;
    }

    struct Pol *p = s1,*q = s3->link,*r = s3,*t;

    while(p != NULL && q != NULL){
        if(p->n > q->n){
            r->link = p;
            r = p;
            p = p->link;
        }
        else if(p->n < q->n){
            r->link = q;
            r = q;
            q = q->link;
        }
        else{
            p->a += q->a;
            r->link = p;
            r = p;
            p = p->link;
            t = q;
            q = q->link;
            free(t);
            t = NULL;
        }
    }
    if(p == NULL)
        r->link = q;
    else
        r->link = p;
}

void xuan(int A,int N,struct Pol *head)
{
    int i = 0;
    struct Pol *tem,*s = NULL,*t = head;

    while(t != NULL){
        struct Pol *p;
        p = (struct Pol *)malloc(sizeof(struct Pol));
        p->link = NULL;
        p->n = N + t->n;
        p->a = A * t->a;
        if(i == 0){
            s = p;
            tem = p;
            i++;
        }
        else{
            tem->link = p;
            tem = p;
        }
        t = t->link;
    }
    meg(s);

    return;
}

void addList(struct Pol **dest)
{
    int i = 0;
    struct Pol *tem;
    char c;

    while(1){
        struct Pol *p;
        p = (struct Pol *)malloc(sizeof(struct Pol));
        p->link = NULL;
        scanf("%lld%lld",&p->a,&p->n);
        if(i == 0){
            *dest = p;
            tem = p;
            i++;
        }
        else{
            tem->link = p;
            tem = p;
        }
        scanf("%c",&c);
        if(c == '\n')
            return;
    }
}
int main()
{
    struct Pol *s1= NULL,*s2 = NULL,*t;

    addList(&s1);
    addList(&s2);
    while(s1 != NULL){
        xuan(s1->a,s1->n,s2);
        s1 = s1->link;
    }
    print(s3);
    while(s3 != NULL){
        t = s3;
        s3 = s3->link;
        free(t);
        t = NULL;
    }

    return 0;
}

