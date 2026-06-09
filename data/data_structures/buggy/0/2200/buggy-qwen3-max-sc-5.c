#include <stdio.h>
#include <string.h>
int main()
{ int i,j,m;
int k[100000];
char start[1000000],end[1000000];
 gets(start); // @@ [Using gets() is unsafe and deprecated; it was removed in C11 and may cause compilation errors or warnings with modern compilers. Use fgets() instead.]
 m=0;
 for(i=0;i<strlen(start);i++)
 {   
     
     if((start[i]=='-')&&(start[i-1]<start[i+1]))
     {
         if(((start[i-1]<='Z'&&start[i-1]>='A')&&(start[i+1]<='Z'&&start[i+1]>='A'))||((start[i-1]<='z'&&start[i-1]>='a')&&(start[i+1]<='z'&&start[i+1]>='a'))||((start[i-1]<='9'&&start[i-1]>='0')&&(start[i+1]<='9'&&start[i+1]>='9'))) // @@ [The last condition has a typo: 'start[i+1]>='9'' should be 'start[i+1]>='0''. This causes digits to never match because it checks if the next char is >= '9' AND <= '9', which only matches '9', breaking expansion like '0-9'.]
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