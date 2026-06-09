#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 
#define eps 1e-6 
char c[1000];

int main() {
    gets(c);
    int s=strlen(c);int flag;
    for(int i=0;i<s;i++)
    {
        if(c[i]=='.') 
        {
            flag=i;break;
        }
    }
    if(flag!=1) 
    {
        for(int i=0;i<s;i++)
        {
            if(i==1) printf("."); // @@ [Logic Error: This condition assumes the decimal point is always at index 1 after shifting, but it incorrectly places the decimal point. For input "87899...", flag=5. The loop prints characters. When i==1, it prints '.', effectively inserting a decimal point after the first character '8'. However, it also prints the original character at index 1 ('7') in the else branch if i!=1. Wait, if i==1, it prints "." and skips the else. So output starts "8.". Then i=2, prints c[2]='8'. i=3, prints c[3]='9'. i=4, prints c[4]='9'. i=5 is '.', skipped. i=6 prints '9'... The resulting mantissa is "8.8999...". The original digit at index 1 ('7') is completely missing from the output because when i==1, it prints '.' instead of c[1]. It should print c[0], then '.', then the rest of the digits excluding the original decimal point.]
            else if (c[i]!='.')printf("%c",c[i]);
        }
        printf("e%d",flag-1);
    }     
    else
    {
        if(c[0]!='0') puts(c);
        else
        {
            int count=0;
            for(int i=0;i<s;i++)
            {
                if(c[i]=='0') count++;
                else if(c[i]>='1'&&c[i]<='9')
                {
                    flag=i;break;
                }
            }
            printf("%c",c[flag]);
            if(flag!=s-1)
            {
                printf(".");
                for(int i=flag+1;i<s;i++)
                {
                    printf("%c",c[i]);
                }    
                printf("e-%d",count);
            }
                
            else printf("e-%d",count);
        }
    }
    
return 0;
}