#include<stdio.h>
#include<string.h>

int top=-1;

int main(){
    int a[100];
    int c,data;
    while(1){
        scanf("%d",&c);
        if(c==-1)  break;
        if(c==1){
            scanf("%d",&data);
            if(top==99)  printf("error ");
            else  a[++top]=data;
        }
        if(c==0){
            if(top==-1)  printf("error ");
            else{
                printf("%d ",a[top]);
                top--;
            }
        }
    }
}
