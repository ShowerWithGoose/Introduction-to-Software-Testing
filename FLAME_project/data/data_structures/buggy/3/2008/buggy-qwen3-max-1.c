#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000],c[1000];
    int n,i,j;
    gets(s); @@ [Using gets() is unsafe and may cause buffer overflow; also, the logic below assumes input format but doesn't handle all cases correctly]
    if(s[0]=='0'){
        for(i=2;s[i]=='0';i++){ @@ [This loop skips zeros after '0.', but if there are no zeros (e.g., "0.9"), i remains 2, leading to incorrect exponent calculation]
        }
        n=1-i; @@ [For input "0.9", i=2, so n = -1, which is correct, but later printing logic is flawed]
        printf("%d\n",i); @@ [This prints intermediate debug value 'i' (which is 2 for "0.9") instead of scientific notation, causing wrong output "2"]
        for(j=0;i<=strlen(s);j++,i++){ @@ [Loop condition should be i < strlen(s), not <=; also, this copies from s[i] including '\0', possibly adding garbage]
            c[j]=s[i];
        }
    }
    else{
        c[0]=s[0];
        c[1]='.';
        for(i=1;s[i]!='.';i++){ @@ [This loop tries to copy digits before '.', but if input has only one digit before '.', this loop doesn't run, leaving c[2] uninitialized]
            c[i+1]=s[i];
        }
        n=i-1;
        for(i=i+1;i<=strlen(s);i++){ @@ [Again, <= causes copying beyond string end; also, this overwrites c starting at position i, which may not align with previous writes]
            c[i]=s[i];
        }
        printf("%se%d",c,n); @@ [This prints correct format only for numbers >=1, but the branch for s[0]=='0' never reaches a proper print of scientific notation]
        return 0;
    }
}