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
            fscanf(in,"%c",&tp); // @@ [This reads next character without checking for EOF, which may cause undefined behavior if file ends inside a word. Also, after reading EOF, tp becomes indeterminate.]
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
            for (int i = 0; i < g-1; i++) // @@ [Loop runs only g-1 times, so it skips the last node when checking for existing words, leading to duplicate entries.]
            {
                if(strcmp(q->w,tem)==0)
                {
                    q->time=1+q->time;
                    same=1;
                    break;
                }
                q=q->next;
            }
            if(strcmp(q->w,tem)==0&&same==0) // @@ [This check only applies to the last node, but if g==1, the for loop doesn't run and q is still head, so this might work accidentally, but logic is inconsistent and error-prone.]
                {
                    q->time=1+q->time;
                    same=1;
                }
            if (same==0)
            {
                p->next=(struct statistic *)malloc(sizeof(struct statistic)); // @@ [If head is not NULL but p was never initialized to point to the last node, p is uninitialized or dangling, causing undefined behavior.]
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
        for (int j = 0; j < g-i; j++) // @@ [When i=0 and g>=1, inner loop runs g times, but list has only g nodes, so p may become NULL and accessing p->w causes segmentation fault.]
        {
            if (strcmp(q->w,p->w)>0) // @@ [If p is NULL (e.g., at end of list), this dereferences NULL pointer, causing crash.]
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