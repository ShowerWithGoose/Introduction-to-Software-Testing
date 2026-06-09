#include <stdio.h>

void swap(int a[],int x,int y){
    int t=a[y];
    for(int i=y;i>x;i--){ // @@ C89/C90 standard does not allow variable declaration inside for-loop initialization; declare 'int i' before the loop to fix compilation error.
    a[i]=a[i-1];
    }
    a[x]=t;
    }
void swapback(int a[],int x,int y){
    int t=a[x];
    for(int i=x;i<=y;i++){ // @@ C89 compilation error for loop variable declaration; additionally, loop variable 'i' is unused in the body.
        a[x]=a[x+1]; // @@ Logical error: should be 'a[i]=a[i+1];' to correctly shift elements left during backtracking.
    }
    a[y]=t;
}
void prt(int a[],int q){
    for(int i=1;i<=q;i++){ // @@ C89 compilation error for loop variable declaration.
    printf("%d ",a[i]);
    }
    printf("\n");
}
void pai_lie(int a[],int p,int q){

    for(int i=p;i<=q;i++){ // @@ C89 compilation error for loop variable declaration.

        swap(a,p,i);

        pai_lie(a,p+1,q);

        swapback(a,p,i);
        if(p==q){
        prt(a,q);
        }

    }



}


int main(){

    int n=0;

    scanf("%d",&n);
    int a[11]={0,1,2,3,4,5,6,7,8,9};

    int num=1;
    pai_lie(a,num,n);























    return 0;
}