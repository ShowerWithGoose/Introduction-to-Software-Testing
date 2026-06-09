/*
 * @Author:
 * @Date: 2022-04-14 19:10:28
 * @LastEditors:
 * @LastEditTime: 2022-04-14 19:17:52
 * @Description: 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
//#define ll long long
int stack[100] ;
int top = -1;
// int x;
int op;
int main()
{
    while(op!=-1)
    {
        scanf("%d",&op);
        if(op == 1){
            if(top == 99) {printf("error "); int x = getchar();}
            else scanf("%d",&stack[++top]);
        }
        else if(op == 0){
            if(top == -1) printf("error ");
            else printf("%d ",stack[top--]);
        }
    }
    return 0;
}
