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
            if(d<=99){scanf("%d",&a[d]);d++;} // @@ Error: The condition should check if the stack is full (d == 100) before pushing. Using d <= 99 allows pushing when d is 99, but after increment, d becomes 100, which is out of bounds (array size is 101, indices 0-100). Also, the pop condition below has a similar issue.
            else printf("error ");
        }
        else if(c==0){
            if(d>=0){printf("%d ",a[d]);d--;} // @@ Error: The condition should check if the stack is empty (d == 0) before popping. Using d >= 0 allows popping when d is 0, which accesses a[0] (valid index) but then decrements d to -1, causing out-of-bounds access on next pop. Also, the pop should access a[d-1] before decrementing, not a[d].
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}