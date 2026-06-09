#include<stdio.h>
int main(){
    int stack[101]={0};
    int th;
    int flag,number;
    while(flag != -1){
        scanf("%d",&flag);
        switch(flag){
            case 1:
                scanf("%d",&number);
                if(th == 100){
                    printf("error ");
                    break;
                }
                th++;
                stack[th] = number;
                break;
            case 0:
                if(th == 0){
                    printf("error ");
                    break;
                }
                printf("%d ",stack[th]);
                stack[th] = 0;
                th--;
                break;
            case -1:
                break;
            default:
                printf("error");
                break;
        }
    }
    return 0;
}



