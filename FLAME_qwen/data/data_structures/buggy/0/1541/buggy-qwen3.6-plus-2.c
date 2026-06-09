#include<stdio.h>
#include<string.h>
int main(){
char ch[100];
gets(ch); // @@ `gets` is deprecated and removed in C11 standard, causing compilation errors in modern environments; use `fgets` instead.
int i;
char j;
for(i=0;ch[i]!='\0';i++)
{if(ch[i]=='-')
 {if(ch[i-1]<ch[i+1]) // @@ Potential out-of-bounds array access when `i==0` or `ch[i]` is the last character; should verify `i > 0 && ch[i+1] != '\0'` first.
    {if((ch[i-1]<='9'&&ch[i-1]>='0'&&ch[i+1]<='9'&&ch[i+1]>='0')||(ch[i-1]<='z'&&ch[i-1]>='a'&&ch[i+1]<='z'&&ch[i+1]>='a')||(ch[i-1]<='Z'&&ch[i-1]>='A'&&ch[i+1]<='Z'&&ch[i+1]>='A'))
    {for(j=ch[i-1]+1;j<ch[i+1];j++)
    printf("%c",j);
    }
      } // @@ Missing `else` branch to print the `-` character when expansion conditions are not met, causing `-` to be lost in the output.
 }
 else // @@ This `else` only corresponds to `if(ch[i]=='-')`, so `-` characters that fail expansion conditions are silently dropped instead of being printed.
 printf("%c", ch[i]);
}
    return 0;
}