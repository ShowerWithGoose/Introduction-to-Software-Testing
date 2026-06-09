#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int a[101];
int main(){
    int c,d=0,e=0,f=0;
    while(scanf("%d",&c)){ @@ [The condition should check for !=EOF to match the reference and handle input correctly; current condition may cause infinite loop or undefined behavior when scanf fails.]
        if(c==1){
            if(d<=99){scanf("%d",&a[d]);d++;}
            else printf("error ");
        }
        else if(c==0){
            if(d>=0){printf("%d ",a[d]);d--;} @@ [Accessing a[d] when d==0 leads to reading a[0] then decrementing, but after decrement d becomes -1; also, when stack is empty (d==0), it should print "error", not pop. Condition should be d>0. Additionally, a[d] is out-of-bounds when d==100, but here the bug is that when d==0, a[0] is printed even though stack is empty.]
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}