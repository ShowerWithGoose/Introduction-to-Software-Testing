#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[500];
int t[100],a[100];
void squeez(char s[]);
int main()
{
  int i,j,k,num,ans,mid;
  int i0=0,m=0,flag=1;
  gets(s);
  squeez(s);//去空格
  for(i=0,j=0; s[i]!='\0'; i++)
    {
      num=s[i]-'0';
      for(i=i+1; isdigit(s[i])!=0; i++)
        {
          num=num*10+s[i]-'0';
        }
      t[j++]=num;
    }//将所有数字保存到数组中
  i=k=0;
A:
  for(; s[i]!='+'&&s[i]!='-'&&s[i]!='='; i++)
    {
      if(flag==1)
        {
          mid=t[k];
          k++;
        }
      if(s[i]=='*')
        {
          mid*=t[k];
          k++;
        }
      if(s[i]=='/')
        {
          mid/=t[k];
          k++;
        }
      flag++;
    }
  a[m]=mid;
  m++;
  flag=1;
  if(s[i]!='=')
    {
      i++;
      goto A;
    }//进行乘除运算
    ans=a[0];
  for(i=0,j=1;s[i]!='=';i++)
  {
  	if(s[i]=='+')
  	{
  	 ans+=a[j];
	   j++;	
	}
	if(s[i]=='-')
	{
		ans-=a[j];
		j++;
	}
  }//进行加减运算 
    printf("%d",ans);
  return 0;
}

void squeez(char s[])
{
  int i,j;
  for(i=j=0; s[i]!='\0'; i++)
    {
      if(s[i]!=' ')
        s[j++]=s[i];
    }
  s[j]='\0';
}



