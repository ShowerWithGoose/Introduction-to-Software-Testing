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
         if(((start[i-1]<='Z'&&start[i-1]>='A')&&(start[i+1]<='Z'&&start[i+1]>='A'))||((start[i-1]<='z'&&start[i-1]>='a')&&(start[i+1]<='z'&&start[i+1]>='a'))||((start[i-1]<='9'&&start[i-1]>='0')&&(start[i+1]<='9'&&start[i+1]>='9'))) // @@ [The condition for digits is incorrect: it checks if start[i+1] <= '9' and >= '9', which only matches the character '9'. It should be >= '0'. Also, accessing start[i-1] and start[i+1] without checking bounds (e.g., when i=0 or i is last index) leads to undefined behavior.]
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
     {printf("%c",start[i]); // @@ [The program prints characters immediately instead of building the full output string. This causes out-of-order output when expansions occur, because expansion characters are printed in the middle of the loop while other characters are also being printed one by one. Additionally, when a '-' is not expanded, it's printed here, but if it is expanded, the surrounding characters may be mishandled (e.g., the character before '-' is not printed again, but it was already printed in a previous iteration).]
 }
 }
return 0;
}