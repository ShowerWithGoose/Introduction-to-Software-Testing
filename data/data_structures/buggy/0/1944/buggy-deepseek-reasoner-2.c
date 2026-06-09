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
        t[j]=s[i]; // @@ [The '-' character is copied into the output array before expansion, but it should not appear in the final string. The code later tries to compensate with j--, but the '-' remains in the result.]
        if(s[i]=='-'){
            a=s[i-1]; // @@ [Potential out-of-bounds access if i==0, but assuming '-' is not at the start.]
            b=s[i+1]; // @@ [Potential out-of-bounds access if i==strlen(s)-1.]
            if(a<b&&((a<='9'&&a>='0'&&b<='9'&&b>='0')||(a<='Z'&&a>='A'&&b<='Z'&&b>='A')||(a<='z'&&a>='a'&&b<='z'&&b>='a'))){
                for(k=1;k!=b-a;k++,j++) // @@ [The loop condition `k != b-a` is correct for expanding from a+1 to b-1. However, because j is incremented inside the loop and then decremented after the loop, and the outer loop also increments j, the indexing becomes inconsistent. More importantly, the '-' itself is never removed.]
                    t[j]=a+k;
            }
            j--;
        }
    }
    puts(t);
}