#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int stack[100];
int main()
{
    int x,i=0;
    scanf("%d",&x);
    while(x!=-1){
        if(1==x){
            scanf("%d",&x);
            if(i<=100)stack[i++]=x;
            else printf("error ");
        }
        if(0==x){
            if(i-1>=0){
                printf("%d ",stack[i-1]);
                stack[i-1]=0;
                i--;
            }
            else printf("error ");
        }
        scanf("%d",&x);
    }

    return 0;
}

