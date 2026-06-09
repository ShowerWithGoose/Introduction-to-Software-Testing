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
            s[i++]=b; // @@ [No check for stack overflow; pushing when stack is full (i == 100) leads to buffer overflow]
        }else{
            printf("%d ",s[i-1]); // @@ [No check for invalid operation code; non-0, non-1 inputs (like -1) are treated as pop operations]
            i--; // @@ [Popping when stack is empty (i == 0) is not checked here because the only empty check is for a == 0; but if a is -1 and i == 0, this causes underflow]
        }
    }
    return 0;
 }