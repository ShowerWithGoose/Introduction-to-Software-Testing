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
                for(k=1;k!=b-a;k++,j++) // @@ The loop condition `k!=b-a` may cause an infinite loop if `b-a` is negative or zero, and the increment of `j` inside the loop can lead to out-of-bounds access on `t`. Also, the loop logic does not correctly handle the expansion; it should iterate while `k < b-a` and properly update `j` and `t`.
                    t[j]=a+k;
            }
            j--;
        }
    }
    puts(t);
}