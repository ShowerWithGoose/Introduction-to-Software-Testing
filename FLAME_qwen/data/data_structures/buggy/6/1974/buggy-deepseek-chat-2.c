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
            if(i==99){ // @@ Error: The stack capacity is 100, so the condition should be i >= 100, not i == 99. Also, the array size is 108, but the maximum index for 100 elements is 99, so checking i == 99 incorrectly allows a 100th element (index 99) to be pushed, exceeding the intended capacity.
                pf("error ");
            }else{
            s[i]=b;i++;}
        }else if(a==0){
            d=s[i-1];s[i-1]=0;i--; // @@ Error: The pop operation decrements i before checking if the stack is empty. If i is 0, accessing s[-1] is out-of-bounds. The check for empty stack (i < 0) should be performed before accessing the array and decrementing i.
            if(i<0){
                pf("error ");
            }else{
                pf("%d ",d);
            }
            
        }else if(a==-1){
            break;
        }
        
    }
}