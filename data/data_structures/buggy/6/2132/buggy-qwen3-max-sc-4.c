#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int a[101];
int main(){
    int c,d=0,e=0,f=0;
    while(scanf("%d",&c)){ @@ [The condition should check for !=EOF to match the reference program and correctly detect end of input; using just scanf(...) as condition may not handle EOF properly, leading to infinite loop or undefined behavior.]
        if(c==1){
            if(d<=99){scanf("%d",&a[d]);d++;}
            else printf("error ");
        }
        else if(c==0){
            if(d>=0){printf("%d ",a[d]);d--;} @@ [When d==0 (stack empty), this still tries to access a[0] and decrements d to -1. It should check d>0 instead of d>=0 to avoid popping from empty stack. Also, it prints a[d] before decrementing, which accesses one element past the top (off-by-one error). Should print a[--d] or a[d-1] after proper bounds check.]
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}