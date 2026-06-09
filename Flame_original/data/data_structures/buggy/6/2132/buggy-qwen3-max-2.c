#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int a[101];
int main(){
    int c,d=0,e=0,f=0;
    while(scanf("%d",&c)){ // @@ [The loop condition should check for EOF or input failure; using just scanf(...) as condition leads to infinite loop on invalid input or EOF because it returns 0 (not EOF) when no items are read, which is still truthy in C. The reference uses !=EOF correctly.]
        if(c==1){
            if(d<=99){scanf("%d",&a[d]);d++;} // @@ [This allows d to become 100, which is okay since array size is 101 (indices 0-100), but the condition should be d < 100 to prevent overflow beyond capacity of 100 elements. Also, no error printed if push on full stack beyond 100.]
            else printf("error ");
        }
        else if(c==0){
            if(d>=0){printf("%d ",a[d]);d--;} // @@ [When d==0 (empty stack), this accesses a[0] and then decrements d to -1, which is wrong. Should check d>0 before popping. Also prints garbage when stack is empty instead of "error ".]
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}