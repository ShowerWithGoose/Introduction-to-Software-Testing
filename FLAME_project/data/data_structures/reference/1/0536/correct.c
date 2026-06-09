#include <stdio.h>
#include <stdlib.h>
void ch(int[],int,int);
void swap(int *a,int *b)
{
    int k;
    k=*a;
    *a=*b;
    *b=k;
}
int main()
{
    int a,*s,i;
    scanf("%d",&a);
    s=(int*)malloc(sizeof(int)*a);
    for(i=0;i<a;i++)
        s[i]=i+1;
    ch(s,0,a-1);
    free(s);
    return 0;
}
void ch(int a[],int m,int n)
{
    int i;
    if(m==n){
        for(i=0;i<=n;i++)
            printf("%d ",a[i]);
    printf("\n");}
    else{
        for(i=m;i<=n;i++){
            swap(&a[m],&a[i]);
            ch(a,m+1,n);
        }
        for(i=m;i<n;i++)
             swap(&a[i],&a[i+1]);
    }
}

