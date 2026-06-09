#include <stdio.h>
#include <string.h>

int s[100];
int op,i=-1,n; 
int main()
{
    while(scanf("%d",&op)!="-1"){ // @@ scanf returns an int representing the number of successfully read items, comparing it to a string literal "-1" causes a type mismatch compilation error. It should compare the variable op to -1.
        
        if(op==1){
            if(i>=100){ // @@ The array s has a size of 100 (valid indices 0 to 99). When i reaches 99, the stack is full. Checking i>=100 allows an out-of-bounds write to s[100]. It should be i>=99.
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