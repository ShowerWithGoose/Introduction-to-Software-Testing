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
            if(i==1) printf("."); // @@ This line skips printing the digit at index 1 (c[1]), which should appear immediately after the decimal point in scientific notation. It should print '.' followed by c[1].
            else if (c[i]!='.')printf("%c",c[i]);
        }
        printf("e%d",flag-1);
    }     
    else
    {
        if(c[0]!='0') puts(c); // @@ Missing the exponent part "e0" for numbers with a single non-zero digit before the decimal point. Also, puts() appends a newline which may interfere with the expected output format. Should print the string followed by "e0".
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