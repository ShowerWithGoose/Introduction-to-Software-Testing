#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); @@ [This loop assumes that the stack is stored contiguously from index 0 and uses 0 to indicate unused slots. However, if a pushed value is 0, it will be treated as an empty slot, causing incorrect behavior. The problem does not restrict pushed values from being 0, so using 0 as a sentinel is invalid.]
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]); @@ [The space after %lld in scanf can cause input parsing issues, especially when next input is immediately following without whitespace or at EOF. It may consume extra whitespace unnecessarily and interfere with subsequent reads.]
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); @@ [Same issue: assumes 0 means empty. If a legitimate 0 was pushed, this logic will skip it and pop from a wrong (earlier) position or report error incorrectly.]
            
            if(j==-1)printf("error ");
                else{
                printf("%lld ",st[j]);
                st[j]=0;} @@ [Setting popped element to 0 reinforces the flawed assumption that 0 means "empty", which breaks if 0 is a valid stack value.]
            
        }
        else if(a==-1){
            return 0;
        }
        
    }
return 0;
}