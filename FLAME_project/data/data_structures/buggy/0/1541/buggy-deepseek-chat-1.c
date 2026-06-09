#include<stdio.h>
#include<string.h>
int main(){
char ch[100];
gets(ch);
int i;
char j;
for(i=0;ch[i]!='\0';i++)
{if(ch[i]=='-')
 {if(ch[i-1]<ch[i+1]) // @@ The condition checks if the character before '-' is less than the character after, but it does not verify that both characters are of the same type (e.g., both uppercase, both lowercase, or both digits). For input "B-e", 'B' and 'e' are different types, so no expansion should occur, but this condition passes, causing the program to incorrectly attempt expansion.
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