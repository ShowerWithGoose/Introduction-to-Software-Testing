#include <stdio.h>
#include <string.h>

void expand(char s1[],char s2[])
{
  int j=0;
  int len=strlen(s1);
  for(int i=0;i<len;i++)
  {
  if (s1[i]!='-'||s1[i-1]>=s1[i+1])
  {
  s2[j++]=s1[i];
  }
  else if((s1[i-1]>='a'&&s1[i-1]<='z'&&s1[i+1]>='a'&&s1[i+1]<='z'&&s1[i+1]>s1[i-1])||(s1[i-1]>='A'&&s1[i-1]<='Z'&&s1[i+1]>='A'&&s1[i+1]<='Z'&&s1[i+1]>s1[i-1])||(s1[i-1]>='0'&&s1[i-1]<='9'&&s1[i+1]>='0'&&s1[i+1]<='9'&&s1[i+1]>s1[i-1]))
  {
  for(int k=s1[i-1]+1;k<s1[i+1];k++)
  {
  s2[j++]=k;
  }
  }
  else if((s1[i]=='-')&&(!(s1[i-1]>='a'&&s1[i-1]<='z'&&s1[i+1]>='a'&&s1[i+1]<='z'&&s1[i+1]>s1[i-1])||(s1[i-1]>='A'&&s1[i-1]<='Z'&&s1[i+1]>='A'&&s1[i+1]<='Z'&&s1[i+1]>s1[i-1])||(s1[i-1]>='0'&&s1[i-1]<='9'&&s1[i+1]>='0'&&s1[i+1]<='9'&&s1[i+1]>s1[i-1])))
  s2[j++]=s1[i];
  }
  s2[j]='\0';
}

int main()
{
char s1[5000],s2[5000];
scanf("%s",s1);
expand(s1,s2);
printf("%s\n",s2);
}



