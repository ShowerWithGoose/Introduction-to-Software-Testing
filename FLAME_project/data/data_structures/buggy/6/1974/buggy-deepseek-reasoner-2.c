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
            if(i==99){ // @@ [Error: Full condition should be i==100 (or i>=100) because capacity is 100 elements (indices 0-99). i==99 only allows 99 pushes, not 100.]
                pf("error ");
            }else{
            s[i]=b;i++;}
        }else if(a==0){
            d=s[i-1];s[i-1]=0;i--; // @@ [Error: Accesses s[i-1] before checking if stack is empty (i==0). This leads to out-of-bounds access when pop is attempted on an empty stack.]
            if(i<0){ // @@ [Error: The condition i<0 after decrement attempts to catch empty stack, but the damage (reading/writing s[-1]) has already been done. The check for empty should occur before any index access.]
                pf("error ");
            }else{
                pf("%d ",d);
            }
            
        }else if(a==-1){
            break;
        }
        
    }
}