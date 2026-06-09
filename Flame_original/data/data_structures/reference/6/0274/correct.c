#include<stdio.h>
int main(){
    int stack[111],top=-1,x,y;
    scanf("%d",&x);
    while(x!=-1){
        if(x==0){
            if(top<0) printf("error ");
            else printf("%d ",stack[top--]);
        }else if(x==1){
            scanf("%d",&y);
            stack[++top]=y;
        }
        scanf("%d",&x);
    }
    return 0;
}
