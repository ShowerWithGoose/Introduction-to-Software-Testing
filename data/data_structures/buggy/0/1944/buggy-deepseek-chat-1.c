#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define eps 1e-8
    
int main()
{
    char s[100],a,b,t[100]={0};
    int i,j,k;
    gets(s);
    for(i=0,j=0;i<strlen(s);i++,j++){
        t[j]=s[i];
        if(s[i]=='-'){
            a=s[i-1];
            b=s[i+1];
            if(a<b&&((a<='9'&&a>='0'&&b<='9'&&b>='0')||(a<='Z'&&a>='A'&&b<='Z'&&b>='A')||(a<='z'&&a>='a'&&b<='z'&&b>='a'))){
                for(k=1;k!=b-a;k++,j++) // @@ The loop condition `k!=b-a` may cause an infinite loop if `b-a` is negative or zero, and the increment `j++` is misplaced; it should be `j++` inside the loop body, not in the for statement, to correctly fill the array.
                    t[j]=a+k;
            }
            j--; // @@ This decrement is incorrect; it should be `j--` only when expansion occurs to adjust for the extra increment in the for loop, but here it always executes, causing the array index to be off by one for non-expansion cases.
        }
    }
    puts(t);
}