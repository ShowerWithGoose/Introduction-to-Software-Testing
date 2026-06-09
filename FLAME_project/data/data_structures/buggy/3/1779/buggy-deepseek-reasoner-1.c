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
     for(int i=3;i<n;i++) @@ // Incorrect loop start index; should start at position after decimal point (i=2 for "0.9" but general case uses q+1). For "0.9", loop never executes causing no output.
     {
         if(s[i]=='0')
         {
         p++;    
        }
        else
        {
            if(i==n-1)
            printf("%c",s[p+3]); @@ // Incorrect indexing; should refer to first non-zero digit after decimal, e.g., s[q+1+p] where q is position of '.'.
            else
                printf("%c.",s[p+3]); @@ // Incorrect indexing; same issue.
        printf("%s",s+p+4); @@ // Incorrect pointer offset; should print from first non-zero digit onward, not from s+p+4.
        printf("e-%d",p+2); @@ // Incorrect exponent calculation; should be e-%d with exponent = -(p+1) for zero-count.
        break;
        }
     }
     return 0;
     
}