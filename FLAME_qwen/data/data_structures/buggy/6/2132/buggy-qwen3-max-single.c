#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int a[101];
int main(){
    int c,d=0,e=0,f=0;
    while(scanf("%d",&c)){ // @@ [The loop condition should check for EOF (e.g., scanf(...) != EOF). As written, it will loop indefinitely on invalid input or EOF because scanf returns EOF (typically -1), which is non-zero and treated as true.]
        if(c==1){
            if(d<=99){scanf("%d",&a[d]);d++;} // @@ [Condition d<=99 allows d to reach 100, but array index a[100] is out of valid range (0-99) for a stack of max capacity 100. Should be d < 100. Also, no check if scanf succeeds after this.]
            else printf("error ");
        }
        else if(c==0){
            if(d>=0){printf("%d ",a[d]);d--;} // @@ [When d==0 (empty stack), accessing a[d] (i.e., a[0]) is invalid. Should check d > 0 before popping. Also, after printing a[d], d is decremented, but a[d] was accessed at current d, which is one past the top. Should access a[--d] or a[d-1].]
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}