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
            if(i==99){ // @@ Incorrect stack-full condition. Should be i>=100 (or i==100) to properly check for full stack with capacity 100.
                pf("error ");
            }else{
            s[i]=b;i++;}
        }else if(a==0){
            d=s[i-1];s[i-1]=0;i--; // @@ Accesses stack element s[i-1] and decrements i before checking if stack is empty. This causes out-of-bounds access when i is 0, and also corrupts the stack state.
            if(i<0){ // @@ Condition checked after decrement, but the damage (out-of-bounds access) has already occurred. The emptiness check should be performed before accessing the stack.
                pf("error ");
            }else{
                pf("%d ",d);
            }
            
        }else if(a==-1){
            break;
        }
        
    }
}