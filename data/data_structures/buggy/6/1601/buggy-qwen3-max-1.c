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
            s[i++]=b; @@ [Missing check for stack overflow: pushing when stack is full (i == 100) should output "error ", but code pushes unconditionally]
        }else{
            printf("%d ",s[i-1]); @@ [Missing check for valid pop operation: when a != 0 and a != 1 (e.g., -1), this else block executes incorrectly. Also, no handling for -1 to terminate loop early, causing -1 to be treated as pop]
            i--;
        }
    }
    return 0;
 }