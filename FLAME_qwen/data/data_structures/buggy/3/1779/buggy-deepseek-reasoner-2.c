#include<stdio.h>
 #include<string.h>

 int main()
 {
     char s[100];
     gets(s); // @@ Use of gets is unsafe and deprecated; in modern C, this may cause compilation error. Consider using scanf or fgets.
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
         for(int i=3;i<n;i++) // @@ Error: should start at i=2 (the first digit after the decimal point) to correctly process all digits, including potential leading zeros.
         {
             if(s[i]=='0')
             {
             p++;    
            }
            else
            {
                if(i==n-1)
                printf("%c",s[p+3]); // @@ Error: indexing is incorrect because the loop started at i=3 and p only counts zeros from index 3 onward. This may miss zero at index 2 and print wrong character.
                else
                    printf("%c.",s[p+3]); // @@ Same indexing issue.
                printf("%s",s+p+4); // @@ Error: the starting position for remaining digits is miscalculated due to incorrect p and offset.
                printf("e-%d",p+2); // @@ Error: exponent value is off because leading zeros from index 2 are not counted in p.
                break;
            }
        }
     return 0;
     
}