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
        scanf("%d%d",&n,&m); // @@ The input format specifies that operations and values are separated by spaces, but not every operation (like 0 or -1) is followed by a second integer. Using scanf("%d%d") forces the program to wait for a second integer even when n is 0 or -1, causing it to hang (Time Limit Exceeded) or read incorrect data. It should read n first, then conditionally read m if n is 1.
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