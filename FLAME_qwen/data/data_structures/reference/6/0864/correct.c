#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define ull unsigned long long
#define MAXN 100
int main(){
	int stack[MAXN],top=-1;
    int op,num;
    while(1)//为什么用两次scanf op 然后while op！=-1不可以 
    {
        scanf("%d",&op);
        if(-1==op)break;
        else if(1==op)//enter
        {
            if(top==MAXN-1)printf("error ");
            else 
            {
                scanf("%d",&num);
                stack[++top]=num;
             }
        }
        else if(0==op)//out
        {
            if(top==-1)printf("error ");
            else{
                printf("%d ",stack[top--]);
            }
            
        }
    }
    return 0;
}


