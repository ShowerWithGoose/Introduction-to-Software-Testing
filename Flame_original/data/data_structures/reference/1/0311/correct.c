#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void f(int step,int n,int a[],int book[]){
    int i;
    if(step>n){
        for(i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    else{
        for(i=1;i<=n;i++){
        if(book[i]==0){
            a[step]=i;
            book[i]=1;
            f(step+1,n,a,book);
            book[i]=0;
            }
        }
    }

}
int main(){
    int n,a[11],book[11]={0};
    scanf("%d",&n);
    f(1,n,a,book);
    return 0;
}

