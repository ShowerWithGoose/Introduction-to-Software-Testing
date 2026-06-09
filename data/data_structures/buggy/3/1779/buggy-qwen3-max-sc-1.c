#include<stdio.h>
 #include<string.h>

 int main()
 {
     char s[100];
     gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. It should be replaced with 'fgets'.]
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
     for(int i=3;i<n;i++) // @@ [This loop assumes the input always starts with "0.0...", but if the input is "0.123" (i.e., no leading zeros after decimal), this logic fails. Also, variable 'i' is redeclared inside the for-loop, which may shadow the outer 'i', though not a compilation error, it's logically flawed. However, the primary compilation issue stems from 'gets'.]
     {
         if(s[i]=='0')
         {
         p++;    
        }
        else
        {
            if(i==n-1)
            printf("%c",s[p+3]); // @@ [Incorrect indexing: 'p+3' may exceed array bounds or reference wrong character. Should use 'i' instead of 'p+3'. This is a logical error, but combined with unsafe 'gets', contributes to overall failure.]
            else
                printf("%c.",s[p+3]); // @@ [Same incorrect indexing as above.]
        printf("%s",s+p+4); // @@ [This prints from an incorrect offset and may print garbage or cause undefined behavior.]
        printf("e-%d",p+2);
        break;
        }
     }
     return 0;
     
}