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
        scanf("%d%d",&n,&m); // @@ [The program always reads two integers, but for pop (n=0) and end (n=-1), no second integer should be read. This causes incorrect input consumption and behavior.]
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