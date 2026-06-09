#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int top=-1;
int  isEmpty( )
{
       return top== -1;
} 
int isFull(  )
{
      return top==100-1;
}

int a[100];
int main(){
    int n,m;
    while(1){
        scanf("%d%d",&n,&m); // @@ This scanf expects two integers per iteration, but the input format is a sequence of integers where push operations are two numbers and pop/end are single numbers. This will cause misreading of subsequent operations, e.g., a pop operation (0) will also consume the next number (which may be a value for a push or another operation).
        if(n==-1)break;
        if(n==1){
            if( isFull() )
               printf("error ");
            else
                a[++top]=m;
        }
        if(n==0){
            if(isEmpty( ))
                printf("error ");
            else{
                printf("%d ",a[top--]);
            }
        }

    } 
    return 0;
}