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
            if(i==99){ // @@ Error: The stack capacity is 100, so the maximum index is 99. However, the condition should check if i >= 100 (or i == 100) because when i equals 100, the stack is full (indices 0-99 are used). The current condition i==99 incorrectly allows a push when the stack already has 100 elements (indices 0-99), causing overflow.
                pf("error ");
            }else{
            s[i]=b;i++;}
        }else if(a==0){
            d=s[i-1];s[i-1]=0;i--;
            if(i<0){ // @@ Error: The pop operation decrements i before checking if the stack is empty. When i is 0, s[i-1] accesses s[-1] which is out of bounds, and then i becomes -1. The check i<0 then catches the error, but the damage (out-of-bounds access) has already occurred. The correct order is to first check if i==0 (empty), then pop.
                pf("error ");
            }else{
                pf("%d ",d);
            }
            
        }else if(a==-1){
            break;
        }
        
    }
}