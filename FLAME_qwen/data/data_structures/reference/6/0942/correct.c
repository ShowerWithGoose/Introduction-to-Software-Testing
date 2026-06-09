#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int a[105];
int top=0;

int main()
{
    int op;
    int num;
    scanf("%d",&op);
    while(op!=-1){
        if(op==1){
            if(top==100){
                printf("error ");
            }else{
                scanf("%d",&num);
                a[top++]=num;
            }
        }else if(op==0){
            if(top==0){
                printf("error ");
            }else{
                top--;
                printf("%d ",a[top]);
            }
        }
        scanf("%d",&op);
    }
    return 0;
}
