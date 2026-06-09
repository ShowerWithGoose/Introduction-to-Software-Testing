#include <stdio.h>
#include <string.h>

int s[100];
int op,i=-1,n; 
int main()
{
    while(scanf("%d",&op)!="-1"){ // @@ [The condition compares an integer return value of scanf with a string literal "-1". It should compare 'op' with -1 after successful reading. Also, scanf returns the number of successfully read items, not the value itself.]

        if(op==1){
            if(i>=100){ // @@ [Stack capacity is 100, indices 0-99. When i==99, stack is full. So condition should be i==99 or i>=99, not i>=100. However, since i starts at -1 and increments before storing, i==99 means 100 elements. So i>=100 is actually correct for overflow check, but the real issue is in loop condition.]
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