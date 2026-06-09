#include <stdio.h>

void squeez(char s[],char c);

int main()
{
  int i=0,j=0;
  char s[512],s2[512];//两个字符串数组，一个放原来的，一个放补充的 
  gets(s); // @@ deprecated, but not a core error
  for(i=0;s[i]!='\0';i++){
    //把s[]传给s2[] 
    s2[j]=s[i]; // @@ error: copies all characters, including dashes that are part of expansion patterns, leading to extra dashes in output
    if(s[i+1]=='-'&&s[i]<s[i+2]&&((s[i]>='a'&&s[i]-1<'z'&&s[i+2]>'a'&&s[i+2]<='z')||(s[i]>='A'&&s[i]<'Z'&&s[i+2]>'A'&&s[i+2]<='Z') ||(s[i]>='0'&&s[i]<'9'&&s[i+2]>'0'&&s[i+2]<='9'))){ // @@ error: incorrect type range conditions (e.g., s[i]-1<'z', s[i]<'Z', s[i]<'9'), and no bounds check for s[i+2] causing potential out-of-bounds access
    //延长字符串
    char temp;
    temp=s[i];//把‘-’前的字符串赋给过渡值 
    while(temp<s[i+2]){
      temp++;
      j++;
      s2[j]=temp;
      }
      i=i+2; // @@ error: after expansion, skips both the dash and the following character, but the following character may be needed as the left side of the next expansion (e.g., "a-c-e"), resulting in missed patterns
    }
    j++; 
    
  } 
  s2[j]='\0';
  puts(s2);
  
    return 0;
}