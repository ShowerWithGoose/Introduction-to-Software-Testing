#include<stdio.h>
#include<stdlib.h>
unsigned long factorial(unsigned long n);
void print();
void find();
int k[10];
int n;
int main()
{
    int i;
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        k[i]=i+1;
    }
    print();
    for(i=1;i<factorial(n);i++){
        find();
        print();
    }
    system("pause");
    return 0;
    
}
unsigned long factorial(unsigned long n)
{
    if(n<=1)    return 1;
    else    return n*factorial(n-1);
}
void print()
{
    int i=0;
    for(i=0;i<n-1;i++)
    {
        printf("%d ",k[i]);
    }
    printf("%d\n",k[i]);
}
void find()
{
    int i,j;
    for(i=n-2;i>0;i--){
        if(k[i]<k[i+1]) break;
    }
    int k1=i;
    int tl=i+1;
    for(i=k1+1;i<n;i++){
        if(k[i]>k[k1]&&k[i]<k[tl])
            tl=i;
    }
    int tmp=k[k1];
    k[k1]=k[tl];
    k[tl]=tmp;
    for(j=k1+1,i=n-1;i>j;i--,j++){
        tmp=k[i];
        k[i]=k[j];
        k[j]=tmp;
    }
}

