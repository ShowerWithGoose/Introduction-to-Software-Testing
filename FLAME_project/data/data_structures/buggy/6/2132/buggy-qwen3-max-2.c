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
            if(d>=0){printf("%d ",a[d]);d--;} // @@ [When d == 0 (stack empty), this condition still passes because d>=0 is true, leading to accessing a[0] which is invalid for an empty stack. It should check d > 0 instead. Also, after popping, it prints a[d] before decrementing d, but since d points to the next available slot, the top element is at a[d-1], not a[d].]
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}