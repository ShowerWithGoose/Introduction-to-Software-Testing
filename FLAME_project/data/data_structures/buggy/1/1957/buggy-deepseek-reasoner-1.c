#include <stdio.h>
int arry[15];
void rank(int arry[],int,int);
void swap(int arry[],int,int);
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        arry[i]=i+1;
    }
    rank(arry,0,N-1);
    return 0;
}
rank(int arry[],int p,int q)
{
    if(p==q){
        for(int i=0;i<=q;i++){
            printf("%d",arry[i]); // @@ Missing space: should be printf("%d ",arry[i]); to match expected output format with spaces between numbers.
        }
        printf("\n");
    }else{
        for(int i=p;i<=q;i++){
            swap(arry,p,i);
            rank(arry,p+1,q );
            swap(arry,p,i);
        }
    }
}
swap(int arry[],int m,int n)
{
    int temp;
    temp=arry[m];
    arry[m]=arry[n];
    arry[n]=temp;
}