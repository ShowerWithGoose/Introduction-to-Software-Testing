#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	char a[1000]={0}; 
	int i=0,b,c,d=0,e;
	while(scanf("%c",&a[i])!=EOF)
	{
		i++;
	}
	a[i]='\0';
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]=='-'&&i>=1)//每当找到-便执行一次，再继续找 
		{
			if('a'<=a[i-1]&&a[i+1]<='z'&&a[i-1]<a[i+1])
			{
				if(a[i+1]-a[i-1]==1)
				{
					//将从第i+1个到最后一个分别向前移1位。 
					for(b=i+1;b<=strlen(a);b++)
					{
						a[b-1]=a[b];
					}
				}
				else
				{
					//扩充：将从最后一个到第i+1个分别后移a[i+1]-a[i-1]-2个，然后补齐 
					for(c=strlen(a);c>=i+1;c--)
					{
						d=a[i+1]-a[i-1]-2;
						a[c+d]=a[c];
					}
					for(e=i;e<=i+d;e++)
					{
						a[e]=a[e-1]+1;
					}
				}
			}
			else if('A'<=a[i-1]&&a[i+1]<='Z'&&a[i-1]<a[i+1])
			{
				if(a[i+1]-a[i-1]==1)
				{
					//将从第i+1个到最后一个分别向前移1位。 
					for(b=i+1;b<=strlen(a);b++)
					{
						a[b-1]=a[b];
					}
				}
				else
				{
					//扩充：将从最后一个到第i+1个分别后移a[i+1]-a[i-1]-2个，然后补齐 
					for(c=strlen(a);c>=i+1;c--)
					{
						d=a[i+1]-a[i-1]-2;
						a[c+d]=a[c];
					}
					for(e=i;e<=i+d;e++)
					{
						a[e]=a[e-1]+1;
					}
				}
			} 
			else if('0'<=a[i-1]&&a[i+1]<='9'&&a[i-1]<a[i+1])
			{
				if(a[i+1]-a[i-1]==1)
				{
					//将从第i+1个到最后一个分别向前移1位。 
					for(b=i+1;b<=strlen(a);b++)
					{
						a[b-1]=a[b];
					}
				}
				else
				{
					//扩充：将从最后一个到第i+1个分别后移a[i+1]-a[i-1]-2个，然后补齐 
					for(c=strlen(a);c>=i+1;c--)
					{
						d=a[i+1]-a[i-1]-2;
						a[c+d]=a[c];
					}
					for(e=i;e<=i+d;e++)
					{
						a[e]=a[e-1]+1;
					}
				}
			} 
			i=i+d+1;
		}
	} 
	printf("%s",a);
	
	
	
	return 0;
}

//#include<string.h>
//memset()
//strlen()
//strcmp()
//strcpy()
//strstr()

//<ctype.h>
//isalnum()
//isalpha()
//islower()
//isupper()
//tolower()
//toupper()
//输入字符串，检测有横杠的前后字符，如果符合则扩展，继续往后检测。 

