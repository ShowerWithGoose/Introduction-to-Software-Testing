#include <stdio.h>
#include <string.h>
int main()
{ int i,j,m;
int k[100000];
char start[1000000],end[1000000];
 gets(start); // @@ gets() is removed in the C11 standard and causes a compilation error in modern compilers; use fgets() or scanf() instead.
 m=0;
 for(i=0;i<strlen(start);i++)
 {   
     
     if((start[i]=='-')&&(start[i-1]<start[i+1])) // @@ Accessing start[i-1] when i=0 causes an out-of-bounds read; should verify i>0 and i<strlen(start)-1 before accessing neighbors.
     {
         if(((start[i-1]<='Z'&&start[i-1]>='A')&&(start[i+1]<='Z'&&start[i+1]>='A'))||((start[i-1]<='z'&&start[i-1]>='a')&&(start[i+1]<='z'&&start[i+1]>='a'))||((start[i-1]<='9'&&start[i-1]>='0')&&(start[i+1]<='9'&&start[i+1]>='9'))) // @@ Typo: start[i+1]>='9' should be start[i+1]>='0' to correctly check the lower bound of the digit range.
    {
        k[m]=i;
        m++;
        for(j=start[i-1]+1;j<start[i+1];j++) // @@ Logical error: The loop only prints intermediate characters and misses the start and end characters of the expansion range.
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