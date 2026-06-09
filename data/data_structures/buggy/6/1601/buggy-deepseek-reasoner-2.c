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
    while(scanf("%d",&a)==1){ // @@ Missing check for termination -1; loop should break when a == -1.
        if(a==0&&i==0){
            printf("error ");
        }else if(a==1){
            scanf("%d",&b);
            s[i++]=b; // @@ No check for stack full (i == 100); should output "error " and not push when full.
        }else{ // @@ This else incorrectly handles cases other than 0 and 1, including termination -1; should only handle pop (a == 0 with i > 0) and break on -1.
            printf("%d ",s[i-1]);
            i--;
        }
    }
    return 0;
 }