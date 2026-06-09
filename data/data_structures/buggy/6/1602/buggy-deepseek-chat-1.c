#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); // @@ This loop uses i to find an empty slot, but i is declared outside and reused, causing potential issues with the push logic. Also, using st[i]!=0 as condition fails if 0 is a valid pushed value.
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]); // @@ The format string has a trailing space, which may cause input reading issues. Also, it does not check if the stack is full before reading the value.
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); // @@ This loop searches from the top (index 99) for a non-zero element, but the stack may have gaps due to the push logic, leading to incorrect pop behavior.
            
            if(j==-1)printf("error ");
                else{
                printf("%lld ",st[j]);
                st[j]=0;}
            
        }
        else if(a==-1){
            return 0;
        }
        
    }
return 0;
}