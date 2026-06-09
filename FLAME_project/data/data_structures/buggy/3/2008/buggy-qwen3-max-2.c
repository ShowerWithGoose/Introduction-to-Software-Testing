#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000],c[1000];
    int n,i,j;
    gets(s); @@ [Using gets() is unsafe and may cause buffer overflow; also, the logic below has multiple flaws]
    if(s[0]=='0'){
        for(i=2;s[i]=='0';i++){ @@ [This loop skips zeros after '0.', but if input is "0.9", s[2] is '9', so loop doesn't run, i remains 2]
        }
        n=1-i; @@ [For "0.9", i=2, so n = -1, which is correct exponent, but later logic fails to build mantissa properly]
        printf("%d\n",i); @@ [This prints '2' and adds a newline, which is wrong output; should not print anything here]
        for(j=0;i<=strlen(s);j++,i++){ @@ [Loop condition i<=strlen(s) causes reading beyond string end; also copies including '\0']
            c[j]=s[i];
        }
    }
    else{
        c[0]=s[0];
        c[1]='.';
        for(i=1;s[i]!='.';i++){ @@ [This loop assumes there are digits before '.', but if number is like "123.45", it copies digits before '.']
            c[i+1]=s[i];
        }
        n=i-1; @@ [Exponent calculation may be off by one depending on digit count]
        for(i=i+1;i<=strlen(s);i++){ @@ [Again, i<=strlen(s) accesses null terminator and beyond]
            c[i]=s[i];
        }
        printf("%se%d",c,n); @@ [This prints only in non-zero-leading case; for "0.9" this block is skipped]
        return 0;
    }
}