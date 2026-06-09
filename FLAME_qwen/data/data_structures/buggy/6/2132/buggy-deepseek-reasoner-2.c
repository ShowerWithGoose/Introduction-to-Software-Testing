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
            if(d<=99){scanf("%d",&a[d]);d++;} // @@ [push condition does not check for negative d, which can occur due to incorrect pop logic; writing to a[d] with d<0 is out-of-bounds]
            else printf("error ");
        }
        else if(c==0){
            if(d>=0){printf("%d ",a[d]);d--;} // @@ [pop logic is incorrect: when stack is empty (d==0), it should not pop; accessing a[0] is uninitialized and decrementing d to -1 leads to undefined behavior]
            else printf("error ");
        }
        else if(c==-1)break;
        getchar(); // @@ [unnecessary getchar() may consume input characters and is not present in the reference program; can cause issues with input parsing]
    }
    return 0;
}