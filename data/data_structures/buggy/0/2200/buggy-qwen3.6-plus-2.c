#include <stdio.h>
#include <string.h>
int main()
{ int i,j,m;
int k[100000];
char start[1000000],end[1000000];
 gets(start); // @@ gets() is deprecated and removed in modern C standards, causing compilation errors; also unsafe for buffer overflows.
 m=0;
 for(i=0;i<strlen(start);i++)
 {   
     
     if((start[i]=='-')&&(start[i-1]<start[i+1])) // @@ Accessing start[i-1] when i=0 causes out-of-bounds memory access (undefined behavior).
     {
         if(((start[i-1]<='Z'&&start[i-1]>='A')&&(start[i+1]<='Z'&&start[i+1]>='A'))||((start[i-1]<='z'&&start[i-1]>='a')&&(start[i+1]<='z'&&start[i+1]>='a'))||((start[i-1]<='9'&&start[i-1]>='0')&&(start[i+1]<='9'&&start[i+1]>='9'))) // @@ Logical error: start[i+1]>='9' should be start[i+1]>='0' to correctly check the lower bound of the digit range.
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