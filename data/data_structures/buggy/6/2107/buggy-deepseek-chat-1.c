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
        scanf("%d%d",&n,&m); // @@ [Error: The input format specifies that operations and values are separated by spaces, but not every operation has a second integer. For example, operation 0 (pop) and operation -1 (end) are single integers. This scanf expects two integers per line, which will cause incorrect reading or undefined behavior when only one integer is provided.]
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