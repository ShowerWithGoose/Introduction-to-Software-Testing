#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int s[100];
    int i=0;
    int a,b;
    while(scanf("%d",&a)==1){ // @@ Missing termination condition for input -1; the loop will continue to process -1 as an operation, causing erroneous pop.
        if(a==0&&i==0){
            printf("error ");
        }else if(a==1){
            scanf("%d",&b);
            s[i++]=b; // @@ No check for stack overflow; if i exceeds 99, it will write out of bounds and not output error.
        }else{ // @@ The else clause handles a==-1 as a pop, but it should break the loop when a==-1. Also, it will try to access s[i-1] when i==0 (if -1 encountered after empty stack), causing out-of-bounds access.
            printf("%d ",s[i-1]); // @@ Accesses s[i-1] when i=0, causing out-of-bounds read. Also outputs for invalid operation -1.
            i--;
        }
    }
    return 0;
}