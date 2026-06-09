#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	char xiaoshu[101];
	int cnt_zheng=0,cnt_dot,cnt_leng=0,i,e,flag=0; 
	gets(xiaoshu);
	cnt_dot=strlen(xiaoshu);
	cnt_zheng=strlen(xiaoshu)-1;
	for(i=0;i<strlen(xiaoshu);i++)
	{
		if(xiaoshu[i]=='0')
		{
			if(flag==1)
			{
				cnt_leng++;
			}
			continue;
		}
	 	else
	 	{
	 		if(xiaoshu[i]=='.')
	 		{
	 			cnt_dot=i;
			}
			else
			{
				cnt_leng++;
				if(flag!=0)
				{
					continue;
				}
				else
				{
					flag=1;
					cnt_zheng=i;
				}
				
			}
		}
	}
	printf("%c",xiaoshu[cnt_zheng]);
	if(cnt_dot!=cnt_leng)
	{
		printf(".");
	}
	for(i=cnt_zheng+1;xiaoshu[i]!='\0';i++)
	{
		if(xiaoshu[i]=='.')
		{
			continue;
		}
		printf("%c",xiaoshu[i]);
	}
	e=cnt_dot-cnt_zheng;
	if(e>0)
		e--;
	printf("e%d",e);
	return 0;
}


