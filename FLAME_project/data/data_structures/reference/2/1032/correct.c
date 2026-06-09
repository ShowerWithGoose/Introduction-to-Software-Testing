#include<stdio.h>
#include<string.h>
int number(char d[],int n);
int senior(char n[]);
int main()
{
	char a[100];
	
	char b[100],n[100];
	
	int res[100];
	gets(a);
	int i,k,flag,num;
	int ans;
	for(i=0,k=0;a[i]!='\0';i++)
	{
		if(a[i]!=' ')
		a[k++]=a[i];
	}
	a[k]='\0';//删空格 
	
	for(i=0,k=0,flag=0,num=0;a[i]!='=';i++)
	{
		if(a[i]!='+'&&a[i]!='-')
		n[flag++]=a[i];
		else
		{
			b[k++]=a[i];
			n[flag]='\0';
			res[num++]=senior(n);
			flag=0;
		}
	}
	
			b[k++]=a[i];
			n[flag]='\0';
			res[num++]=senior(n);
			flag=0;//计算所有二级运算式的结果 
	   
	   ans = res[0];
		
		for(i=0,num=1;i<k-1;i++)
		{
		
			if(b[i]=='+')
		   {
			ans+=res[num];
			num++;
	      	}
			else
		    {
			ans-=res[num];
			num++;
		   }
	    }
	
	printf("%d",ans);
	
	return 0;
	
	
}


int senior(char n[])
{
	int c[100];
	char d[100],e[100];//d存数字，e存字符 
	int i,k,flag1,num=0,ans=1;
	for(i=0,k=0,flag1=0;n[i]!='\0';i++)
	{
		if(n[i]!='*'&&n[i]!='/')
		d[flag1++]=n[i];
		else
		{
			e[k++]=n[i];
			d[flag1]='\0';
			c[num++]=number(d,flag1);
			flag1=0;
		}
	}
	
			e[k++]=n[i];
			d[flag1]='\0';
			c[num++]=number(d,flag1);
			flag1=0;
			
	
	ans=c[0];
	for(i=0,num=1;i<k-1;i++)
	{
		
		if(e[i]=='*')
		{
			ans*=c[num];
			num++;
		}
		else
		{
			ans/=c[num];
			num++;
		}
	}
	return ans;
}

int number(char d[],int n)
{
	int shu=0;
	int i;
	for(i=0;i<n;i++)
	{
		shu+=(d[i]-'0');
		shu*=10;
	}
	shu/=10;

	return shu;
}



