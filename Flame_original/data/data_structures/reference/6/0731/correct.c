#include<stdio.h>
int sum=0;
int s[100];
int main(void){
    int f;
    int num;
    while(~scanf("%d",&f)){
        switch (f){
            case 1:
                scanf("%d",&num);
                if(sum==100)printf("error ");
                else s[sum++]=num;
                break;
            case 0:
                if(sum==0)printf("error ");
                else printf("%d ",s[--sum]);
                break;
            case -1:
                return 0;
        }
    }
    return 0;
}


