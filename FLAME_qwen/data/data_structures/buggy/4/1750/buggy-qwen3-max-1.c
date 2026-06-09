#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
struct statistic
    {
        char w[50] ;
        int time;
        struct statistic *next;
    };
typedef struct statistic sta;
typedef struct statistic *stap;
int main()
{
    char tem[50],tp;
    int m=0,g=0,same=0;
    stap head=NULL,p,q,t;
    FILE *in;
    in=fopen("article.txt","r");
    
    
    
    while ((fscanf(in,"%c",&tp))!=EOF)
    {
        while (tp<'A'||tp>'z'||(tp<'a'&&tp>'Z')) // @@ [This condition incorrectly includes non-alphabetic characters between 'Z' and 'a' (like '[', '\', etc.) as valid separators, but also fails to properly detect alphabetic characters due to flawed logic. It should use isalpha() instead.]
        {
           if(fscanf(in,"%c",&tp)==EOF)
           {
            same=1;
            break;
           }
        }
        if (same==1)
        {
            break;
        }
        
        
        while ((tp>='A'&&tp<='Z')||(tp>='a'&&tp<='z'))
        {
            if (tp>='A'&&tp<='Z')
            {
                tp=tp+'a'-'A';
            }
            tem[m]=tp;
            m++;
            fscanf(in,"%c",&tp); // @@ [If fscanf reaches EOF here, tp becomes undefined, and the loop may continue with garbage data. Also, no check for buffer overflow (m >= 50).]
        }
        
        if (head==NULL)
        {
            p=(struct statistic *)malloc(sizeof(struct statistic));
            strcpy(p->w,tem);
            p->time=1;
            head=p;
            q=head;
            g++;
        }
        else
        {
            for (int i = 0; i < g-1; i++) // @@ [Loop runs only g-1 times, so it never checks the last node in the list when searching for duplicates.]
            {
                if(strcmp(q->w,tem)==0)
                {
                    q->time=1+q->time;
                    same=1;
                    break;
                }
                q=q->next;
            }
            if(strcmp(q->w,tem)==0&&same==0) // @@ [This only checks the last node if the loop above didn't find a match, but q may be NULL if g==0 or list traversal went too far. Also, if g==1, the for loop doesn't run, and this condition works, but logic is fragile.]
                {
                    q->time=1+q->time;
                    same=1;
                }
            if (same==0)
            {
                p->next=(struct statistic *)malloc(sizeof(struct statistic)); // @@ [p is uninitialized when head != NULL and same==0 on first insertion after head. This leads to writing to random memory.]
                p=p->next;
                p->time=1;
                strcpy(p->w,tem);
                g++;
            }
        }
        q=head;
        m=0;
        memset(tem,'\0',sizeof(tem));
        same=0;
    }
    
    
    for (int i = 0; i < g; i++)
    {
        p=head;
        q=p;    
        t=q;
        p=p->next;
        for (int j = 0; j < g-i; j++) // @@ [When i=0 and j starts, if g>=1, then p = head->next. But if the list has only one node, p is NULL, leading to dereferencing NULL in strcmp(q->w,p->w).]
        {
            if (strcmp(q->w,p->w)>0)
            {
                if (strcmp(t->w,q->w)==0) // @@ [This condition attempts to check if t == q (i.e., swapping head), but comparing strings instead of pointers is incorrect and unreliable.]
                {
                    q=head;
                    q->next=p->next;
                    p->next=head;
                    head=p;
                    p=q->next;
                    t=head;
                }
                else
                {
                    t->next=p;
                    q->next=p->next;
                    p->next=q;
                    
                    t=p;
                    p=q->next;
                }
            }
            else
            {
                t=q;
                q=p;
                p=p->next;
            }
        }
    }
    p=head;
    for (int i = 0; i < g; i++)
    {
        printf("%s %d\n",p->w,p->time);
        p=p->next; // @@ [If the list has fewer than g nodes due to earlier logic errors (e.g., failed insertions), this will eventually dereference NULL. Also, g counts intended nodes, but list may be malformed.]
    }
    
    
return 0;
}