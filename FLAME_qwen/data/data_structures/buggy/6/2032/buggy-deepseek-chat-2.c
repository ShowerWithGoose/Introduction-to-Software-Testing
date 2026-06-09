#include <stdio.h>
#include <string.h>

int s[100];
int op,i=-1,n; 
int main()
{
    while(scanf("%d",&op)!="-1"){ // @@ [Error: Comparing integer with string literal. scanf returns an integer, and "-1" is a string. Should compare with -1 (integer). Also, the loop condition should check for end-of-file or -1 input, but the correct comparison is op != -1 after reading.]
        
        if(op==1){
            if(i>=100){ // @@ [Error: Stack capacity is 100, but index i starts at -1, so the maximum index is 99. Condition should be i >= 99 to check if stack is full before pushing.]
                printf("error ");
            }else{
                scanf("%d",&s[++i]); // @@ [Error: If the stack is full, this line still executes because the else block is only skipped when i>=100, but the condition is wrong. Additionally, the error message is printed but the push should not occur; however, due to the incorrect condition, the push may still happen when stack is full.]
                
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