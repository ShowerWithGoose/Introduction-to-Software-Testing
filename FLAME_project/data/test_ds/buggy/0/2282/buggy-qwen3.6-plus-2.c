#include<stdio.h>
#include <string.h>
#include <ctype.h>
char str[1000];
int main()
{int i;
gets(str); // @@ gets is deprecated and removed in C11, causing implicit declaration warning/error; should use fgets or scanf instead.

char c;
int len=strlen(str);
for(i=0;i<len;i++)
{
if((str[i]=='-')&&(i>=1))
{ 
 if( (isdigit(str[i-1])!=0 )&&(isdigit(str[i+1])!=0) )&&( str[i-1]<str[i+1] )) // @@ Syntax error: extra closing parenthesis before '&&' causes mismatched parentheses and breaks the if statement structure.
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
 else if( (isupper(str[i-1])!=0 )&& (isupper(str[i+1])!=0) )&&( str[i-1]<str[i+1] )) // @@ Syntax error: extra closing parenthesis before '&&' causes mismatched parentheses and breaks the else if statement structure.
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