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
            if(d>=0){printf("%d ",a[d]);d--;} // @@ [Error 1: When popping, it should print a[d-1] (the top element), not a[d]. Also, the check for empty stack should be d>0, not d>=0. If d is 0, the stack is empty, so accessing a[0] before decrementing or checking is incorrect logic for an empty stack pop. Specifically, if d=0, stack is empty. The current code prints a[0] which is uninitialized or garbage, then decrements d to -1.]
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}