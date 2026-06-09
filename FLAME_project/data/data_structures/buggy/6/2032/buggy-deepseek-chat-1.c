#include <stdio.h>
#include <string.h>

int s[100];
int op,i=-1,n; 
int main()
{
    while(scanf("%d",&op)!="-1"){ // @@ Error: Comparing integer with string. "-1" is a string literal, but op is an integer. Should be op != -1.
        
        if(op==1){
            if(i>=100){ // @@ Error: Stack capacity is 100, but index i starts at -1, so the maximum valid index is 99. Condition should be i >= 99 to check if stack is full.
                printf("error ");
            }else{
                scanf("%d",&s[++i]);
                
            }
            
        }else if(op==0){
            
            if(i<0){ // @@ Error: This condition is correct for empty stack, but the logic for pop is fine.
                printf("error ");
            }else{
                printf("%d ",s[i--]);
            
            }
            
        }
    }
    
    
    
//    for(i=0;i<n;i++){}
    

 return 0;
}