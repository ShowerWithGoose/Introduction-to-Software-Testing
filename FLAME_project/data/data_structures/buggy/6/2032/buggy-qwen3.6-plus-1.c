#include <stdio.h>
#include <string.h>

int s[100];
int op,i=-1,n; 
int main()
{
    while(scanf("%d",&op)!="-1"){ // @@ [The condition compares the return value of scanf (an integer) with a string literal "-1". This is a type mismatch and logical error. scanf returns the number of items successfully read, or EOF. It does not return the string read. Furthermore, even if it returned the value, comparing an int to a char* is invalid. The loop should terminate when op is -1, so the condition should be `op != -1`. Because this condition is always true (or behaves unpredictably/incorrectly), the loop never terminates correctly upon reading -1, causing Time Limit Exceeded.]
        
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