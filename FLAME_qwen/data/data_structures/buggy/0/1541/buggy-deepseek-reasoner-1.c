#include<stdio.h>
#include<string.h>
int main(){
char ch[100];
gets(ch); // @@ gets is unsafe and may cause compilation error in C11; also no bound check.
int i;
char j;
for(i=0;ch[i]!='\0';i++)
{if(ch[i]=='-')
 {if(ch[i-1]<ch[i+1]) // @@ potential out-of-bounds access when i=0 or i is last index; also need to handle out-of-bounds.
    {if((ch[i-1]<='9'&&ch[i-1]>='0'&&ch[i+1]<='9'&&ch[i+1]>='0')||(ch[i-1]<='z'&&ch[i-1]>='a'&&ch[i+1]<='z'&&ch[i+1]>='a')||(ch[i-1]<='Z'&&ch[i-1]>='A'&&ch[i+1]<='Z'&&ch[i+1]>='A'))
    {for(j=ch[i-1]+1;j<ch[i+1];j++)
    printf("%c",j);
    }
      }  // @@ this closing brace ends the type-checking if; there is no else to print the dash when expansion condition fails.
 }
 else
 printf("%c", ch[i]);
}
    return 0;
}