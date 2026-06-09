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

     else
     for(int i=3;i<n;i++) @@ [The loop should start from index 2 because s[0] is '0' and s[1] is '.', so the first digit after the decimal point is at index 2]
     {
         if(s[i]=='0')
         {
         p++;    
        }
        else
        {
            if(i==n-1)
            printf("%c",s[p+3]); @@ [Incorrect index calculation; should use s[i] to print the first significant digit]
            else
                printf("%c.",s[p+3]); @@ [Incorrect index calculation; should use s[i] to print the first significant digit followed by a decimal point]
        printf("%s",s+p+4); @@ [Incorrect pointer arithmetic; should use s+i+1 to print the remaining digits after the first significant one]
        printf("e-%d",p+2); @@ [Incorrect exponent calculation; the exponent should be -(p+1) where p is the count of zeros after the decimal point]
        break;
        }
     }
     return 0;
     
}