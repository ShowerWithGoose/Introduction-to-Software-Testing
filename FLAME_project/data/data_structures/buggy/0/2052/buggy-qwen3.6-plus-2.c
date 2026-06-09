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
    if(s[i+1]=='-'&&s[i]<s[i+2]&&((s[i]>='a'&&s[i]-1<'z'&&s[i+2]>'a'&&s[i+2]<='z')||(s[i]>='A'&&s[i]<'Z'&&s[i+2]>'A'&&s[i+2]<='Z') ||(s[i]>='0'&&s[i]<'9'&&s[i+2]>'0'&&s[i+2]<='9'))){ // @@ The boundary checks are incorrect. For example, s[i]-1<'z' allows 'z' to pass the first part of the check, but 'z' cannot be a start of an expansion where start < end within 'a'-'z' effectively if we consider standard ranges. More critically, the condition `s[i]<'Z'` excludes 'Y'->'Z' expansion? No, 'Y'<'Z' is true. But `s[i+2]>'A'` excludes 'A' as end point. E.g., A-C: 'A'<'C' and 'A'>='A', 'C'<='Z'. But `s[i+2]>'A'` means C>'A' which is true. What about A-B? B>'A' is true. What about expanding to 'a'? `s[i+2]>'a'` means end char must be > 'a'. So a-b fails because b>'a' is true, wait. b > 'a' is true. So a-b works. What about a-a? s[i]<s[i+2] fails. What about y-z? y<z is true. y>='a' true. y-1<'z' (x<'z') true. z>'a' true. z<='z' true. So y-z works. The logic seems mostly okay for valid ranges but overly complex and potentially buggy on boundaries like '0'-'9'. However, the main logical error causing the Wrong Answer on `a-c-g0-A` is likely elsewhere or this condition is just fragile. Let's look closer at the loop logic.
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