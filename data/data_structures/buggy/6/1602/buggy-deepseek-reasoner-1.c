#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{    long long int st[100]={0};
    memset(st,0,sizeof(st));
    int a,i=0,j;
    while(scanf("%d",&a)!=EOF){
        if(a==1){
            for(i=0;st[i]!=0;i++); // @@ [This loop may access out-of-bounds st[100] when stack is full (all indices 0-99 non-zero), causing undefined behavior. Should stop at i<100.]
            
            if(i==100)printf("error ");
            else
            scanf("%lld ",&st[i]);
        }
        else if(a==0){
            for(j=99;st[j]==0&&j>=0;j--); // @@ [The condition order is wrong: it checks st[j]==0 before j>=0, so when j becomes -1, st[-1] is accessed out-of-bounds. Should be j>=0 && st[j]==0.]
            
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