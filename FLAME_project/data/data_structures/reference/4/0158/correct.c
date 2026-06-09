#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i=0,j=0,k=0,n,flag,num[105];
int main()
{FILE *fp;char str[105][20],temp[20];char t;int len;
fp=fopen("article.txt","r");
t=fgetc(fp);
while(t!=EOF)
{if(isalpha(t))
 {
 str[i][j]=t;
 j++;
 }
 else if(isspace(t)||ispunct(t))
 {str[i][j]='\0';
 j=0;
 i++;
 }
 t=fgetc(fp);
}
n=i;
for(i=0;i<n;i++)
num[i]=1;
for(i=0;i<n;i++)
{len=strlen(str[i]);
for(j=0;j<len;j++)
str[i][j]=tolower(str[i][j]);
}
for(i=0;i<n;i++)
{for(j=i+1;j<n;j++)
 {
 if(strcmp(str[i],str[j])>0)
 {strcpy(temp,str[j]);
  strcpy(str[j],str[i]);
  strcpy(str[i],temp);
 }
 }
}
for(i=0;i<n;i++)
{flag=0;
 for(j=i+1;j<n;j++)
{
  if(strcmp(str[i],str[j])==0)
  {
  num[i]++;
  str[j][0]='\0';
  flag=1;}
  if(str[j][0]=='\0')
  continue;
  else
  {if(flag==1)
   i=j-1;
  }
  break;
 }
}
for(i=0;i<n;i++)
if(str[i][0]!='\0') printf("%s %d\n",str[i],num[i]);
return 0;
}

