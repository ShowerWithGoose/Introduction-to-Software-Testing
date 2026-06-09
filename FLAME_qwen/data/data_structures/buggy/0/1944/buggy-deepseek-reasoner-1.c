#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define eps 1e-8
    
int main()
{
    char s[100],a,b,t[100]={0};
    int i,j,k;
    gets(s); // @@ Unsafe function, may cause buffer overflow, but not the main logical error.
    for(i=0,j=0;i<strlen(s);i++,j++){
        t[j]=s[i]; // @@ When s[i] is '-', this unconditionally copies the dash, but it should not be copied if expansion occurs (the dash should be removed).
        if(s[i]=='-'){
            a=s[i-1]; // @@ Potential out-of-bounds access if i==0 (string starts with '-').
            b=s[i+1]; // @@ Potential out-of-bounds access if i==strlen(s)-1 (string ends with '-').
            if(a<b&&((a<='9'&&a>='0'&&b<='9'&&b>='0')||(a<='Z'&&a>='A'&&b<='Z'&&b>='A')||(a<='z'&&a>='a'&&b<='z'&&b>='a'))){
                for(k=1;k!=b-a;k++,j++)
                    t[j]=a+k;
            }
            j--; // @@ Always executed, even when expansion fails (should not decrement j if dash is kept) or when expansion succeeds (incorrectly adjusts index, leaving the dash in place and overwriting last expanded character).
        }
    }
    puts(t);
}