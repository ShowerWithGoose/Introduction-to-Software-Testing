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
// @@ [The condition checks in the if-statement are logically incorrect. Specifically: (1) `s[i]-1<'z'` should be `s[i]<'z'` to ensure the left character is within 'a' to 'y' (so that expansion is possible). Similarly, `s[i+2]>'a'` should be `s[i+2]>'a'` is redundant and wrong; it should just ensure `s[i+2] <= 'z'`. The same applies to uppercase and digits: `s[i]<'Z'` excludes 'Z', which is correct, but `s[i+2]>'A'` is unnecessary and causes valid cases like A-C to fail. Also, digit range checks use `s[i]<'9'`, which excludes '9', but more critically, `s[i+2]>'0'` excludes expansions starting from '0'. These flawed boundary checks cause valid expansions like a-c or 0-2 to be skipped or handled incorrectly. Additionally, the loop increments `i` by 2 inside the if-block, but the outer for-loop also increments `i`, leading to skipping characters after expansion. Finally, `gets()` is unsafe and may cause buffer overflow, though not directly causing WA here.]