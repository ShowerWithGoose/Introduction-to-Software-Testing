#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); // @@ This loop may cause out-of-bounds access if the stack is full (all 100 elements non-zero), and the subsequent if condition will never be reached because i will be 100, but the loop will continue past the array bounds.
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]); // @@ The format string "%lld " has a trailing space, which will cause scanf to consume the next integer in the input, potentially skipping the next operation code.
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); // @@ This loop searches from the top of the stack incorrectly; it assumes the stack is stored contiguously from index 0, but the push operation uses the first zero element, not the top. This will pop the wrong element.
            
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