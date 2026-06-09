#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); // @@ The logic for finding the top of the stack is flawed. It assumes 0 means empty, but 0 is a valid integer value that can be pushed. Also, it scans from the bottom up, which is inefficient and incorrect if 0s are present in the middle. A separate 'top' index variable should be used.
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]); // @@ Reading into st[i] after the loop. If the stack was full (i==100), this branch is skipped, which is correct. However, the previous line's logic for finding 'i' is the primary error. Also, using space in scanf format string can cause issues with input parsing depending on newlines/spaces.
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); // @@ Similar to push, this logic for finding the top element is flawed. It assumes 0 means empty slot. If a user pushes 0, this will incorrectly identify it as an empty slot or skip valid elements. It should use a maintained 'top' index.
            
            if(j==-1)printf("error ");
                else{
                printf("%lld ",st[j]);
                st[j]=0;} // @@ Setting the slot to 0 to mark it empty reinforces the flaw that 0 is treated as "empty", making it impossible to distinguish between an empty slot and a pushed 0.
            
        }
        else if(a==-1){
            return 0;
        }
        
    }
return 0;
}