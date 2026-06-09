#include<stdio.h>
#include<string.h>
int main(){
char ch[100];
gets(ch);
int i;
char j;
for(i=0;ch[i]!='\0';i++)
{if(ch[i]=='-')
 {if(ch[i-1]<ch[i+1]) // @@ Missing else branch to print '-' when left >= right, causing dash omission.
    {if((ch[i-1]<='9'&&ch[i-1]>='0'&&ch[i+1]<='9'&&ch[i+1]>='0')||(ch[i-1]<='z'&&ch[i-1]>='a'&&ch[i+1]<='z'&&ch[i+1]>='a')||(ch[i-1]<='Z'&&ch[i-1]>='A'&&ch[i+1]<='Z'&&ch[i+1]>='A')) // @@ Missing else branch to print '-' when types do not match, causing dash omission.
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