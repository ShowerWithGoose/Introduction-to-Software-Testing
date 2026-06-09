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
 else @@ // The 'else' is misplaced—it should correspond to the case when expansion conditions are not met, but currently it only handles when ch[i] != '-', and fails to output '-' when expansion conditions fail.
 printf("%c", ch[i]); @@ // This line prints the current character (which is '-') only when it's not '-', which is contradictory. Also, when expansion conditions fail (e.g., B-e), the '-' should be printed, but the code skips it because the outer 'if(ch[i]=='-')' doesn't have an else to print '-' in failure cases.
 }
}
    return 0;
}