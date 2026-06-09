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
     for(int i=3;i<n;i++) // @@ [Error: This loop assumes the input always has at least 3 characters before the decimal point, but for input like "0.9", the decimal point is at index 1, so starting from i=3 skips valid digits and may cause out-of-bounds access or incorrect output.]
     {
         if(s[i]=='0')
         {
         p++;    
        }
        else
        {
            if(i==n-1)
            printf("%c",s[p+3]); // @@ [Error: Index p+3 may be out of bounds or incorrect for inputs like "0.9", where p+3 could exceed the string length or point to wrong character.]
            else
                printf("%c.",s[p+3]); // @@ [Error: Same index issue as above; also the logic for handling the decimal point and exponent is flawed for numbers like "0.9".]
        printf("%s",s+p+4); // @@ [Error: s+p+4 may be out of bounds or point to garbage for short strings like "0.9".]
        printf("e-%d",p+2); // @@ [Error: The exponent calculation p+2 is incorrect for "0.9"; it should be -1, but p+2 gives 2.]
        break;
        }
     }
     return 0;
     
}