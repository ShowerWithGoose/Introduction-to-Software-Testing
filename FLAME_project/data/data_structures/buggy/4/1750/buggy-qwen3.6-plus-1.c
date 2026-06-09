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
        while (tp<'A'||tp>'z'||(tp<'a'&&tp>'Z')) // @@ [Logic error: The condition tp<'A'||tp>'z' is incorrect for filtering non-alpha characters. It allows characters like '[', '\', ']' which are between 'Z' and 'a'. Also, the inner loop doesn't update tp if the first character is valid alpha, leading to potential infinite loops or logic errors depending on flow. However, the primary runtime/logic issue here is that `tem` is not null-terminated before use in `strcpy` or `strcmp` later if `m` is 0 or if `tem` contains garbage. But more critically, see below.]
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
            fscanf(in,"%c",&tp);
        }
        
        if (head==NULL)
        {
            p=(struct statistic *)malloc(sizeof(struct statistic));
            strcpy(p->w,tem); // @@ [Runtime Error: `tem` is not null-terminated. `m` tracks length, but `tem[m] = '\0'` is missing before this call. `strcpy` will read beyond bounds until it finds a null byte, causing undefined behavior/crash.]
            p->time=1;
            head=p;
            q=head;
            g++;
        }
        else
        {
            for (int i = 0; i < g-1; i++)
            {
                if(strcmp(q->w,tem)==0) // @@ [Runtime Error: `tem` is still not null-terminated here. `strcmp` requires null-terminated strings.]
                {
                    q->time=1+q->time;
                    same=1;
                    break;
                }
                q=q->next;
            }
            if(strcmp(q->w,tem)==0&&same==0) // @@ [Runtime Error: `tem` is still not null-terminated here.]
                {
                    q->time=1+q->time;
                    same=1;
                }
            if (same==0)
            {
                p->next=(struct statistic *)malloc(sizeof(struct statistic));
                p=p->next;
                p->time=1;
                strcpy(p->w,tem); // @@ [Runtime Error: `tem` is still not null-terminated here.]
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
        for (int j = 0; j < g-i; j++) // @@ [Logic Error/Runtime Error: The inner loop runs `g-i` times, but `p` becomes NULL before the loop finishes if the list is short or if `p->next` is accessed when `p` is NULL. Specifically, `p=p->next` is executed inside the loop, and `strcmp(q->w,p->w)` accesses `p->w`. If `p` becomes NULL, this crashes. The bubble sort implementation is flawed for linked lists.]
        {
            if (strcmp(q->w,p->w)>0)
            {
                if (strcmp(t->w,q->w)==0)
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
        p=p->next;
    }
    
    
return 0;
}