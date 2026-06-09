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
            if(i==99){ // @@ The stack capacity is 100, so the condition for a full stack should be i >= 100, not i == 99.
                pf("error ");
            }else{
            s[i]=b;i++;}
        }else if(a==0){
            d=s[i-1];s[i-1]=0;i--; // @@ Accessing s[i-1] when i=0 causes out-of-bounds memory access. The empty stack check should be performed before popping.
            if(i<0){ // @@ The check for an empty stack is performed after modifying i, which is logically incorrect and leads to undefined behavior.
                pf("error ");
            }else{
                pf("%d ",d);
            }
            
        }else if(a==-1){
            break;
        }
        
    }
}