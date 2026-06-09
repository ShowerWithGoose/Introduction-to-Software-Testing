#include<stdio.h>
#include <string.h>
#include <ctype.h>
char str[1000];
int main()
{int i;
gets(str);

char c;
int len=strlen(str);
for(i=0;i<len;i++)
{
if((str[i]=='-')&&(i>=1))
{ 
 if( (isdigit(str[i-1])!=0 )&&(isdigit(str[i+1])!=0) )&&( str[i-1]<str[i+1] )) // @@ [Syntax error: mismatched parentheses and extra '&&' outside the condition, causing "expected identifier before '('" and "expected statement before ')'"]
 {c=str[i-1]+1;
  while(c<str[i+1])
  {printf("%c",c);
  c++;
  }
 }
 else if((islower(str[i-1])!=0)&&(islower(str[i+1])!=0) &&( str[i-1]<str[i+1] )) // @@ [Syntax error: because previous 'if' condition is malformed, the compiler expects a '}' before this 'else', causing "expected '}' before 'else'"]
 {c=str[i-1]+1;
  while(c<str[i+1])
  {printf("%c",c);
  c++;
  }
 }
 else if( (isupper(str[i-1])!=0 )&& (isupper(str[i+1])!=0) )&&( str[i-1]<str[i+1] )) // @@ [Syntax error: similar to line 15, mismatched parentheses and extra '&&' outside the condition]
 {c=str[i-1]+1;
  while(c<str[i+1])
  {printf("%c",c);
  c++;
  }
 }
 else {printf("%c",str[i]); // @@ [Syntax error: this 'else' does not have a matching 'if' due to the malformed previous conditions, causing "else without a previous if"]
 }   
}    
else // @@ [Syntax error: this 'else' is placed after the closing brace of the outer 'if', making it orphaned; should be part of the outer 'if' but structure is broken]
{
printf("%c",str[i]);
    }    
}

return 0; // @@ [Syntax error: due to unmatched braces, the compiler expects an identifier or '(' before 'return']
} // @@ [Syntax error: same reason, expected identifier or '(' before '}']