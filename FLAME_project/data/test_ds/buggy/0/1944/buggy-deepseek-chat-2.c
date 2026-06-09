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
                for(k=1;k!=b-a;k++,j++) // @@ The loop condition `k!=b-a` is incorrect; it should be `k < b-a` to properly iterate through the characters between a and b. Also, the increment `j++` inside the loop causes j to be incremented twice per iteration (once in the loop and once in the for statement), leading to incorrect indexing.
                    t[j]=a+k;
            }
            j--; // @@ This decrement of j is incorrect. After processing the expansion, j should not be decremented because the loop's increment already handles the position. This causes the next character to overwrite the last expanded character.
        }
    }
    puts(t);
}