#include<stdio.h>
int main(){
    int a[100];
    int com,n,top=-1;//com是1 0 -1，n是元素
    scanf("%d",&com);
    while(com!=-1){
        if(com==1){
            scanf("%d",&n);
            if(top==99){
                printf("error ");
            }
            else{
                top++;
                a[top]=n;
            }
        }
        else if(com==0){
            if(top==-1){
                printf("error ");
            }
            else{
                printf("%d ",a[top]);
                top--;
            }
        }
        scanf("%d",&com);
    }
    return 0;
}
