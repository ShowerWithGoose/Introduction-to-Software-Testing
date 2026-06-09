#include<stdio.h>
 #include<string.h>

 int main()
 {
     char s[100];
     gets(s); // @@ [Using gets() is unsafe and deprecated; it can cause buffer overflow. Also, in many modern environments, gets() is not available, leading to compilation errors.]
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
     for(int i=3;i<n;i++) // @@ [This loop assumes the input starts with "0.0...", but if the input is "0.x" where x is non-zero at position 2 (i.e., "0.5"), this loop starts at i=3 and skips the first non-zero digit, leading to incorrect output or no output. Also, variable 'i' is redeclared inside for loops while already declared earlier, which may cause compilation error in C89 or warnings in stricter standards.]
     {
         if(s[i]=='0')
         {
         p++;    
        }
        else
        {
            if(i==n-1)
            printf("%c",s[p+3]); // @@ [Incorrect indexing: should use s[i] instead of s[p+3]; p counts leading zeros after "0.", but index calculation is wrong.]
            else
                printf("%c.",s[p+3]); // @@ [Same indexing error as above; also, this logic fails to handle cases where there's only one significant digit after zeros.]
        printf("%s",s+p+4); // @@ [Wrong pointer arithmetic; should print from s[i+1], not s+p+4. This leads to printing garbage or nothing.]
        printf("e-%d",p+2); // @@ [Exponent calculation is off; for "0.00xyz", exponent should be -(number of leading zeros + 1), but here it's p+2 which is incorrect.]
        break;
        }
     }
     return 0;
     
}