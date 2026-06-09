#include<stdio.h>
int main()
{
	char str[100000],str1[10000];
	gets(str);
	int i,j;
	for(i=0,j=0;i<100;i++,j++)
	{
		if(str[i]!='-')
		{
			str1[j]=str[i];
		}
		else if(str[i]=='-')
		{
			j--;
			if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0)
			{
				int n,t;
				n=str[i+1]-str[i-1];
				for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
				{
					j++;
					str1[j]=(char)t;
				}
			}
			else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0)
			{
				int n,t;
				n=str[i+1]-str[i-1];
				for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
				{
					j++;
					str1[j]=(char)t;
				}
			}
			else if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0)
			{
				int n,t;
				n=str[i+1]-str[i-1];
				for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
				{
					j++;
					str1[j]=(char)t;
				}
			}
			else
			{
				j++;
				str1[j]=str[i];
				
			}
		}
	}
	puts(str1);
	return 0;
 } 

