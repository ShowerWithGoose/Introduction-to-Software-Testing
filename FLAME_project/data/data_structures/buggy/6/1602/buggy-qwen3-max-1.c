#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); @@ [This loop assumes that the stack is stored contiguously from index 0 and uses 0 as an indicator of unused slots. However, after popping (setting an element to 0), this logic breaks because a zero in the middle may be mistaken for an empty slot, causing push to overwrite non-top elements or skip valid ones.]
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]); @@ [Using "%lld " with trailing space can cause input parsing issues, especially when next input is not separated by extra whitespace or at end-of-input. Also, storing values in non-top positions due to flawed vacancy detection leads to incorrect stack behavior.]
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); @@ [This searches from the top of the array downward for a non-zero value, assuming zeros represent empty slots. However, if actual pushed value is zero (which is allowed per problem: only operations are 1, 0, -1; pushed integers are "not 1, 0, or -1", so zero should never be pushed — BUT the code allows reading any integer including zero, and problem says pushed integers are not 0, so maybe safe? However, the real issue is that stack is not maintained as a LIFO structure with a top pointer; instead it relies on zero-filling, which fails when pops create holes. Also, if all elements are zero, j becomes -1 correctly, but the logic doesn't reflect true stack top.]
            
            if(j==-1)printf("error ");
                else{
                printf("%lld ",st[j]);
                st[j]=0;} @@ [Setting popped element to 0 creates a "hole". Subsequent push will fill the first zero (lowest index), not the actual top, violating stack LIFO order.]
            
        }
        else if(a==-1){
            return 0;
        }
        
    }
return 0;
}