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
            s[i++]=b;
        }else if(a==-1){ // @@ The original code treats -1 as a pop operation because it falls into the final else block. It should break the loop or be ignored as per problem description (-1 represents end of operations).
            break;
        }else{ // @@ This else block handles pop operations (when a==0 and stack is not empty) but also incorrectly handles -1 if the previous check is missing. With the fix above, this handles valid pops.
            printf("%d ",s[i-1]);
            i--;
        }
    }
    return 0;
 }