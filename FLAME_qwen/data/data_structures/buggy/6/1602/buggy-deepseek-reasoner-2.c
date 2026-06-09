#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); @@ // Error: out-of-bounds access when i reaches 100 (stack full) because condition does not check i<100; should be for(i=0; i<100 && st[i]!=0; i++);
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]); @@ // Error: when stack is full (i==100), the integer value after '1' is not read from input, causing the next scanf to consume it as an operation number. Should still read the integer to discard it.
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); @@ // Error: accesses st[-1] when j becomes -1 (empty stack) because st[j]==0 is evaluated before checking j>=0; should be for(j=99; j>=0 && st[j]==0; j--);
            
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