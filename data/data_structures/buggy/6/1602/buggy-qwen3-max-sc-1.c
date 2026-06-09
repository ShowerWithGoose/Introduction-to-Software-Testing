#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); @@ [This loop assumes that the stack is contiguous and ends at the first zero, but zeros can be valid pushed values. Thus, it incorrectly computes the current stack size.]
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]); @@ [The space after %lld in scanf can cause unexpected blocking/waiting for non-whitespace input after the number, leading to incorrect parsing of subsequent operations.]
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); @@ [This loop searches from the top of the array downward for a non-zero value, which fails if zero was explicitly pushed onto the stack. It also accesses st[-1] when j becomes -1, causing undefined behavior.]
            
            if(j==-1)printf("error ");
                else{
                printf("%lld ",st[j]);
                st[j]=0;} @@ [Setting st[j]=0 to "pop" is flawed because zero is a valid integer that could have been pushed; this corrupts the stack state and interferes with future size/pop checks.]
            
        }
        else if(a==-1){
            return 0;
        }
        
    }
return 0;
}