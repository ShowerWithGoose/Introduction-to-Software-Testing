#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); @@ [This loop assumes that the stack is stored contiguously from index 0 and uses 0 to mean "empty", but 0 could be a valid pushed value. Thus, using 0 as a sentinel for empty slots is incorrect and leads to logical errors in tracking stack size and contents.]
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]); @@ [The space after %lld in scanf can cause unexpected blocking or input parsing issues because it consumes any amount of whitespace, including newlines, potentially interfering with subsequent reads. Also, the logic for tracking top of stack is flawed due to misuse of zero-initialized array as stack state.]
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); @@ [Same issue: assuming 0 means empty slot is wrong because 0 might have been pushed as a valid value. This causes incorrect pop behavior—either popping from wrong location or reporting error when stack isn't actually empty.]
            
            if(j==-1)printf("error ");
                else{
                printf("%lld ",st[j]);
                st[j]=0;} @@ [Setting popped element to 0 further corrupts stack state if 0 is a valid value, and breaks the assumption used elsewhere in the code.]
            
        }
        else if(a==-1){
            return 0;
        }
        
    }
return 0;
}