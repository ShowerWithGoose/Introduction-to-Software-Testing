#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int a[101];
int main(){
    int c,d=0,e=0,f=0;
    while(scanf("%d",&c)){ // @@ [The loop condition should check for EOF (e.g., scanf(...) != EOF). As written, it will loop indefinitely on non-integer input or EOF because scanf returns EOF (typically -1), which is non-zero and treated as true.]
        if(c==1){
            if(d<=99){scanf("%d",&a[d]);d++;} // @@ [This allows d to reach 100, which is beyond the valid index range (0-99) for a stack of max capacity 100. Should be d < 100 or d <= 99 before incrementing, but after storing, d becomes 100 which is okay as size, but next push would overflow. However, more critically, the pop logic below has a serious bug.]
            else printf("error ");
        }
        else if(c==0){
            if(d>=0){printf("%d ",a[d]);d--;} // @@ [When d == 0 (empty stack), this accesses a[0] which is invalid (should be a[d-1]), and then decrements d to -1. It should check d > 0, then print a[d-1] and decrement. Accessing a[d] when d==0 reads uninitialized or wrong data, and when d becomes negative, future pops will access invalid memory. Also, condition d>=0 is always true initially, so it never prints "error" for empty stack.]
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}