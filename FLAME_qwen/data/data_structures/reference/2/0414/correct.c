#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void removeSpace(char a[]);
int partPlus(char a[],int j,int i);
int main()
{
	char a[1000];
	int ans=0,temp;
	int i,j=0;
	gets(a);
	char condition,condition2;
	removeSpace(a);
	//去掉了最后的=，加上了一个+号
	//printf("remove space : %s \n",a);
	if(isdigit(a[0]))
	{
		i=0;
		condition='+';
	}
	else
	{
		if(a[0]=='+')
			condition='+';
		else if(a[0]=='-')
			condition='-';
		i=1;
		j=1;
	}

	for(;a[i]!='\0';i++)
	{
		if(a[i]=='+')
		{
			condition2='+';
			temp=partPlus(a,j,i);
			if(condition=='+')
				ans+=temp;
			if(condition=='-')
				ans-=temp;
			j=i+1;
			condition=condition2;
		}
		else if(a[i]=='-')
		{
			condition2='-';
			temp=partPlus(a,j,i);
			if(condition=='+')
				ans+=temp;
			if(condition=='-')
				ans-=temp;
			j=i+1;
			condition=condition2;
		}
	}

	printf("%d",ans);
	return 0;
}

void removeSpace(char a[])
{
	int i,j;
	j=0;
	for(i=0;a[i]!='=';i++)
	{
		if(a[i]!=' ')
		{
			a[j]=a[i];
			j++;
		}	
	}
	a[j]='+';
	a[j+1]='\0';
	return ;	
}

int partPlus(char a[],int j,int i)		//找到加减号中间乘除的部分进行处理
											 
{
	//printf("from %d to %d ---->  ",j,i);
	int ans=1,num;
	char temp[100];
	char temp2[100];
	memset(temp,0,sizeof(char)*100);
	strncpy(temp,a+j,i-j);
	strcat(temp,"*");
	//printf("part: %s   ",temp);
	char condition,condition2;		
	int m=0,n=0;
	condition='*';
	
	for(;temp[m]!='\0';m++)
	{
		if(temp[m]=='*'||temp[m]=='/')
		{
			sscanf(temp+n,"%d%c%s",&num,&condition2,temp2);
			//printf("num:%d   ",num);
			if(condition=='*')
				ans*=num;
			if(condition=='/')
				ans/=num;
			condition=condition2;
			n=m+1;
		}

	}
	//printf("plus: %d\n",ans);
	return ans;
	
}

