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
        scanf("%d%d",&n,&m); // @@ The input format requires reading operations sequentially. Reading two integers at once causes issues when the operation is '0' or '-1' (which are not followed by a value to push), leading to incorrect parsing, potential infinite loops if input doesn't match expectations, or skipping inputs. Specifically for '0', it tries to read the next operation as 'm', consuming it prematurely. For '-1', it might wait for another integer if not handled carefully or misinterpret subsequent data. This mismatch with the problem's input stream structure causes logical errors and potentially Time Limit Exceeded if the loop doesn't terminate correctly due to failed scans or infinite waiting.
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