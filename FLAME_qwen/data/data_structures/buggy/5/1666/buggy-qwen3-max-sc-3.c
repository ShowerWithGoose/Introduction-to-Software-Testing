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
    lista=(POL *)malloc(sizeof(POL)); // @@ [Potential dereference of uninitialized pointer if malloc fails, but more critically: the program assumes at least one term exists in each polynomial; however, the real issue is that input reading logic does not handle empty lines or EOF correctly, and getchar() returns int, not char, leading to potential comparison issues with '\n'.]
    listb=(POL *)malloc(sizeof(POL)); // @@ [Same as above; also, if the input line is empty (no terms), this leads to undefined behavior.]
    listc=(POL *)malloc(sizeof(POL)); // @@ [Unnecessary initial allocation for result list; multiplication may produce zero terms if inputs are empty, but problem states non-zero terms only, so maybe acceptable—but logic later assumes listc always has at least one node.]
    p=lista;
    q=listb;
    r=listc;
    p->link=NULL;
    q->link=NULL;
    r->link=NULL;
    scanf("%d%d",&p->a,&p->power); // @@ [If first input line is empty (e.g., just newline), scanf fails, leaving p->a and p->power uninitialized, causing undefined behavior. Problem states "only non-zero terms appear", but doesn't guarantee at least one term. However, typical test cases have at least one term. Bigger issue: no check for scanf success.]
    while((c=getchar())!='\n') // @@ [c is declared as char, but getchar() returns int. If char is unsigned, EOF (which is -1) becomes 255, never equal to '\n', causing infinite loop. Also, after reading last number, there may be trailing space before newline; this loop condition may misbehave. Moreover, if input ends without newline (EOF), this loops forever or breaks incorrectly.]
    {
        p->link=(POL *)malloc(sizeof(POL));
        p=p->link;
        scanf("%d%d",&p->a,&p->power);
        p->link=NULL;
    }
    p=lista;
    scanf("%d%d",&q->a,&q->power); // @@ [Same issue as earlier scanf: no validation, assumes second polynomial has at least one term.]
    while((c=getchar())!='\n') // @@ [Same getchar() issue: c should be int to properly detect EOF and compare with '\n'. This can cause infinite loop or premature termination.]
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
    while(r->link!=NULL) // @@ [This prints intermediate unsorted/uncombined terms with newline, which violates output format (should be single line, space-separated). Also, if multiplication yields only one term, this loop doesn't print anything, then later full print happens—so duplicate or missing output possible.]
    {
        printf("%d %d\n",r->a,r->power);
        r=r->link;
    }
    while(r!=listc) // @@ [r was advanced to last node by previous loop; if listc has only one node, r == listc, so this loop never runs—meaning no combining/sorting occurs. Thus, like terms aren't merged, and output isn't sorted descending. Also, bubble sort logic is flawed: it tries to sort ascending? And handles merging during sort, but condition checks are incorrect (e.g., p->link may be NULL in comparisons).]
    {
        q=listc;
        p=listc->link;
        jud=0;
        while(p!=r)
        {
            if(p->power<(p->link)->power) // @@ [Accesses p->link->power without ensuring p->link != NULL. If p is last node, p->link is NULL → segmentation fault. Also, sorting direction seems wrong for descending output.]
            {
                q->link=p->link;
                p->link=(q->link)->link;
                (q->link)->link=p;
                q=q->link;
                jud=1;
            }
            else if(p->power==(p->link)->power) // @@ [Same NULL dereference risk. Also, when merging terms, it frees p but doesn't update all pointers correctly in all cases, possibly leaving dangling references.]
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
        printf("%d %d ",r->a,r->power);
        r=r->link;
    }
    return 0;
}