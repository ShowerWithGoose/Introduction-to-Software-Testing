#include <stdio.h>
#define sf scanf
#define pf printf
#define ll long long 
#include <math.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>
 

int main(){
    int s[108]={0};
    int a,b,c,d,e,f,i=0;
    while(1){
        sf("%d",&a);
        if(a==1){sf("%d",&b);
            if(i==99){
                pf("error ");
            }else{
            s[i]=b;i++;}
        }else if(a==0){
            d=s[i-1];s[i-1]=0;i--;
            if(i<0){ // @@ The condition i<0 is checked after decrementing i, so when the stack is empty (i==0), after i--, i becomes -1, and the condition triggers. However, the pop operation should be attempted when the stack is empty before decrementing. The correct logic is to check if i==0 before decrementing, and if so, output "error" without popping. Here, when the stack is empty (i==0), the code incorrectly accesses s[-1] and then decrements i to -1, causing undefined behavior and incorrect output.
                pf("error ");
            }else{
                pf("%d ",d);
            }
            
        }else if(a==-1){
            break;
        }
        
    }
}