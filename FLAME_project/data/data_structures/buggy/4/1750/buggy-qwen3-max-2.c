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
        while (tp<'A'||tp>'z'||(tp<'a'&&tp>'Z'))
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
            strcpy(p->w,tem);
            p->time=1;
            head=p;
            q=head;
            g++;
        }
        else
        {
            for (int i = 0; i < g-1; i++)
            {
                if(strcmp(q->w,tem)==0)
                {
                    q->time=1+q->time;
                    same=1;
                    break;
                }
                q=q->next;
            }
            if(strcmp(q->w,tem)==0&&same==0)
                {
                    q->time=1+q->time;
                    same=1;
                }
            if (same==0)
            {
                p->next=(struct statistic *)malloc(sizeof(struct statistic)); // @@ [p is uninitialized when head != NULL and it's the second word or later; p points to last node only if previous insertion succeeded, but logic doesn't maintain p correctly]
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
        for (int j = 0; j < g-i; j++) // @@ [when j reaches g-i-1, p becomes NULL, then accessing p->w causes runtime error (segmentation fault)]
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