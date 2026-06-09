#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); @@ [This loop assumes that the stack is stored contiguously from index 0, but after popping (setting an element to 0), there may be zeros in the middle, causing the push to overwrite or skip positions incorrectly. The stack should be managed with a top pointer, not by searching for the first zero.]
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]); @@ [Using "%lld " with a space at the end can cause input parsing issues, especially if the next input is immediately following without whitespace. Also, this approach of using 0 to denote empty slots fails when 0 is a valid value to push (though problem says pushed integers are not 0, but logic is still flawed due to non-contiguous tracking).]
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); @@ [This searches from the end for a non-zero element, which assumes that all valid elements are at the high end, but pushes fill from the bottom. This leads to incorrect pop behavior — it doesn't simulate a LIFO stack correctly. For example, after pushing 5, 10, the stack should pop 10 then 5, but this will look from index 99 downward and miss them if they're at indices 0 and 1.]
            
            if(j==-1)printf("error ");
                else{
                printf("%lld ",st[j]);
                st[j]=0;} @@ [Setting st[j]=0 breaks the contiguous assumption and introduces gaps. Combined with the flawed push logic, this causes future operations to misbehave. The stack should use a top index instead of relying on zero/non-zero values.]
            
        }
        else if(a==-1){
            return 0;
        }
        
    }
return 0;
}