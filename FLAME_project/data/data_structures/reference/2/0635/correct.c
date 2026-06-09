#include <stdio.h>
#include <string.h>
#include <ctype.h>
void Delete(char s[]);
void Change(int s[]);
int Num(int c);
int Calculate(int s[]);
void Exchange(char s[]);
char s0[105];
int s3[105],s1[105],s2[105];
int main()
{
	gets(s0);
	Delete(s0);
	Exchange(s0);
	Change(s3);
	printf("%d",Calculate(s1));
	return 0;
}
void Delete(char s[])
{
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
	{
		if(s[i]!=' ')
		s[j++]=s[i];
	}
	s[j]='\0';
} 
void Exchange(char s[])
{
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
	{
		if(isdigit(s[i]))
		{
			int a=s[i]-'0';
			while(isdigit(s[++i]))
			a=a*10+s[i]-'0';
			s3[j++]=a;
			i--;
		}
		else 
		{switch(s[i])
		{case ('+'):s3[j++]=-1;break;
		case ('-'):s3[j++]=-2;break;
		case ('*'):s3[j++]=-3;break;
		case ('/'):s3[j++]=-4;break;
		default :s3[j++]=-5;
		}
		}
	}
}
void Change(int s[])
{
	int i,j,k=0;
	for(i=j=0;s[i]!=-5;i++)
	{
		if(s[i]>=0)
		s1[j++]=s[i];
		else 
		{
			if(k==0)
			s2[k++]=s[i];
		    else
			{
			    for(;Num(s2[k-1])>=Num(s[i])&&k!=0;k--)
				s1[j++]=s2[k-1];
				s2[k++]=s[i];
			}
		}
	}
	for(;k>0;k--)
	s1[j++]=s2[k-1];
	s1[j]=-5;
}
int Num(int c)
{if(c==-1||c==-2)
return 0;
else return 1;
}
int Calculate(int s[])
{
	int i,j,k;
	int a[105]={0};
	for(i=j=0;s[i]!=-5;i++)
	{if(s[i]>=0)
	a[j++]=s[i];
	else
	{if(s[i]==-1) a[j-2]=a[j-2]+a[j-1];
	else if(s[i]==-2) a[j-2]=a[j-2]-a[j-1];
	else if(s[i]==-3) a[j-2]=a[j-2]*a[j-1];
	else a[j-2]=a[j-2]/a[j-1];
	j--;
	}
	}
	return a[0];
}



