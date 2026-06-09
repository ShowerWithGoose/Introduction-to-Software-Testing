#include<stdio.h>
#include<string.h>
int main(){
char ch[100];
gets(ch);
int i;
char j;
for(i=0;ch[i]!='\0';i++)
{if(ch[i]=='-')
 {if(ch[i-1]<ch[i+1]) @@ The condition ch[i-1] < ch[i+1] is checked before verifying if the characters are of the same type. For input "B-e", 'B' < 'e' is true, so it enters the block, but since they are different types, it should not expand. This logic error causes the hyphen to be skipped (not printed) when it should be printed because the type check fails later or is bypassed.
    {if((ch[i-1]<='9'&&ch[i-1]>='0'&&ch[i+1]<='9'&&ch[i+1]>='0')||(ch[i-1]<='z'&&ch[i-1]>='a'&&ch[i+1]<='z'&&ch[i+1]>='a')||(ch[i-1]<='Z'&&ch[i-1]>='A'&&ch[i+1]<='Z'&&ch[i+1]>='A'))
    {for(j=ch[i-1]+1;j<ch[i+1];j++)
    printf("%c",j);
    }
      } 
 }
 else
 printf("%c", ch[i]);
}
    return 0;
}