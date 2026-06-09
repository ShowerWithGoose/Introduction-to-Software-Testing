#include<stdio.h>
#include<string.h>
int main(){
char ch[100];
gets(ch);
int i;
char j;
for(i=0;ch[i]!='\0';i++)
{if(ch[i]=='-')
 {if(ch[i-1]<ch[i+1]) // @@ [When i=0, ch[i-1] accesses index -1, causing undefined behavior; also, the condition does not check if ch[i+1] exists (i+1 may be out of bounds)]
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