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
rank(int arry[],int p,int q) @@ [Missing return type 'void' in function definition; this causes a compilation error in standard C]
{
    if(p==q){
        for(int i=0;i<=q;i++){
            printf("%d",arry[i]); @@ [Missing space after each number as required by output format, but this is a logic/output issue, not compilation. However, the primary compilation error is the missing 'void'.]
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
swap(int arry[],int m,int n) @@ [Missing return type 'void' in function definition; this causes a compilation error in standard C]
{
    int temp;
    temp=arry[m];
    arry[m]=arry[n];
    arry[n]=temp;
}