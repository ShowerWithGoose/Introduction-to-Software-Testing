#include<stdio.h>
 #include<string.h>

 int main()
 {
     char s[100];
     gets(s); @@ [Using gets() is unsafe and may cause buffer overflow; however, the main logic errors are elsewhere.]
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
     for(int i=3;i<n;i++) @@ [This loop starts at index 3, assuming input format like "0.x...", but fails for "0.9" where significant digit is at index 2.]
     {
         if(s[i]=='0')
         {
         p++;    
        }
        else
        {
            if(i==n-1)
            printf("%c",s[p+3]); @@ [Incorrect indexing: for "0.9", p=0, so s[3] is out of bounds (string is "0.9\n" or "0.9" with len=3). Should use s[i].]
            else
                printf("%c.",s[p+3]); @@ [Same indexing error: should print s[i], not s[p+3].]
        printf("%s",s+p+4); @@ [This prints from s[p+4], which for "0.9" is beyond string length, causing undefined behavior or no output.]
        printf("e-%d",p+2); @@ [Exponent calculation is wrong. For "0.9", exponent should be -1, but p=0 → prints e-2.]
        break;
        }
     }
     return 0;
     
}