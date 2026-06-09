#include<stdio.h>
 #include<string.h>

 int main()
 {
     char s[100];
     gets(s);
     int n=strlen(s);
     int q=0,i=0,p=0;
    while(s[i]!='.')
    {
        q++;
        i++;
    }
     if(q>1)
     {
         printf("%c.",s[0]);
     for(int i=1;i<n;i++)
     {
         if(s[i]!='.')
         {
         printf("%c",s[i]);    
        }
     }
         printf("e");
         printf("%d",q-1);
     }
     else if(q==1&&s[0]!='0')
     {
         printf("%s",s);
         printf("e0");
     }

     else // @@ The logic for handling numbers less than 1 (like 0.9) is flawed. It enters this block but fails to correctly identify the first non-zero digit and construct the scientific notation properly. For "0.9", q is 1 and s[0] is '0', so it goes here. The loop starts at i=3, skipping s[1] ('.') and s[2] ('9'). It misses the significant digit entirely.
     for(int i=3;i<n;i++)
     {
         if(s[i]=='0')
         {
         p++;    
        }
        else
        {
            if(i==n-1)
            printf("%c",s[p+3]); // @@ Incorrect index calculation and logic for printing the significant digit and subsequent digits.
            else
                printf("%c.",s[p+3]); // @@ Incorrect formatting. It prints a dot after the digit if it's not the last character of the original string, which is not how scientific notation base works.
        printf("%s",s+p+4); // @@ Prints the rest of the string incorrectly, including potential trailing zeros or wrong characters.
        printf("e-%d",p+2); // @@ Exponent calculation is incorrect for the general case of 0.xxx...
        break;
        }
     }
     return 0;
     
}