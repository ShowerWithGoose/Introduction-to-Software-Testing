#include <stdio.h>
#include <string.h>

int s[100];
int op,i=-1,n; 
int main()
{
    while(scanf("%d",&op)!="-1"){ // @@ [Error: Condition never false because comparing return value of scanf ('-1' string) causes infinite loop. Should check `op != -1` after reading, or break when op is -1.]
        
        if(op==1){
            if(i>=100){ // @@ [Error: Stack capacity check off-by-one. Should be `i>=99` to prevent overflow when i=99 (next push would be at index 100).]
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