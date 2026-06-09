#include<stdio.h>
#include <string.h>
#include <ctype.h>
char str[1000];
int main()
{int i;
gets(str); // @@ [implicit declaration of function 'gets'; it's unsafe and removed in modern C standards; also causes compilation warning/error]

char c;
int len=strlen(str);
for(i=0;i<len;i++)
{
if((str[i]=='-')&&(i>=1))
{ 
 if( (isdigit(str[i-1])!=0 )&&(isdigit(str[i+1])!=0) )&&( str[i-1]<str[i+1] )) // @@ [extra closing parenthesis before the second && causes syntax error: expected identifier before '(' token]
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
 else if( (isupper(str[i-1])!=0 )&& (isupper(str[i+1])!=0) )&&( str[i-1]<str[i+1] )) // @@ [extra closing parenthesis before the second && causes syntax error: expected identifier before '(' token]
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

return 0; // @@ [missing opening brace '{' for main function body causes this line to be outside any function, leading to 'expected identifier or '(' before return']
} // @@ [this closing brace does not match any function due to missing opening brace earlier]