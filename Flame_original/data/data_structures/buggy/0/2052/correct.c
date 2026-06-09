#include <stdio.h>

void squeez(char s[],char c);

int main()
{
  int i=0,j=0;
  char s[512],s2[512];//两个字符串数组，一个放原来的，一个放补充的 
  gets(s);
  for(i=0;s[i]!='\0';i++){
    if(s[i]=='-'&&s[i-1]<s[i+1]&&((s[i-1]>='a'&&s[i-1]-1<'z'&&s[i+1]>'a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i-1]<'Z'&&s[i+1]>'A'&&s[i+1]<='Z') ||(s[i-1]>='0'&&s[i-1]<'9'&&s[i+1]>'0'&&s[i+1]<='9'))){
    //延长字符串
    char temp;
    temp=s[i-1];//把‘-’前的字符串赋给过渡值 
    while(temp<s[i+1]-1){
      temp++;
      s2[j]=temp;
      j++;
      }
      i=i+1;
    }
    s2[j]=s[i];
    j++; 
    
  } 
  s2[j]='\0';
  puts(s2);
  
	return 0;
}







