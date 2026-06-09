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
                    t[j]=a+k; // @@ [This loop writes the expanded characters but overwrites the '-' and the next character incorrectly. Also, after expansion, the next character (b) is never appended, leading to missing characters. Additionally, j-- at the end causes misalignment in output indexing.]
            }
            j--; // @@ [This decrement causes the next character (after '-') to be overwritten or skipped incorrectly, especially when no expansion occurs. It also interferes with proper copying of unexpanded segments like in "B-e".]
        }
    }
    puts(t);
}