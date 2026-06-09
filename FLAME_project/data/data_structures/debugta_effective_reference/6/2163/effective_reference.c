#include<stdio.h>
int sum=0;
int shuzu[100];
int main(void){
    int choice;
    int num;
    while(~scanf("%d",&choice)){
        switch (choice){
            case 1:
                scanf("%d",&num);
                if(sum==100)printf("error ");
                else shuzu[sum++]=num;
                break;
            case 0:
                if(sum==0)printf("error ");
                else printf("%d ",shuzu[--sum]);
                break;
            case -1:
                return 0;
        }
    }
    return 0;
}


