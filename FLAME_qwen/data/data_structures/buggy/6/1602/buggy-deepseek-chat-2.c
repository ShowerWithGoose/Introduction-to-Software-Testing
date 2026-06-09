#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); // @@ [Error: This loop assumes that a value of 0 indicates an empty slot, but 0 could be a valid pushed value, causing incorrect behavior. Also, the loop does not check for array bounds, potentially accessing st[100] which is out of bounds.]
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]); // @@ [Error: The format string "%lld " has a trailing space, which will cause scanf to consume any following whitespace, potentially skipping the next input token. Also, the variable 'a' is declared as int but the stack stores long long int, and the input for push values is read as %lld, but the operation code is read as %d, causing type mismatch issues.]
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); // @@ [Error: This loop assumes that a value of 0 indicates an empty slot, but 0 could be a valid pushed value, causing incorrect pop behavior. Also, the loop starts from index 99, which is incorrect for a stack that should pop from the top (last pushed element).]
            
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