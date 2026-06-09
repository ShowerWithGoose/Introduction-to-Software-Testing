#include<stdio.h>
int op,a,st[101],top;
int main(){
    scanf("%d",&op);
    while(~op){
        if(op==1){
            scanf("%d",&a);
            if(top<100) st[++top]=a;
            else printf("error ");
        }
        else{
            if(top) printf("%d ",st[top--]);
            else printf("error ");
        }
        scanf("%d",&op);
    }
    return 0;
}
