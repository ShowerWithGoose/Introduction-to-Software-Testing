#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int sta[2333];
int main()
{
    int top=-1,func;
    for(;1;){
        scanf("%d",&func);
        if(func==1){
            top++;
            scanf("%d",&sta[top]);
        }
        if(func==0){
            if(top!=-1){
                printf("%d ",sta[top]);
                top--;
            }
            else if(top==-1){
                printf("error ");
            }
        }
        if(func==-1){
            break;
        }
    }
    return 0;
}

