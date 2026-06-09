#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int a[101];
int main(){
    int c,d=0,e=0,f=0;
    while(scanf("%d",&c)){
        if(c==1){
            if(d<=99){scanf("%d",&a[d]);d++;}
            else printf("error ");
        }
        else if(c==0){
            if(d>=0){printf("%d ",a[d]);d--;} // @@ Condition should be d>0, and should print a[d-1] then decrement, or decrement first then print a[d]. Current prints a[d] which is the next empty slot, causing wrong output and failure to detect empty stack.
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}