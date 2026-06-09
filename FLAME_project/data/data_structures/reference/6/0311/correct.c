#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int s[105],top=-1,d,num;
    while(scanf("%d",&d)&&d!=-1){
        if(d==1){
            scanf("%d",&num);
            if(top==99)
                printf("error ");
            else{
                top++;
                s[top]=num;
            }
        }
        else if(d==0){
            if(top==-1)
                printf("error ");
            else{
                printf("%d ",s[top]);
                top--;
            }
        }
    }
    return 0;
}



