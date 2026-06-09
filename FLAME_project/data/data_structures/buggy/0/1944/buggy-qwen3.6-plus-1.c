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
            if(a<b&&((a<='9'&&a>='0'&&b<='9'&&b>='0')||(a<='Z'&&a>='A'&&b<='Z'&&b>='A')||(a<='z'&&a>='a'&&b<='z'&&b>='a'))){ // @@ The condition checks if types match, but 'B' (upper) and 'e' (lower) do not match. However, the logic here is actually correct for filtering. The error lies in the loop logic below or how the '-' is handled when expansion DOES NOT happen.
                for(k=1;k!=b-a;k++,j++) // @@ This loop condition `k!=b-a` is risky if b-a is 0 (handled by outer if) or negative. But more importantly, if the condition above is FALSE (like B-e), we skip this block.
                    t[j]=a+k;
            }
            j--; // @@ This line decrements j regardless of whether expansion happened. If expansion DID happen, j was incremented inside the loop. If expansion DID NOT happen (like B-e), j was incremented at the start of the for loop (t[j]=s[i]), so we need to decrement it to overwrite the '-' in the next iteration? No, if we don't expand, we want to keep the '-'. By decrementing j here, we are effectively removing the '-' from the output buffer `t` if we don't write over it. But wait, if we don't expand, we just want to keep the '-'. The next iteration will write to t[j] which is now the position of the '-'. This overwrites the '-' with the next character. This is why 'B-e' becomes 'Be'. The '-' is overwritten by 'e' because j is decremented.
        }
    }
    puts(t);
}