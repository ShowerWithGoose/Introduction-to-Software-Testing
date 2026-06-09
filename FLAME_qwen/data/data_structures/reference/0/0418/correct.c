#include <stdio.h>
#define MAXLINE 512
int main()
{
 char c,s1[MAXLINE],s2[MAXLINE];
 int i,j;
 i = j = 0;
 gets(s1);
 while(s1[i] != '\0')
 {
  s2[j++] = s1[i];
  if(s1[i+1] == '-' &&(s1[i] < s1[i+2])&&((s1[i]>='a'&&s1[i]<='z'&&s1[i+2]>='a'&&s1[i+2]<='z')||(s1[i]>='A'&&s1[i]<='Z'&&s1[i+2]>='A'&&s1[i+2]<='Z')||(s1[i]>='0'&&s1[i]<='9'&&s1[i+2]>='0'&&s1[i+2]<='9')))
  {
   for(c = s1[i]+1; c < s1[i+2]; c++)
    s2[j++] = c;
   i = i+2;
  }
  else i++;
 }
 s2[j] = '\0';
 puts(s2);
 return 0;
}

