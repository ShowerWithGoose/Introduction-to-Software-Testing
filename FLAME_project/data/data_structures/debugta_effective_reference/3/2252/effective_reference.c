#include <stdio.h>
#include <string.h>
char s[105];
char p[105];
int main()
{
	int m=0,i=0,j=0,z=0,sign=1,xiao=0,qian=0,hou=0,flag=0,you=0,zheng=0;
	gets(s);
	for(i=0;i<=strlen(s)-1;i++)
	{
		if(s[i]=='.')xiao++;
		if(xiao==1)
		{
			if(flag==0)
			{
				if(s[i]=='0')qian++;
				else if(s[i]!='.'&&s[i]!='0') flag++;
			}
			you++;			
		}
		else zheng++;
	}
	if(zheng<=1&&s[0]=='0')m=-1;
	else m=1;
	for(i=0,j=0,z=0;i<=strlen(s)-1;i++)
	{
		if(m>0)
		{
			if(i==1)
			{
				p[j]='.';
				j++;
			}
			if(s[i]=='.')i++;
			if(s[i]!='.')p[j]=s[i];
			
			j++;
		}
		else if(m<0)
		{
			if(z==0&&s[i]!='0'&&s[i]!='.')
			{
				z=1;
				p[j]=s[i];
				p[++j]='.';
				j++;
				continue;
			}
			if(z==1)
			{
				p[j]=s[i];
				j++;
			}
		}
	}
	for(i=strlen(p)-1;p[i]=='0'||p[i]=='.';i--)p[i]='\0';
	printf("%s",p);
	if(m>0) printf("e%d",zheng-1);
	else printf("e%d",m*(qian+1));
	return 0;
	 
} 

