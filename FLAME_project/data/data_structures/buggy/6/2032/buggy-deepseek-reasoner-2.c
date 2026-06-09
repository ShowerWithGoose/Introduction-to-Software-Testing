#include <stdio.h>
#include <string.h>

int s[100];
int op,i=-1,n; 
int main()
{
    while(scanf("%d",&op)!="-1"){ // @@ Incorrect condition: compares integer return value with string; should be while(scanf("%d",&op)==1 && op!=-1). Causes infinite loop.

        if(op==1){
            if(i>=100){ // @@ Off-by-one: max index is 99; condition should be i>=99 to prevent out-of-bounds access when pushing after 100 elements.
                printf("error ");
            }else{
                scanf("%d",&s[++i]);
                
            }
            
        }else if(op==0){
            
            if(i<0){
                printf("error ");
            }else{
                printf("%d ",s[i--]);
            
            }
            
        }
    }
    
    
    
//    for(i=0;i<n;i++){}
    

 return 0;
}