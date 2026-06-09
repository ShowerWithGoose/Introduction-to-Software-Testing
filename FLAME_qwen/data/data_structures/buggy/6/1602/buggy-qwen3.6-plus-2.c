#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); // @@ Accesses st[100] out of bounds when stack is full; loop condition should check i < 100 first.
            
            if(i==100)printf("error "); // @@ Fails to consume the integer value for the push operation, causing input stream desynchronization.
            else
            scanf("%lld ",&st[i]); // @@ Trailing space in format string causes scanf to wait indefinitely for non-whitespace input; should be "%lld".
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); // @@ Evaluates st[j] before checking j>=0, leading to out-of-bounds access st[-1] when stack is empty; conditions should be swapped.
            
            if(j==-1)printf("error ");
                else{
                printf("%lld ",st[j]);
                st[j]=0;}
            
        }
        else if(a==-1){
            return 0;
        }
        
    }
return 0;
}