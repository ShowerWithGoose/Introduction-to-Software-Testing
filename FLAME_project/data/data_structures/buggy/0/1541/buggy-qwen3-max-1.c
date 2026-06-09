#include<stdio.h>
#include<string.h>
int main(){
char ch[100];
gets(ch);
int i;
char j;
for(i=0;ch[i]!='\0';i++)
{if(ch[i]=='-')
 {if(ch[i-1]<ch[i+1])
    {if((ch[i-1]<='9'&&ch[i-1]>='0'&&ch[i+1]<='9'&&ch[i+1]>='0')||(ch[i-1]<='z'&&ch[i-1]>='a'&&ch[i+1]<='z'&&ch[i+1]>='a')||(ch[i-1]<='Z'&&ch[i-1]>='A'&&ch[i+1]<='Z'&&ch[i+1]>='A'))
    {for(j=ch[i-1]+1;j<ch[i+1];j++)
    printf("%c",j);
    }
      } 
 else @@ // The 'else' is incorrectly placed; it pairs with the inner 'if (ch[i-1]<ch[i+1])', but should output '-' when conditions fail. Also, when '-' is at start/end or types differ, it's not printed.
 printf("%c", ch[i]); @@ // This prints the current character only if it's not '-', but when it is '-', and expansion doesn't happen, the '-' itself is never printed due to flawed control flow.
 }
 else
 printf("%c", ch[i]);
}
    return 0;
}