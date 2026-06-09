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
            if(d>=0){printf("%d ",a[d]);d--;} // @@ [Error 1: When popping, it should print a[d-1] (the top element), not a[d]. Also, the condition d>=0 allows popping from an empty stack (when d=0), which should output "error". Correct logic: if(d>0) { d--; printf("%d ", a[d]); } else { printf("error "); }]
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}