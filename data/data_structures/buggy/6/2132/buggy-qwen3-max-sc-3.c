#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int a[101];
int main(){
    int c,d=0,e=0,f=0;
    while(scanf("%d",&c)){ // @@ [The loop condition should check for EOF to match the reference program and problem requirements. Using just `scanf(...)` as a condition may not terminate correctly on EOF, leading to undefined behavior or infinite loops.]
        if(c==1){
            if(d<=99){scanf("%d",&a[d]);d++;}
            else printf("error ");
        }
        else if(c==0){
            if(d>=0){printf("%d ",a[d]);d--;} // @@ [When d is 0 (stack empty), this still tries to access a[0] and decrements d to -1. The condition should be `if(d > 0)` to ensure stack isn't empty before popping. Also, it prints a[d] instead of a[d-1], which is incorrect indexing for a stack.]
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}