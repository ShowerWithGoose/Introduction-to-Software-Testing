#include <stdio.h>
#include <string.h>

int s[100];
int op,i=-1,n; 
int main()
{
    while(scanf("%d",&op)!="-1"){ // @@ The condition compares an integer with a string pointer, which is always false, causing an infinite loop. Should be: while(scanf("%d",&op) && op != -1)
        
        if(op==1){
            if(i>=100){ // @@ The stack size is 100, so valid indices are 0-99. When i is 99, the next push would go to index 100, which is out of bounds. Should be: if(i >= 99)
                printf("error ");
            }else{
                scanf("%d",&s[++i]);
                
            }
            
        }else if(op==0){
            
            if(i<0){ // @@ This condition is correct for empty stack check, but the initial value of i is -1, so the first pop will correctly detect empty stack.
                printf("error ");
            }else{
                printf("%d ",s[i--]);
            
            }
            
        }
    }
    
    
    
//    for(i=0;i<n;i++){}
    

 return 0;
}