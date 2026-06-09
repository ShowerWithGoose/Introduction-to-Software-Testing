/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char s[2005],a[2005];
int ans,flag=1,flag1=1;
int main()
{
	gets(s);
	int len=strlen(s),len1=0;
	int i,j; 
	for(i=0;i<len;++i)
	if(s[i]!=' ')a[len1++]=s[i];
	len1--;
	for(i=0;i<len1;++i)
	{
		int g=0;
		while(isdigit(a[i]))
		{
			g=g*10+a[i]-'0';
			i++;
		}
	//	printf("%d\n",g);
		for(j=i;j<len1;++j)
		{
			if(a[j]=='/')
			{
				++j;
				int k=0;
				while(isdigit(a[j]))
				{
					k=k*10+a[j]-'0';
					j++;
				}
				g=g/k;
				//printf("%d\n",g);
			}
			if(a[j]=='*')
			{
				++j;
				int k=0;
				while(isdigit(a[j]))
				{
					k=k*10+a[j]-'0';
					j++;
				}
				g=g*k;
			//	printf("%d\n",g);
			}
			if(a[j]=='+')
			{
				i=j;
				flag=1;
				break;
			}
			if(a[j]=='-')
			{
				i=j;
				flag=-1;
				break;
			} 
			j--;
			i=j;
			//printf("%d\n",g);
		}
		ans+=g*flag1;
		flag1=flag;
	//	printf("%d\n",i);
	}
	printf("%d",ans);
	return 0;
}


