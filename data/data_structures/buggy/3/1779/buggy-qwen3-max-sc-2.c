#include<stdio.h>
 #include<string.h>

 int main()
 {
     char s[100];
     gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers. It should be replaced with 'fgets'.]
     int n=strlen(s);
     int q=0,i=0,p=0;
    while(s[i]!='.') // @@ [If the input does not contain a decimal point, this loop will run past the end of the string, causing undefined behavior. The problem states that the input always has digits before and after the decimal point, but robustness is still expected. However, the primary error leading to compilation failure is the use of 'gets'.]
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
     for(int i=3;i<n;i++) // @@ [This loop assumes the number starts with "0.0...", but if the input is "0.1", then i=3 is beyond the string length, leading to incorrect behavior. Also, variable 'i' is redeclared in inner scopes, which is allowed in C99+, but combined with logic errors, it causes wrong output. However, the compilation error is due to 'gets'.]
     {
         if(s[i]=='0')
         {
         p++;    
        }
        else
        {
            if(i==n-1)
            printf("%c",s[p+3]); // @@ [Incorrect indexing: 'p' counts leading zeros after "0.", but using 'p+3' as index is flawed. For example, input "0.001" would have p=2 at i=4, then access s[5], which is out of bounds. This is a runtime/logic error, not compilation.]
            else
                printf("%c.",s[p+3]);
        printf("%s",s+p+4); // @@ [Same indexing issue; also, this prints the rest of the string starting from an incorrect offset, possibly causing garbage output or crashes. Again, not a compilation error.]
        printf("e-%d",p+2);
        break;
        }
     }
     return 0;
     
}