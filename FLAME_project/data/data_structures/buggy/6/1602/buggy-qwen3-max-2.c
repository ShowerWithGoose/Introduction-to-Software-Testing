#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); @@ [This loop assumes that the stack is stored contiguously from index 0 and uses 0 as an indicator of unused slots. However, after popping (setting an element to 0), there may be zeros in the middle of the stack, causing this loop to incorrectly treat the stack as having fewer elements than it actually does. This breaks the LIFO behavior of a stack.]
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]); @@ [Using "%lld " with a trailing space can cause scanf to wait for additional input or behave unexpectedly when the next token is not separated by whitespace properly. Also, storing values starting from index i based on zero-checking is logically flawed due to the earlier issue.]
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); @@ [This attempts to find the top by scanning from the end, but because popped elements are set to 0 and pushes don't necessarily fill contiguously (due to the flawed push logic), this may pop from an incorrect position or miss valid elements. The stack should track the top index explicitly rather than relying on zero values.]
            
            if(j==-1)printf("error ");
                else{
                printf("%lld ",st[j]);
                st[j]=0;} @@ [Setting st[j] = 0 marks it as empty, but combined with the flawed push logic (which scans for first zero), this breaks stack ordering. For example, pushing 5, then 3, then popping (sets index 1 to 0), then pushing 7 will place 7 at index 1 instead of index 2, corrupting the stack order.]
            
        }
        else if(a==-1){
            return 0;
        }
        
    }
return 0;
}