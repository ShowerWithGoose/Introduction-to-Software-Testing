#include<stdio.h>
#include <string.h>
#include <ctype.h>
char str[1000];
int main()
{int i;
gets(str); // @@ [Error: 'gets' is deprecated/removed in modern C standards and causes compilation warnings/errors. Should use fgets.]

char c;
int len=strlen(str);
for(i=0;i<len;i++)
{
if((str[i]=='-')&&(i>=1))
{ 
 if( (isdigit(str[i-1])!=0 )&&(isdigit(str[i+1])!=0) )&&( str[i-1]<str[i+1] )) // @@ [Error: Syntax error due to mismatched parentheses. There is an extra closing parenthesis after the second isdigit check and before the logical AND, causing "expected identifier" errors.]
 {c=str[i-1]+1;
  while(c<str[i+1])
  {printf("%c",c);
  c++;
  }
 }
 else if((islower(str[i-1])!=0)&&(islower(str[i+1])!=0) &&( str[i-1]<str[i+1] ))
 {c=str[i-1]+1;
  while(c<str[i+1])
  {printf("%c",c);
  c++;
  }
 }
 else if( (isupper(str[i-1])!=0 )&& (isupper(str[i+1])!=0) )&&( str[i-1]<str[i+1] )) // @@ [Error: Syntax error due to mismatched parentheses. Similar to line 15, there is an extra closing parenthesis breaking the if condition structure.]
 {c=str[i-1]+1;
  while(c<str[i+1])
  {printf("%c",c);
  c++;
  }
 }
 else {printf("%c",str[i]);
 }   
}    
else
{
printf("%c",str[i]);
    }    
}

return 0;
}