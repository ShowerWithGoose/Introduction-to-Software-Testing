#include <stdio.h>
#include <string.h>
char c[99],b[30],a[99];
int main() 
{
    gets(c); // @@ [Compilation Error] 'gets' is removed in the C11 standard and causes compilation failure on modern compilers. Use 'fgets' or 'scanf' instead.
    int i,j=0,k,n;
    for(i=0; c[i]!='\0'; i++) 
    {
        n=0;
        if(c[i]=='-') 
        {
            if(c[i-1]<c[i+1]) // @@ [Logical/Runtime Error] Accessing c[i-1] when i=0 causes out-of-bounds memory access. Additionally, if expansion conditions fail, the '-' character is not copied to the output array 'a', violating the requirement to output the string unchanged.
            {
                k=c[i+1]-c[i-1]-1;

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ [Logical Error] This condition does not strictly verify that both characters are digits. It should explicitly check the range for both c[i-1] and c[i+1] (e.g., c[i-1]>='0' && c[i-1]<='9' && c[i+1]>='0' && c[i+1]<='9').
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') // @@ [Logical Error] Same issue: does not strictly verify that both characters are lowercase letters. Should check ranges for both sides.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') // @@ [Logical Error] Same issue: does not strictly verify that both characters are uppercase letters. Should check ranges for both sides.
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                }
            }
        }
        else
        {
            a[j]=c[i];
            j++;
        }
    }
    a[j]='\0';
    printf("%s",a);
    return 0;
}