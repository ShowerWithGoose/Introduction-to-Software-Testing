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
            printf("%d ",s[i-1]); // @@ [No check for invalid operation code; treats any non-0 and non-1 input as pop, which is incorrect. Also, when a==-1 (end marker), it incorrectly tries to pop]
            i--;
        }
    }
    return 0;
 }