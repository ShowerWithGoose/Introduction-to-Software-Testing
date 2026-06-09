#include<stdio.h>
int a[12],n;
int b[12]={0};
void f(int);
int main(){
    
    scanf("%d",&n);
    f(0);
    return 0;
}
void f(int x){
    int i;
    if(x==n){
    int j;
    for(j=0;j<n;j++){
        printf("%d",a[j]); // @@ missing space between numbers - should be "%d "
        
    }
    printf("\n");
    }
    else{
        for(i=1;i<=n;i++){
            if(b[i]==0){
                a[x]=i;
                b[i]=1;
                f(x+1);
                b[i]=0;
            }
        }
    }
}