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
            s[i++]=b; // @@ [Error: No check for stack overflow. When i reaches 100, pushing another element will write beyond array bounds, causing undefined behavior. Should check if i < 100 before pushing.]
        }else{
            printf("%d ",s[i-1]); // @@ [Error: This branch handles both pop (a==0 when i>0) and end-of-input (a==-1). When a==-1, it incorrectly tries to pop from the stack, which is not the intended behavior. Should only pop when a==0 and i>0, and break or handle -1 separately.]
            i--;
        }
    }
    return 0;
 }