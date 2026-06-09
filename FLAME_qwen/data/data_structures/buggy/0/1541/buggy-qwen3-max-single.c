#include<stdio.h>
#include<string.h>
int main(){
char ch[100];
gets(ch); // @@ [Using gets() is unsafe and may cause compilation errors or warnings in modern compilers; it was removed in C11. Also, the program does not handle cases where '-' appears at the start or end of the string, leading to out-of-bounds access (e.g., ch[i-1] when i=0).]
int i;
char j;
for(i=0;ch[i]!='\0';i++)
{if(ch[i]=='-')
 {if(ch[i-1]<ch[i+1]) // @@ [Accessing ch[i-1] when i=0 (i.e., '-' at start) or ch[i+1] when '-' is at the end leads to undefined behavior due to out-of-bounds array access.]
    {if((ch[i-1]<='9'&&ch[i-1]>='0'&&ch[i+1]<='9'&&ch[i+1]>='0')||(ch[i-1]<='z'&&ch[i-1]>='a'&&ch[i+1]<='z'&&ch[i+1]>='a')||(ch[i-1]<='Z'&&ch[i-1]>='A'&&ch[i+1]<='Z'&&ch[i+1]>='A'))
    {for(j=ch[i-1]+1;j<ch[i+1];j++) // @@ [Loop variable j is of type char; if ch[i+1] - ch[i-1] is large, this may cause infinite loop or unexpected behavior due to char overflow. Also, same out-of-bounds issue as above.]
    printf("%c",j);
    }
      } 
 }
 else
 printf("%c", ch[i]);
}
    return 0;
}