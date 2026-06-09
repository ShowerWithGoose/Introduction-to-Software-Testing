#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int a[101];
int main(){
    int c,d=0,e=0,f=0;
    while(scanf("%d",&c)){ // @@ scanf returns EOF (-1) on end of input, which evaluates to true in C, causing an infinite loop. It should check for EOF or ==1.
        if(c==1){
            if(d<=99){scanf("%d",&a[d]);d++;}
            else printf("error ");
        }
        else if(c==0){
            if(d>=0){printf("%d ",a[d]);d--);} // @@ d represents the index of the next free slot, so the top element is at d-1. Also, the stack is empty when d==0, so the condition should be d>0 to prevent accessing invalid memory and incorrect logic.
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}