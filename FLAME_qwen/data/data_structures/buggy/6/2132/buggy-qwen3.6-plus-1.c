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
            if(d>=0){printf("%d ",a[d]);d--;} // @@ The condition should be d>0 to check for an empty stack, and a[d] accesses the next free slot instead of the top element; it should be a[d-1] or d should be decremented before printing.
            else printf("error ");
        }
        else if(c==-1)break;
        getchar(); // @@ getchar() consumes a character from the input buffer, which may incorrectly consume digits or cause synchronization issues with scanf; it should be removed as scanf automatically skips whitespace.
    }
    return 0;
}