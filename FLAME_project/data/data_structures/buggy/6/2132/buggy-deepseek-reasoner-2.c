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
            if(d>=0){printf("%d ",a[d]);d--;} // @@ Error: When d is the number of elements, the top element is at index d-1, not d. Also, when stack is empty (d==0), the condition d>=0 is true, causing an invalid access of a[0] and then d becomes -1. Correct condition should be d>0 and print a[d-1].
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}