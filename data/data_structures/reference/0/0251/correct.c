#include <stdio.h>
#include <string.h>
#include<ctype.h>

void extend(char a1[],char a2[])
{
  int i,j=0,k;
  int len=strlen(a1);
  for(i=0;i<len;i++)
  {
  if (a1[i]!='-'||a1[i-1]>=a1[i+1])
  {
  a2[j++]=a1[i];
  }//'-'不存在或前大于后
  
   else if((a1[i-1]>='0'&&a1[i-1]<='9'&&a1[i+1]>='0'&&a1[i+1]<='9'&&a1[i+1]>a1[i-1]))
  {
  for(k=a1[i-1]+1;k<a1[i+1];k++)
  {
  a2[j++]=k;
  }
  }
  
  else if((a1[i-1]>='a'&&a1[i-1]<='z'&&a1[i+1]>='a'&&a1[i+1]<='z'&&a1[i+1]>a1[i-1]))
  {
  for(k=a1[i-1]+1;k<a1[i+1];k++)
  {
  a2[j++]=k;
  }
  }
  
  else if((a1[i-1]>='A'&&a1[i-1]<='Z'&&a1[i+1]>='A'&&a1[i+1]<='Z'&&a1[i+1]>a1[i-1]))
  {
  for(k=a1[i-1]+1;k<a1[i+1];k++)
  {
  a2[j++]=k;
  }
  }
 
  
  else if((a1[i]=='-')&&(!(a1[i-1]>='a'&&a1[i-1]<='z'&&a1[i+1]>='a'&&a1[i+1]<='z'&&a1[i+1]>a1[i-1])||(a1[i-1]>='A'&&a1[i-1]<='Z'&&a1[i+1]>='A'&&a1[i+1]<='Z'&&a1[i+1]>a1[i-1])||(a1[i-1]>='0'&&a1[i-1]<='9'&&a1[i+1]>='0'&&a1[i+1]<='9'&&a1[i+1]>a1[i-1])))
  {
  	  a2[j++]=a1[i];
  }

  }
  a2[j]='\0';
}

int main()
{
char a1[5000],a2[5000];
scanf("%s",a1);
extend(a1,a2);
printf("%s\n",a2);
}




