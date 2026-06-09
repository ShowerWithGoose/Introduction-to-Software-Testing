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
                for(k=1;k!=b-a;k++,j++) // @@ The loop condition `k!=b-a` is incorrect; it should be `k < b-a` to properly iterate through the characters to be inserted. Also, the increment `j++` inside the loop combined with the outer loop's `j++` causes `j` to be incremented twice per iteration, leading to incorrect indexing and skipping positions in the output array `t`.
                    t[j]=a+k;
            }
            j--; // @@ This decrement of `j` is incorrect. After processing the expansion, `j` should point to the last inserted character, but the outer loop will increment `j` again. The logic here causes `j` to be off by one, potentially overwriting or skipping characters.
        }
    }
    puts(t);
}