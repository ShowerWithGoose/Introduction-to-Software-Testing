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
        }else{
            printf("%d ",s[i-1]); // @@ [Error: This branch handles both pop (a==0) and end (-1) operations. When a==-1, it incorrectly prints the top element and decrements i, instead of terminating the loop. The condition should check for a==0 specifically before popping.]
            i--;
        }
    }
    return 0;
 }