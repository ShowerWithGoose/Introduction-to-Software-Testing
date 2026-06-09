#include<stdio.h>
#include<string.h>
int main()
{
	char str_begin[500]={0};
	char str_end[1000]={0};
	gets(str_begin);
	int n,i,j,k,num;
	n=strlen(str_begin);
	for(i=0,j=0;i<n;i++)
	{
		if(str_begin[i]!='-')
		{
			str_end[j++]=str_begin[i];
		}
		else if(i!=0)
		{
			if('0'<=str_begin[i-1]&&str_begin[i+1]<='9')
			{
				for(num=1;str_begin[i-1]+num<str_begin[i+1];num++)
				{
					str_end[j++]=str_begin[i-1]+num;
				}
			}
			else if('a'<=str_begin[i-1]&&str_begin[i+1]<='z')
			{
				for(num=1;str_begin[i-1]+num<str_begin[i+1];num++)
				{
					str_end[j++]=str_begin[i-1]+num;
				}
			}
			else if('A'<=str_begin[i-1]&&str_begin[i+1]<='Z')
			{
				for(num=1;str_begin[i-1]+num<str_begin[i+1];num++)
				{
					str_end[j++]=str_begin[i-1]+num;
				}
			}
			else str_end[j++]='-';
		}
	}
	puts(str_end);
	return 0;
}



