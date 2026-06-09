#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0}; // @@ Compilation error in C89: 'long long' type is not standard; use 'int' instead.
    memset(st,0,sizeof(st)); // @@ Redundant but not an error.
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++);
            
            if(i==100)printf("error "); // @@ Logical error: when stack is full, the push value is not read, causing input desynchronization.
            else
            scanf("%lld ",&st[i]); // @@ Depends on long long; if compilation fails above, this also fails.
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); // @@ Potential out-of-bounds access when j becomes -1; condition order should be j>=0 && st[j]==0.
            
            if(j==-1)printf("error ");
                else{
                printf("%lld ",st[j]); // @@ Same compilation dependency on long long.
                st[j]=0;}
            
        }
        else if(a==-1){
            return 0;
        }
        
    }
return 0;
}