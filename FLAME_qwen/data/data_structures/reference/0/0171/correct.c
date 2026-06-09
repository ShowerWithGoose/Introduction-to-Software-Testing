#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	char str[10000]={'\0'};
	int dis,i,i1,i2;
	gets(str);
  for(i=1;i<strlen(str)-1;i++)
  {
  	if(str[i]-'-'==0)
  	{
  		if(str[i-1]-'a'>=0&&str[i-1]-'z'<=0&&str[i+1]-'a'>=0&&str[i+1]-'z'<=0)
  		{
  			for(i1=strlen(str)-1;i1>i;i1--)
				{
					dis=str[i+1]-str[i-1]-2;
					str[i1+dis]=str[i1];
				}
				for(i2=1;i2<=str[i+1+dis]-str[i-1]-1;i2++)
				{
					str[i2+i-1]=str[i-1]+i2;
				}
				i+=dis;
			}
			if(str[i-1]-'A'>=0&&str[i-1]-'Z'<=0&&str[i+1]-'A'>=0&&str[i+1]-'Z'<=0)
  		{
  			for(i1=strlen(str)-1;i1>i;i1--)
				{
					dis=str[i+1]-str[i-1]-2;
					str[i1+dis]=str[i1];
				}
				for(i2=1;i2<=str[i+1+dis]-str[i-1]-1;i2++)
				{
					str[i2+i-1]=str[i-1]+i2;
				}
				i+=dis;
			}
			if(str[i-1]-'0'>=0&&str[i-1]-'9'<=0&&str[i+1]-'0'>=0&&str[i+1]-'9'<=0)
  		{
  			for(i1=strlen(str)-1;i1>i;i1--)
				{
					dis=str[i+1]-str[i-1]-2;
					str[i1+dis]=str[i1];
				}
				for(i2=1;i2<=str[i+1+dis]-str[i-1]-1;i2++)
				{
					str[i2+i-1]=str[i-1]+i2;
				}
				i+=dis;
			}
		}
	}
		printf("%s",str);
}

