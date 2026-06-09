#include<stdio.h>
 #include<string.h>

 int main()
 {
     char s[100];
     gets(s); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. Also, many modern compilers remove 'gets', leading to compilation error.]
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
     for(int i=3;i<n;i++)
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