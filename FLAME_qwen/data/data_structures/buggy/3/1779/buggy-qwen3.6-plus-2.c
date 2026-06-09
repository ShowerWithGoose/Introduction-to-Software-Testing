#include<stdio.h>
 #include<string.h>

 int main()
 {
     char s[100];
     gets(s); // @@ gets() is removed in the C11 standard and causes compilation errors in modern environments; use scanf("%s", s) or fgets() instead.
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

     else
     for(int i=3;i<n;i++) // @@ Loop should start at index 2 to check the first digit after the decimal point; starting at 3 skips it and causes incorrect parsing for numbers like 0.123.
     {
         if(s[i]=='0')
         {
         p++;    
        }
        else
        {
            if(i==n-1)
            printf("%c",s[p+3]); // @@ Index calculation is incorrect; should use s[i] to print the first significant digit found.
            else
                printf("%c.",s[p+3]); // @@ Index calculation is incorrect; should use s[i] to print the first significant digit.
        printf("%s",s+p+4); // @@ Pointer offset is incorrect; should be s+i+1 to correctly print the remaining digits after the decimal point.
        printf("e-%d",p+2); // @@ Exponent calculation is incorrect; for 0.00...0d, the exponent should be -(p+1), not p+2.
        break;
        }
     }
     return 0;
     
}