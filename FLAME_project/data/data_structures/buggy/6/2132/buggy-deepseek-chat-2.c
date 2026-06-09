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
            if(d<=99){scanf("%d",&a[d]);d++;} // @@ Error: The condition should check if the stack is full before pushing. The stack capacity is 100, so the maximum index is 99. However, when d equals 100, the stack is full, but the condition d<=99 allows pushing when d=99 (which is correct) but also when d=100? Actually d starts at 0, so after 100 pushes, d becomes 100. The condition d<=99 would be false when d=100, preventing overflow. But the logic is flawed because after pushing, d is incremented, so the next push checks d<=99 again. This is actually correct for capacity 100. However, the main issue is that when popping, the code accesses a[d] before decrementing d, which accesses the wrong element. See below.
            else printf("error ");
        }
        else if(c==0){
            if(d>=0){printf("%d ",a[d]);d--;} // @@ Error: When d is 0, the stack is empty, but the condition d>=0 allows popping. It should check if d>0 (i.e., stack not empty). Also, it prints a[d] before decrementing, but the top element is at index d-1. For example, after pushing 567, d=1. On pop, it prints a[1] which is uninitialized, then decrements d to 0. It should print a[d-1] first, then decrement.
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}