#include<stdio.h>
#include<string.h>
int key(char a[])
{
	int ans=0,i,cnt=1;
	for(i=strlen(a)-1;i>=0;i--)
	{

		ans+=(a[i]-'0')*cnt;
		cnt*=10;


	}
	return ans;
}

int main()
{
	char ch[192608],mid[192608],record[100][100],point[1926],end[1926];
	gets(ch);
	int i=0,j=0,m=0,n=0,k=0,a[192608]={0},star[192608]={0},goal=0;
	for(i=0;i<strlen(ch);i++)
	{
		while(ch[i]==' ')
		i++;
		mid[m++]=ch[i];
	}
	//printf("%s",mid);
	m=0;
	for(i=0;i<strlen(mid);i++)
	{

		if((mid[i]<'0'&&'0'-mid[i]!=16)||mid[i]-'0'==13)
		{
			point[m]=mid[i];
			i++;
			m++;
			n=0;
		}
		record[m][n++]=mid[i];

	}
	for(i=0;i<m;i++)
	{
		a[i]=key(record[i]);
		//printf("%s %c %d\n",record[i],point[i],a[i]);//提取出每个整数，整数放在a[]里面，与紧跟整数之后的运算符放在point里面，并检验，经检验后正确
	}//此行之前正确
    for(i=0,j=0;i<m;i++,j++)//此循环目的是求出相邻的连乘与连除的积或商
	{
		if(point[i]=='*')
		{

			star[j]=a[i]*a[i+1];
			i++;
			while(point[i]=='*'||point[i]=='/')
			{
				if(point[i]=='*')
				{
					i++;
					star[j]*=a[i];
				}
				if(point[i]=='/')
				{
					i++;
					star[j]/=a[i];
				}
			}
		}
		else if(point[i]=='/')
		{
			star[j]=a[i]/a[i+1]	;
			i++;
			while(point[i]=='/'||point[i]=='*')
			{
				if(point[i]=='*')
				{
					i++;
					star[j]*=a[i];
				}
				if(point[i]=='/')
				{
					i++;
					star[j]/=a[i];
				}
			}
		}
		else
			star[j]=a[i];

	}
	for(i=0,k=0;i<m;i++,k++)
	{

		while(point[i]=='*'||point[i]=='/')
		{
			i++;
		}
		if(point[i]=='+'||point[i]=='-')
			end[k]=point[i];
		//printf("%c",end[k]);
	}
	goal+=star[0];
	for(i=1;i<j;i++)
	{
		if(end[i-1]=='+')
		{
			goal+=star[i];
		}
		else
			goal-=star[i];
	}
	printf("%d",goal);

	return 0;

}

