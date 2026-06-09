#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); @@ [This loop assumes that the stack is stored contiguously from index 0, but after popping (setting an element to 0), there may be zeros in the middle, causing incorrect detection of the next free slot. Also, it doesn't track actual stack size correctly.]
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]); @@ [Using "%lld " with trailing space may cause input parsing issues; also, storing at index i found by scanning for zero is logically flawed for a stack.]
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); @@ [This scans from the top of the array downward to find the last non-zero element, which incorrectly assumes that the stack grows upward and that zeros only appear above valid elements. However, due to previous pops setting elements to zero, this may skip valid elements or access invalid indices. Also, j can become -1 leading to out-of-bounds concerns in logic.]
            
            if(j==-1)printf("error ");
                else{
                printf("%lld ",st[j]);
                st[j]=0;} @@ [Setting popped element to zero breaks the contiguous assumption of the stack and interferes with future push/pop logic. A proper stack should use a top pointer instead of relying on zero/non-zero values.]
            
        }
        else if(a==-1){
            return 0;
        }
        
    }
return 0;
}