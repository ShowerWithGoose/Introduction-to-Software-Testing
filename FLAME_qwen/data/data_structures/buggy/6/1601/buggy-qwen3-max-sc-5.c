#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int s[100]; // @@ [Stack size is 100, but indices go from 0 to 99. However, the code does not check for stack overflow during push.]
    int i=0;
    int a,b;
    while(scanf("%d",&a)==1){
        if(a==0&&i==0){
            printf("error ");
        }else if(a==1){
            scanf("%d",&b);
            s[i++]=b; // @@ [No check for stack full condition (i == 100). Pushing beyond capacity leads to buffer overflow.]
        }else{
            printf("%d ",s[i-1]); // @@ [When a is neither 0 nor 1 (e.g., -1), this else block executes, causing invalid pop or undefined behavior. Also, no check if i > 0 before popping in this branch.]
            i--;
        }
    }
    return 0;
 }