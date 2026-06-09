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
        }else if(a==-1){ // @@ The original code treats -1 as a pop operation because it falls into the final else block. It should break the loop when -1 is encountered.
            break;
        }else{ // @@ This block originally handled both 0 (pop) and -1 (end). Now it only handles 0.
            if(i > 0) { // @@ Added check to ensure stack is not empty before popping, although the first if handles i==0, this is safer logic structure matching the problem description for valid pops.
                 printf("%d ",s[i-1]);
                 i--;
            } else {
                 printf("error ");
            }
        }
    }
    return 0;
 }