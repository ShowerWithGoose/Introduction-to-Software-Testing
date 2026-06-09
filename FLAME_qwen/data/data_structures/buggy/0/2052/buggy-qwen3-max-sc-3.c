#include <stdio.h>

void squeez(char s[],char c);

int main()
{
  int i=0,j=0;
  char s[512],s2[512];//两个字符串数组，一个放原来的，一个放补充的 
  gets(s); // @@ [Using 'gets' is unsafe and deprecated; however, the primary error is logical in expansion condition]
  for(i=0;s[i]!='\0';i++){
    //把s[]传给s2[] 
    s2[j]=s[i];
    if(s[i+1]=='-'&&s[i]<s[i+2]&&((s[i]>='a'&&s[i]-1<'z'&&s[i+2]>'a'&&s[i+2]<='z')||(s[i]>='A'&&s[i]<'Z'&&s[i+2]>'A'&&s[i+2]<='Z') ||(s[i]>='0'&&s[i]<'9'&&s[i+2]>'0'&&s[i+2]<='9'))){ // @@ [Incorrect boundary checks: e.g., 's[i]-1<'z'' should be 's[i]<'z'', and 's[i+2]>'a'' should be 's[i+2]>='a''. Also, accessing s[i+2] without ensuring i+2 is within bounds leads to undefined behavior.]
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