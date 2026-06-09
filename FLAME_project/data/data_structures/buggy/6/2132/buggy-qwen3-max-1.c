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
            if(d>=0){printf("%d ",a[d]);d--;} // @@ [When d is 0 (stack empty), accessing a[d] (i.e., a[0]) is invalid and should print "error". Also, after popping, d becomes -1, and next pop will access a[-1], which is undefined behavior. The condition should be d > 0, not d >= 0. Additionally, the popped element should be a[d-1], not a[d].]
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}