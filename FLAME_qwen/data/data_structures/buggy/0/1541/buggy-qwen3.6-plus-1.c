#include<stdio.h>
#include<string.h>
int main(){
char ch[100];
gets(ch); // @@ gets() is deprecated and removed in C11, which may cause compilation errors; use fgets() instead.
int i;
char j;
for(i=0;ch[i]!='\0';i++)
{if(ch[i]=='-')
 {if(ch[i-1]<ch[i+1]) // @@ Accessing ch[i-1] when i=0 causes out-of-bounds memory access; lacks boundary checks for i>0 and ch[i+1]!='\0'.
    {if((ch[i-1]<='9'&&ch[i-1]>='0'&&ch[i+1]<='9'&&ch[i+1]>='0')||(ch[i-1]<='z'&&ch[i-1]>='a'&&ch[i+1]<='z'&&ch[i+1]>='a')||(ch[i-1]<='Z'&&ch[i-1]>='A'&&ch[i+1]<='Z'&&ch[i+1]>='A'))
    {for(j=ch[i-1]+1;j<ch[i+1];j++)
    printf("%c",j);
    }
      }
 } // @@ Missing else branch to print '-' when expansion conditions fail, causing '-' to be omitted from the output.
 else
 printf("%c", ch[i]);
}
    return 0;
}