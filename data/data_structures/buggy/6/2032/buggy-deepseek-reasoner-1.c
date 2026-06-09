#include <stdio.h>
#include <string.h>

int s[100];
int op,i=-1,n; 
int main()
{
    while(scanf("%d",&op)!="-1"){ // @@ [Invalid comparison: comparing int to string literal. Should check if op != -1 after successful read. Also loop never ends on -1.]
        
        if(op==1){
            if(i>=100){ // @@ [Incorrect full condition: i is index (max 99). Should be i>=99 or i==99.]
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