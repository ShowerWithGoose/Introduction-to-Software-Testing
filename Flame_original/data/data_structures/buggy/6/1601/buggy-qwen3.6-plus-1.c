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
    while(scanf("%d",&a)==1){ // @@ Does not check for the termination condition -1, causing the loop to process -1 as a pop operation instead of stopping.
        if(a==0&&i==0){
            printf("error ");
        }else if(a==1){
            scanf("%d",&b);
            s[i++]=b; // @@ Missing check for stack full condition (i == 100). Pushing when full causes array out-of-bounds and should output "error ".
        }else{ // @@ Incorrectly catches -1 and any other input, treating them as pop operations. Should explicitly handle a==0 for pop and break on a==-1.
            printf("%d ",s[i-1]);
            i--;
        }
    }
    return 0;
 }