#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); // @@ Out-of-bounds array access when stack is full (i reaches 100), should check i<100 first.
            
            if(i==100)printf("error "); // @@ Fails to consume the integer to be pushed from the input buffer, causing subsequent reads to be misaligned.
            else
            scanf("%lld ",&st[i]); // @@ Trailing space in scanf format string causes it to wait for non-whitespace input, potentially hanging or misreading.
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); // @@ Incorrect short-circuit evaluation order; st[j] is accessed when j=-1, causing out-of-bounds access. j>=0 should be checked first.
            
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