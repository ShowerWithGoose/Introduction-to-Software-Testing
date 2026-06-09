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
     for(int i=3;i<n;i++) // @@ [Error: This loop assumes the input always has at least 3 characters before the decimal point, but for input like "0.9", the decimal point is at index 1, so i=3 skips the valid digit '9'. The logic for handling numbers less than 1 is incorrect.]
     {
         if(s[i]=='0')
         {
         p++;    
        }
        else
        {
            if(i==n-1)
            printf("%c",s[p+3]); // @@ [Error: Index p+3 is based on incorrect assumptions about input structure; for "0.9", p+3 would be out of bounds or point to wrong character.]
            else
                printf("%c.",s[p+3]); // @@ [Error: Same indexing issue; also, the logic for printing the base and exponent is flawed for numbers like 0.9.]
        printf("%s",s+p+4); // @@ [Error: s+p+4 points beyond the string for "0.9", causing undefined behavior or incorrect output.]
        printf("e-%d",p+2); // @@ [Error: The exponent calculation p+2 is wrong; for 0.9, the correct exponent should be -1, but p+2 gives 2.]
        break;
        }
     }
     return 0;
     
}