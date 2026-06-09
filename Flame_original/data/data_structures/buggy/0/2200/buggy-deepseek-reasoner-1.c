#include <stdio.h>
#include <string.h>
int main()
{ int i,j,m; // @@ [Variables i, j, m are declared; okay]
int k[100000]; // @@ [Array size may be too large; could cause stack overflow but not necessarily a compilation error]
char start[1000000],end[1000000]; // @@ [end is unused; array sizes are extremely large, potential stack overflow]
 gets(start); // @@ [gets() is deprecated and removed in C11; using it may cause compilation error on modern compilers. Also it does not prevent buffer overflow. Use fgets instead.]
 m=0;
 for(i=0;i<strlen(start);i++) // @@ [strlen() called each iteration; inefficient but not an error; i is compared with size_t without cast, may generate warning]
 {   
     
     if((start[i]=='-')&&(start[i-1]<start[i+1])) // @@ [When i=0, start[i-1] accesses out-of-bounds memory (start[-1]), causing undefined behavior. Should check i>0 before accessing start[i-1].]
     {
         if(((start[i-1]<='Z'&&start[i-1]>='A')&&(start[i+1]<='Z'&&start[i+1]>='A'))||((start[i-1]<='z'&&start[i-1]>='a')&&(start[i+1]<='z'&&start[i+1]>='a'))||((start[i-1]<='9'&&start[i-1]>='0')&&(start[i+1]<='9'&&start[i+1]>='9'))) // @@ [Digit condition is wrong: (start[i+1]>='9') should be (start[i+1]>='0'). This causes digits like '0'-'8' to be incorrectly handled. Also note the same out-of-bounds issue for i=0.]
    {
        k[m]=i;
        m++;
        for(j=start[i-1]+1;j<start[i+1];j++)
        {
            printf("%c",j);
        }
    }
    else 
    {printf("%c",start[i]);
    }
     }
     else 
     {printf("%c",start[i]);
 }
 }
return 0;
}