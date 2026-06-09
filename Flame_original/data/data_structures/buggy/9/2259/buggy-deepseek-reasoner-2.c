#include<stdio.h>
#include<string.h>
#include<stdlib.h>
    struct line{
        int a1,b1;
        int a2,b2;
        struct line *next;
    };
    struct line l[100];
    int n;
    int num[100];
void link(struct line *a)
{
    int judge=0;
    for(int i=0;i<n;i++) // @@ Compilation error in C89: variable declaration inside for loop not allowed; use C99 or declare i at function start.
    {
            if(a->a2==l[i].a1&&a->b2==l[i].b1)
            {
                judge=1;
                a->next=&l[i];
                link(&l[i]);
            }
            else
            continue;
    }
    if(judge==0)
    a->next = NULL;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) // @@ Compilation error in C89: variable declaration inside for loop not allowed; use C99 or declare i at function start.
    {
        scanf("%d%d%d%d",&l[i].a1,&l[i].b1,&l[i].a2,&l[i].b2);
    }
    for(int i=0;i<n;i++) // @@ Compilation error in C89: variable declaration inside for loop not allowed; use C99 or declare i at function start.
    {
        link(&l[i]);
    }
    int high=1,low=1; // @@ Potential error: high should be initialized to 0, otherwise a chain of length 1 (isolated segment) will not update high and t will remain uninitialized.
    struct line *temp,*t;
    for(int i=0;i<n;i++) // @@ Compilation error in C89: variable declaration inside for loop not allowed; use C99 or declare i at function start.
    {
        temp=&l[i];
        while(temp->next !=NULL)
        {
            temp=temp->next ;
            low++;
        }
        
        {
            if(low>high)
            {
                high=low;
                t=&l[i]; // Potential runtime error: if low never > high, t remains uninitialized and is used in printf.
            }
            else
            continue; // @@ Logical error: this continue skips the reset of low (line 59), causing low to retain its value for the next iteration, leading to incorrect chain length calculations.
            low=1; // @@ Logical error: this line is only executed when low>high, but low must be reset to 1 for every chain; the continue above prevents reset in other cases.
        }
    }
    printf("%d %d %d",high,t->a1,t->b1); // @@ Potential runtime error: t may be uninitialized if no chain length > 1 was found.
    return 0;
}