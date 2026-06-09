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
            if(i<=0){ // @@ The check for empty stack (i <= 0) must happen BEFORE accessing the array element s[i-1]. In the original code, accessing s[i-1] when i is 0 leads to undefined behavior or incorrect logic, and the error message is printed after the invalid access. Also, the original logic decremented i before checking, which is incorrect for detecting underflow on an empty stack.
                pf("error ");
            }else{
                d=s[i-1];s[i-1]=0;i--; // @@ Move the pop operation (accessing element and decrementing index) to inside the else block, ensuring it only happens when the stack is not empty.
                pf("%d ",d);
            }
            
        }else if(a==-1){
            break;
        }
        
    }
}