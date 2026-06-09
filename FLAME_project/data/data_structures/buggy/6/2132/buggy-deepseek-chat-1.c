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
            if(d<=99){scanf("%d",&a[d]);d++;} // @@ Error: The condition should be d < 100 to check if stack is full (max capacity 100). Using d <= 99 allows pushing when d=99, which is correct, but the pop logic below has an off-by-one error.
            else printf("error ");
        }
        else if(c==0){
            if(d>=0){printf("%d ",a[d]);d--;} // @@ Error: When d is 0, the stack is empty, but this condition allows popping when d=0, accessing a[0] which is invalid. Should check d > 0. Also, after decrement, d becomes -1, causing future pushes to overwrite a[-1] incorrectly.
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}