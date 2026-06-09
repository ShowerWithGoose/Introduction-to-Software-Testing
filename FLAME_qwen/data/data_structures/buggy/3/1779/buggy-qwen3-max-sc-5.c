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
     for(int i=3;i<n;i++) // @@ [This loop assumes the input starts with "0.0...", but if the input is "0.x" where x is non-zero at position 2 (i.e., "0.5"), this loop starts at i=3 and skips the first non-zero digit, leading to incorrect output or no output. Also, variable 'i' is redeclared inside for-loop while already declared earlier, which may cause compilation error in C89/C90 mode.]
     {
         if(s[i]=='0')
         {
         p++;    
        }
        else
        {
            if(i==n-1)
            printf("%c",s[p+3]); // @@ [Incorrect indexing: 'p' counts zeros after "0.", but using 'p+3' assumes fixed prefix "0.0", which fails when there's only one zero after decimal (e.g., "0.05"). Should use 'i' directly instead of 'p+3'.]
            else
                printf("%c.",s[p+3]); // @@ [Same indexing error as above.]
        printf("%s",s+p+4); // @@ [Incorrect substring printing: 's+p+4' may go out of bounds or skip digits incorrectly due to wrong offset calculation.]
        printf("e-%d",p+2); // @@ [Exponent calculation is off: for "0.005", expected exponent is -3, but p=2 leads to e-4. Should be e-(p+2) only if counting from correct position; actual exponent should be -(number of places moved), which is i-1 (since "0." takes 2 chars).]
        break;
        }
     }
     return 0;
     
}