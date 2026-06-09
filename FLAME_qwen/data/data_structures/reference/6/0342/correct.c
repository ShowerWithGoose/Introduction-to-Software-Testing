/*
 * @Author:
 * @Date: 2022-04-14 19:04:32
 * @LastEditors:
 * @LastEditTime: 2022-04-14 19:07:59
 * @FilePath: 1.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN 110
int op,top;
int A[MAXN];

int main()
{
    scanf("%d",&op);
    while (op != -1)
    {
        if(op == 1) 
        {
            scanf("%d",&A[++top]);
            if(top > 100)
            {
                printf("error ");
                top = 100;
            }
        }
        else
        {
            if(!top)
                printf("error ");
            else
                printf("%d ",A[top--]);
        }
        scanf("%d",&op);
    }
    
    return 0;
}
