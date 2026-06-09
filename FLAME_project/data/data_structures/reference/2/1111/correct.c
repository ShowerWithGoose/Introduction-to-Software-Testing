#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[100];
int num[100];
char op[100];
int main()
{
int i,j=0,k=0,a=0;

gets(s);
for(i=0;i<=strlen(s);i++)
{
 if(s[i]!=' ')
 {
 s[j]=s[i];
  if(isdigit(s[j]))
  {a=a*10+s[j]-'0';}
  else{num[k]=a;op[k]=s[j];k++;a=0;}
  j++;
 }
}
j=0;
for(i=0;i<k;i++)
{
 if(op[i]=='*')
  num[i+1]=num[i]*num[i+1];
 else if(op[i]=='/')
  num[i+1]=num[i]/num[i+1];
 else{num[j]=num[i];op[j]=op[i];j++;}
}
for(i=0;op[i]!='=';i++)
{
if(op[i]=='+')
  num[i+1]=num[i]+num[i+1];
 else if(op[i]=='-')
  num[i+1]=num[i]-num[i+1];
}
printf("%d ",num[i]);
return 0;
}

