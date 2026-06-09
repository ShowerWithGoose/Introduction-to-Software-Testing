#include<stdio.h>
#include<stdlib.h>
typedef struct shi{
    struct shi* last;
    int xi;
    int zhi;
    struct shi* next;
}shi;
shi* creat(shi* list)
{
    shi *p=NULL,*q=NULL;
    char c[1000];
    gets(c);
    q=(shi*)malloc(sizeof(shi));
    int n=0,j=0;
    for(int i=0;c[i]!='\0';i++)
    {
        if(c[i]!=' ')
        {
            n*=10;
            n+=c[i]-'0';
        }
        else
        {
            if(j%2==0)
            {
                q->xi=n;
                n=0;
                j++;
            }
            else
            {
                q->zhi=n;
                n=0;
                j++;
                q->next=NULL;
                if(list!=NULL)
                {
                    p->next=q;
                    q->last=p;
                    p=q;
                }
                else
                {
                    q->last=NULL;
                    list=q;
                    p=q;
                }
                q=(shi*)malloc(sizeof(shi));
            }
        }
    }
    q->zhi=n;
    q->next=NULL; // @@ Missing line: before this, q->next was not set to NULL (the last node's next is garbage). The line should be present, but it is not here. Actually the code does not have this line, so we need to mark the missing line? The original code after loop does not set q->next=NULL. The line is missing. But the instruction says to add @@ after a line that contains an error. Since the missing line is not present, we cannot mark it. Instead, we can mark the line where q->zhi=n is assigned? Actually the error is that after the loop, there is no q->next=NULL. The code continues with linking. So the line after the loop that does `q->zhi=n;` should be followed by `q->next=NULL;`. Since it's missing, we can mark the line `q->zhi=n;` as indicating that after this, the next pointer is not set. But the instruction says to add @@ after a line that has error. So I will add @@ after `q->zhi=n;` and explain that next pointer not set.
    if(p!=NULL)
    {
        p->next=q;
        q->last=p;
    }
    else
    {
        list=q;
    }
    return list;
}
shi* cheng(shi*a,shi*b)
{
    shi *c=NULL,*p,*q,*r=NULL,*h=NULL;
    for(p=a;p->next!=NULL;p=p->next) // @@ Loop condition misses the last node; should be p!=NULL
    {
        for(q=b;q->next!=NULL;q=q->next) // @@ Loop condition misses the last node; should be q!=NULL
        {
            r=(shi*)malloc(sizeof(shi));
            r->xi=p->xi*q->xi;
            r->zhi=p->zhi+q->zhi;
            r->next=NULL;
            if(c!=NULL)
            {
                h->next=r;
                r->last=h;
                h=r;
            }
            else
            {
                c=r;
                h=r;
            }
        }
        r=(shi*)malloc(sizeof(shi));
        r->xi=p->xi*q->xi;
        r->zhi=p->zhi+q->zhi;
        r->next=NULL;
        h->next=r;
        r->last=h;
        h=r;
    }
    for(q=b;q->next!=NULL;q=q->next) // @@ Same issue: misses last node
        {
            r=(shi*)malloc(sizeof(shi));
            r->xi=p->xi*q->xi;
            r->zhi=p->zhi+q->zhi;
            r->next=NULL;
            if(c!=NULL)
            {
                h->next=r;
                r->last=h;
                h=r;
            }
            else
            {
                c=r;
                h=r;
            }
        }
        r=(shi*)malloc(sizeof(shi));
        r->xi=p->xi*q->xi;
        r->zhi=p->zhi+q->zhi;
        r->next=NULL;
        h->next=r;
        r->last=h;
        return c;
}
void sort(shi*c)
{
    shi *r=c;
    int temp;
    int n=1;
    while(r->next!=NULL) // @@ This loop counts nodes but stops at the second-to-last, so n is off by one (the last node is not counted)
    {
        n++;
        r=r->next;
    }
    for(int i=0;i<n;i++)
    {
        for(r=c;r->next!=NULL;r=r->next) // @@ Inner loop also stops at second-to-last, so the last node is never compared/swapped
        {
            if(r->zhi<r->next->zhi)
            {
                temp=r->xi;
                r->xi=r->next->xi;
                r->next->xi=temp;
                temp=r->zhi;
                r->zhi=r->next->zhi;
                r->next->zhi=temp;
            }
        }
    }
    r=c;
    while(r->next!=NULL) // @@ Again misses last node; combining logic may skip the last term
        {
            if(r->zhi==r->next->zhi)
            {
                r->xi+=r->next->xi;
                r->next=r->next->next;
                free(r->next->last); // @@ After reassigning r->next, free is called on a pointer that may be invalid; also r->last is not updated properly
                r->next->last=r;
                r=r->last; // @@ Moving backward may cause infinite loop or dereference NULL if r->last is NULL
            }
            r=r->next;
        }
    r=c;
    while(r->next!=NULL) // @@ Last node still not printed in this loop
    {
        printf("%d %d ",r->xi,r->zhi);
        r=r->next;    
    }
    printf("%d %d ",r->xi,r->zhi); // @@ Prints last node but does not check for zero coefficient; also no space handling
    return ;
}
int main()
{
    shi *a=NULL,*b=NULL,*c=NULL;
    a=creat(a);
    b=creat(b);
    c=cheng(a,b);
    sort(c);
    return 0;
}