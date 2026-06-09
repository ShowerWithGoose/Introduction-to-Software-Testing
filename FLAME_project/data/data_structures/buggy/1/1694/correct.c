#include<stdio.h>
int n,a[10],biaoji[100];
void f(int T);
int main(){
    scanf("%d",&n);
    f(1);
    return 0;
}
void f(int T){
    if(T>n){
        for(int i=1;i<=n;i++){
            printf("%d",a[i]);
            if(i!=n){
                printf(" ");
            }
            else
            printf("\n");
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(biaoji[i]==0){
                biaoji[i]=1;
                a[T]=i;
                f(T+1);
                biaoji[i]=0;
            }
        }
    }
}


