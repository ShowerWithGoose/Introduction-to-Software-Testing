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
                for(k=1;k!=b-a;k++,j++)
                    t[j]=a+k; // @@ [This loop writes expansion characters but overwrites the '-' and potentially skips handling of subsequent characters correctly. Also, after expansion, the next character (b) is not copied because the outer loop increments i and j, leading to missing the character after '-'.]
            }
            j--; // @@ [This decrement attempts to adjust index but causes incorrect positioning; especially when no expansion occurs, it leads to overwriting or skipping characters. For example, in "B-e", since expansion condition fails, j-- causes the '-' to be overwritten by the next character, resulting in "Be" instead of "B-e".]
        }
    }
    puts(t);
}