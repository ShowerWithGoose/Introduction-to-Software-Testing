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
            s[i++]=b; // @@ [Missing check for stack overflow: pushing when stack is full (i == 100) should output "error ", but this code pushes unconditionally]
        }else{
            printf("%d ",s[i-1]); // @@ [Missing check for invalid operation: 'a' could be -1 or other values; also, when a == -1, it should terminate without popping, but this treats -1 as a pop]
            i--;
        }
    }
    return 0;
 }