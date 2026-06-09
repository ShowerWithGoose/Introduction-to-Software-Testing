#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); @@ [This loop assumes that the stack is stored contiguously from index 0, but after popping (setting an element to 0), there may be zeros in the middle, causing the push to overwrite or skip valid elements. The stack should use a top pointer instead of searching for the first zero.]
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]); @@ [Using "%lld " with a trailing space can cause input parsing issues by consuming extra whitespace and potentially interfering with subsequent reads. Also, storing into st[i] assumes i is the correct next position, which is invalid due to the flawed zero-search logic above.]
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); @@ [This searches from the end of the array for a non-zero element, which does not reflect actual stack behavior. A stack must pop the most recently pushed element (LIFO), but this may pop an old element if newer ones were popped (set to 0) earlier. The stack should track the top index, not rely on zero/non-zero values.]
            
            if(j==-1)printf("error ");
                else{
                printf("%lld ",st[j]);
                st[j]=0;} @@ [Setting st[j]=0 breaks the contiguous stack assumption and causes future push operations to misbehave because they search for the first zero, which may be before j. This leads to incorrect ordering and potential data loss.]
            
        }
        else if(a==-1){
            return 0;
        }
        
    }
return 0;
}