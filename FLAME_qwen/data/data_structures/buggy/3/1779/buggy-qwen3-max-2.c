#include<stdio.h>
 #include<string.h>

 int main()
 {
     char s[100];
     gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers due to security risks. Should use 'fgets' instead.]
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
     for(int i=3;i<n;i++) // @@ [This loop assumes the input starts with "0.XXX", but if the input is just "0.0" or similar with all zeros after, the loop may not handle it correctly. Also, variable 'i' is redeclared inside loops, which is allowed in C99+, but the logic here is flawed for general cases. However, the primary compilation error is due to 'gets'.]
     {
         if(s[i]=='0')
         {
         p++;    
        }
        else
        {
            if(i==n-1)
            printf("%c",s[p+3]);
            else
                printf("%c.",s[p+3]);
        printf("%s",s+p+4);
        printf("e-%d",p+2);
        break;
        }
     }
     return 0;
     
}