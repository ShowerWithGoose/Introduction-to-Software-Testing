#include <stdio.h>
#include <string.h>
int main()
{ int i,j,m;
int k[100000];
char start[1000000],end[1000000];
 gets(start);
 m=0;
 for(i=0;i<strlen(start);i++)
 {   
     
     if((start[i]=='-')&&(start[i-1]<start[i+1]))
     {
         if(((start[i-1]<='Z'&&start[i-1]>='A')&&(start[i+1]<='Z'&&start[i+1]>='A'))||((start[i-1]<='z'&&start[i-1]>='a')&&(start[i+1]<='z'&&start[i+1]>='a'))||((start[i-1]<='9'&&start[i-1]>='0')&&(start[i+1]<='9'&&start[i+1]>='9'))) // @@ The condition `start[i+1]>='9'` is incorrect. It should be `start[i+1]>='0'` to check if the character is a digit. Currently, it only allows '9' as the end character, causing ranges like '0-8' to fail the type check and fall through to printing the hyphen unchanged.
    {
        k[m]=i;
        m++;
        for(j=start[i-1]+1;j<start[i+1];j++)
        {
            printf("%c",j);
        }
    }
    else 
    {printf("%c",start[i]); // @@ This prints the '-' character when the types don't match or the range is invalid, which is correct behavior for non-expansion cases, but the logic above failed to identify valid digit expansions due to the previous error.
    }
     }
     else 
     {printf("%c",start[i]);
 }
 }
return 0;
}