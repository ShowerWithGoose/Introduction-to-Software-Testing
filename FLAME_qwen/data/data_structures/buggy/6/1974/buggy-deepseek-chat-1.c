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
            if(i==99){ // @@ The condition should be i >= 100 to check if the stack is full (max capacity 100). Using i==99 only catches the exact moment when 100 elements are already stored, but the stack can hold up to 100 elements (indices 0-99). When i==100, the stack is full, so the condition should be i >= 100.
                pf("error ");
            }else{
            s[i]=b;i++;}
        }else if(a==0){
            d=s[i-1];s[i-1]=0;i--; // @@ The pop operation decrements i before checking if the stack is empty. If i is 0, accessing s[i-1] (s[-1]) is out of bounds, and then i becomes -1, which is incorrect. The check for empty stack (i < 1) should be performed before accessing the stack and decrementing i.
            if(i<0){ // @@ This check is too late; the error condition should be checked before the pop operation. Also, the condition should be i < 0 (or i < 1 before decrement) to detect empty stack, but since i was already decremented, it should check if i < 0 after decrement, but the pop should not have happened.
                pf("error ");
            }else{
                pf("%d ",d);
            }
            
        }else if(a==-1){
            break;
        }
        
    }
}