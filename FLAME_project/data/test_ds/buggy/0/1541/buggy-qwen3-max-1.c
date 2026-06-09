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
 else
 printf("%c", ch[i]); @@ [When the '-' is not part of a valid expansion (e.g., B-e), the program should output the '-' as-is, but this code skips printing '-' entirely in such cases because the 'else' only prints non-'-' characters. The '-' character is never printed when it fails the expansion conditions.]
 }
 else
 printf("%c", ch[i]);
}
    return 0;
}