#include <stdio.h>
#include <stdlib.h>

typedef struct pol
{
    int a;
    int power;
    struct pol *link;
} POL;
int main()
{
    POL *lista=NULL,*listb=NULL;
    POL *p=NULL,*q=NULL;
    POL *listc=NULL,*r=NULL;
    char c;
    lista=(POL *)malloc(sizeof(POL)); // @@ [Potential dereference of uninitialized pointer if malloc fails, but more critically: the program assumes at least one term exists in each polynomial; however, the problem allows zero terms (empty polynomial), which would cause undefined behavior. But the immediate bug is below.]
    listb=(POL *)malloc(sizeof(POL)); // @@ [Same issue as above, but not the primary error causing wrong output.]
    listc=(POL *)malloc(sizeof(POL)); // @@ [This pre-allocates the result list head even before knowing if there's any term, and later logic mishandles merging/sorting. However, the critical flaw is in input reading and multiplication logic.]
    p=lista;
    q=listb;
    r=listc;
    p->link=NULL;
    q->link=NULL;
    r->link=NULL;
    scanf("%d%d",&p->a,&p->power); // @@ [If the first polynomial is empty (no terms), this scanf will fail or read garbage, but problem states only non-zero terms are given, so at least one term expected. However, the real issue is that getchar() after scanf leaves newline unhandled properly across platforms.]
    while((c=getchar())!='\n') // @@ [This loop condition assumes that after each pair, a non-newline character is present to continue. However, if the input line has trailing space or multiple spaces, getchar() may consume space and not stop at '\n' correctly. Also, if the input ends immediately after last number, the '\n' might have already been consumed by scanf, leading to undefined behavior (c could be EOF or leftover). This can cause infinite loop or incorrect parsing.]
    {
        p->link=(POL *)malloc(sizeof(POL));
        p=p->link;
        scanf("%d%d",&p->a,&p->power);
        p->link=NULL;
    }
    p=lista;
    scanf("%d%d",&q->a,&q->power); // @@ [Same issue as first scanf: assumes second polynomial has at least one term, which is valid per problem, but input reading is fragile.]
    while((c=getchar())!='\n') // @@ [Same critical flaw as previous getchar() loop: may not correctly detect end of line due to buffering and leftover characters, leading to incorrect parsing of second polynomial or infinite loop.]
    {
        q->link=(POL *)malloc(sizeof(POL));
        q=q->link;
        scanf("%d%d",&q->a,&q->power);
        q->link=NULL;
    }
    q=listb;
    int jud=0;
    while(p!=NULL)
    {
        while(q!=NULL)
        {
            if(jud==0)
            {
                r->a=p->a*q->a;
                r->power=p->power+q->power;
                jud=1;
            }
            else
            {
                r->link=(POL *)malloc(sizeof(POL));
                r=r->link;
                r->a=p->a*q->a;
                r->power=p->power+q->power;
                r->link=NULL;
            }
            q=q->link;
        }
        p=p->link;
        q=listb;
    }
    r=listc;
    p=listc;
    q=listc;
    while(r->link!=NULL) // @@ [This loop prints intermediate unsorted/uncombined terms with newline, which violates output format (should be single line, space-separated, no extra newlines). Also, it prints before combining like terms!]
    {
        printf("%d %d\n",r->a,r->power);
        r=r->link;
    }
    while(r!=listc) // @@ [This sorting/combining loop has flawed logic: 'r' was set to last node from previous loop, but condition 'r!=listc' may never hold if listc has only one node. Also, bubble sort implementation is incorrect for linked list and doesn't handle all cases of combining like terms. Specifically, it only checks adjacent nodes during sort, but like terms may not be adjacent initially.]
    {
        q=listc;
        p=listc->link;
        jud=0;
        while(p!=r)
        {
            if(p->power<(p->link)->power)
            {
                q->link=p->link;
                p->link=(q->link)->link;
                (q->link)->link=p;
                q=q->link;
                jud=1;
            }
            else if(p->power==(p->link)->power)
            {
                (p->link)->a+=p->a;
                q->link=p->link;
                free(p);
                p=q->link;
            }
            else
            {
                p=p->link;
                q=q->link;
            }
        }
        if(jud==0)
        {
            break;
        }
        r=q;
    }
    r=listc;
    while(r!=NULL)

    {
        printf("%d %d ",r->a,r->power); // @@ [Prints final result, but due to earlier flawed combination and sorting, like terms may not be merged, and order may be incorrect. Also, if a coefficient becomes zero after combination, it should be omitted, but program doesn't check for that.]
        r=r->link;
    }
    return 0;
}