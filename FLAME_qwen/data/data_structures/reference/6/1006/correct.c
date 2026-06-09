#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    int stack[110],act,cnt,top=-1;
    while(1){
        scanf("%d",&act);
        if(act==-1){
            break;
        }

        if(act==1){
            scanf("%d",&cnt);
            if(top<100){
                top++;
                stack[top]=cnt;
            }else{
                printf("error ");
            }
        }else{
            if(top>=0){
                printf("%d ",stack[top]);
                top--;
            }else{
                printf("error ");
            }
        }
    }
    
    return 0;
}
