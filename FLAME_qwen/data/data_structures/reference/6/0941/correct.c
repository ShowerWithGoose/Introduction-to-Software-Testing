#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int stack[100];
    int i = 0,count = 0,in,putin;
    while(scanf("%d",&in)){
        if(in == -1) break;
        else if(in == 0){
            if(count == 0) printf("error ");
            else{
                printf("%d ",stack[count-1]);
                count--;
            }
        }
        else if(in == 1){
            scanf("%d",&putin);
            stack[count] = putin;
            count++;
        }
    }
    system("pause");
    return 0;
}

