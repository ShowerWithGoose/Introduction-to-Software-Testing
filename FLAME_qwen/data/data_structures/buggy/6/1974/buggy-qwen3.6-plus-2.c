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
            if(i==99){ // @@ The stack capacity is 100, so the error condition for a full stack should be i >= 100. Checking i == 99 incorrectly limits the stack to 99 elements.
                pf("error ");
            }else{
            s[i]=b;i++;}
        }else if(a==0){
            d=s[i-1];s[i-1]=0;i--; // @@ This line accesses s[i-1] and decrements i before checking if the stack is empty. When i=0, this causes an out-of-bounds array access (s[-1]). The empty check must be performed first.
            if(i<0){ // @@ This check occurs after decrementing i. If the stack was empty (i=0), i becomes -1 here, triggering the error message, but the invalid memory access already happened. The condition should check i <= 0 before any pop operation.
                pf("error ");
            }else{
                pf("%d ",d);
            }
            
        }else if(a==-1){
            break;
        }
        
    }
}