#include <stdio.h>
#include <string.h>

int s[100];
int op,i=-1,n; 
int main()
{
    while(scanf("%d",&op)!="-1"){ // @@ The condition scanf("%d",&op)!="-1" is incorrect. scanf returns the number of successfully read items (an integer), not the value read. Comparing the return value (likely 1) to the string pointer "-1" or its address is logically wrong and does not check if the input value is -1. This likely causes an infinite loop because the termination condition is never met properly, leading to Time Limit Exceeded. It should be checking if the read value 'op' is -1, e.g., while(scanf("%d",&op)==1 && op!=-1).
        
        if(op==1){
            if(i>=100){
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