#include <stdio.h>

void squeez(char s[],char c);

int main()
{
  int i=0,j=0;
  char s[512],s2[512];
  gets(s);
  for(i=0;s[i]!='\0';i++){
    s2[j]=s[i];
    if(s[i+1]=='-'&&s[i]<s[i+2]&&((s[i]>='a'&&s[i]-1<'z'&&s[i+2]>'a'&&s[i+2]<='z')||(s[i]>='A'&&s[i]<'Z'&&s[i+2]>'A'&&s[i+2]<='Z') ||(s[i]>='0'&&s[i]<'9'&&s[i+2]>'0'&&s[i+2]<='9'))){ // @@ [The condition only checks for dash at s[i+1]. After an expansion, the next dash may be at the current i (since i is set to i+2 then incremented), causing subsequent dashes to be missed. Also the range checks for digits exclude '0' and '9', which is incorrect.]
    //延长字符串
    char temp;
    temp=s[i];
    while(temp<s[i+2]){
      temp++;
      j++;
      s2[j]=temp;
      }
      i=i+2; // @@ [This line, combined with the for loop increment, skips the next dash (which becomes the current i after increment) so it is not processed. Should adjust index handling to avoid missing dashes.]
    }
    j++; 
    
  } 
  s2[j]='\0';
  puts(s2);
  
    return 0;
}