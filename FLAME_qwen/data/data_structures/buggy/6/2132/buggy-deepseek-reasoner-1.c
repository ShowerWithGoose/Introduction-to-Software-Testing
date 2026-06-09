#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int a[101];
int main(){
    int c,d=0,e=0,f=0;
    while(scanf("%d",&c)){ // @@ This while loop condition should check for EOF to avoid infinite loop; scanf returns EOF on end-of-file, which is non-zero, causing the loop to continue indefinitely.
        if(c==1){
            if(d<=99){scanf("%d",&a[d]);d++;}
            else printf("error ");
        }
        else if(c==0){
            if(d>=0){printf("%d ",a[d]);d--;} // @@ Error: Should check if stack is not empty (d>0) and print a[d-1] instead of a[d]. Current logic prints uninitialized value on empty stack and then decrements d to -1, causing subsequent operations to access negative index.
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}