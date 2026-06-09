#include <stdio.h>

void squeez(char s[],char c);

int main()
{
  int i=0,j=0;
  char s[512],s2[512];//两个字符串数组，一个放原来的，一个放补充的 
  gets(s);
  for(i=0;s[i]!='\0';i++){
    //把s[]传给s2[] 
    s2[j]=s[i];
    if(s[i+1]=='-'&&s[i]<s[i+2]&&((s[i]>='a'&&s[i]-1<'z'&&s[i+2]>'a'&&s[i+2]<='z')||(s[i]>='A'&&s[i]<'Z'&&s[i+2]>'A'&&s[i+2]<='Z') ||(s[i]>='0'&&s[i]<'9'&&s[i+2]>'0'&&s[i+2]<='9'))){
    //延长字符串
    char temp;
    temp=s[i];//把‘-’前的字符串赋给过渡值 
    while(temp<s[i+2]){
      temp++;
      j++;
      s2[j]=temp;
      }
      i=i+2;
    }
    j++; 
    
  } 
  s2[j]='\0';
  puts(s2);
  
    return 0;
}
// @@ [The condition checks for expansion are incorrect. Specifically: 
// (1) `s[i]-1<'z'` should be `s[i]<'z'` because we need to ensure the left char is less than 'z' to allow incrementing.
// (2) `s[i+2]>'a'` should be `s[i+2]>='a'` to include cases like a-b where right char is exactly 'b'.
// Similar issues exist for uppercase and digits: e.g., `s[i]<'Z'` excludes 'Z' as valid start, but 'Y-Z' should expand.
// Also, the loop processes only one '-' at a time and skips proper handling of multiple expansions like a-c-g.
// Additionally, using `gets()` is unsafe and may cause buffer overflow, though not directly causing WA here.]