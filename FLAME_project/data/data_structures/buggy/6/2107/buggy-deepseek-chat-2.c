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
        scanf("%d%d",&n,&m); // @@ [Error: This reads two integers per iteration, but the input format may have only one integer (e.g., 0 or -1) without a second value, causing incorrect parsing and potential infinite loop or undefined behavior.]
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