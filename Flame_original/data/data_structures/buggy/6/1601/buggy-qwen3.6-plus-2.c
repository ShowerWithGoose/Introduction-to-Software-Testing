#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int s[100];
    int i=0;
    int a,b;
    while(scanf("%d",&a)==1){
        if(a==0&&i==0){
            printf("error ");
        }else if(a==1){
            scanf("%d",&b);
            s[i++]=b; // @@ Missing check for stack full (i==100), causing array out-of-bounds and failing to output "error " when full.
        }else{
            printf("%d ",s[i-1]); // @@ Incorrectly handles -1 (end of operations) as a pop operation; should break or ignore -1.
            i--; // @@ Incorrectly decrements stack pointer when a==-1, modifying state after termination signal.
        }
    }
    return 0;
 }