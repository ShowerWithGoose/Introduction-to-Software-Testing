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
      i=i+2; // @@ [After expansion, the code skips the right character (e.g., 'c' in "a-c") and the hyphen, so the next left character is never processed. This prevents detection of subsequent hyphens like 'c-g'. To correctly handle consecutive expansions, the index should not skip the right character; instead, set i to the position of the hyphen (i+1) so that the loop increment lands on the right character, or restructure the loop.]
    }
    j++; 
    
  } 
  s2[j]='\0';
  puts(s2);
  
    return 0;
}