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
 if( (isdigit(str[i-1])!=0 )&&(isdigit(str[i+1])!=0) )&&( str[i-1]<str[i+1] )) // @@ Syntax error: extra closing parenthesis after the first condition, causing the && to be outside the if condition. Should be: if( (isdigit(str[i-1])!=0) && (isdigit(str[i+1])!=0) && (str[i-1]<str[i+1]) )
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
 else if( (isupper(str[i-1])!=0 )&& (isupper(str[i+1])!=0) )&&( str[i-1]<str[i+1] )) // @@ Syntax error: same issue as line 15, extra closing parenthesis after the first condition. Should be: else if( (isupper(str[i-1])!=0) && (isupper(str[i+1])!=0) && (str[i-1]<str[i+1]) )
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