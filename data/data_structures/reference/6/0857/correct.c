#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[100];
int main(){
    int op;
    int num;
    int put = -1;
    while((scanf("%d",&op))!=EOF){
        if(op == 1){
            scanf("%d",&num);
            if(put+1<= 99){
                put = put+1;
                a[put] = num;

            }
            else{
                printf("error ");
            }
        }
        if(op == 0){
            if(put>=0){
                printf("%d ",a[put]);
                put = put - 1;
            }
            else{
                printf("error ");
            }
        }
        if(op == -1){
            break;
        }
    }
    return 0;
}
