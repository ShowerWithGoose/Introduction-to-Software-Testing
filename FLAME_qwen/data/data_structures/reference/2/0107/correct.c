#include<stdio.h>
char ch[1005]="\0";
int num[1005]={0};//记录数字 
int used[1005]={0};//记录用过的数字 
int a[1005]={0};//1--> +    2--> -   3-->  *   4-->  /
int res=0;//记录结果 
int change(int x,int y)//将字符变为数字并返回 
{
	int n=0;
	while(x<=y)
	{
		n=n*10+ch[x]-'0';
		x++;
	}
	return n;
}
void del(int i)
{
	int j=i,k=i;
	while(a[k]!=0)
	a[j++]=a[++k];
	j=++i;
	while(j<=k+2)
	num[j++]=num[++i];
 } 
int main()
{
	int i=0,j=0;
	while((ch[i++]=getchar())!='=');
	ch[i]='\0';
	i=0;
	while(ch[i]!='\0')
	{
		if(ch[i]!=' ')
		ch[j++]=ch[i];
		i++; 
	}
	ch[j]='\0'; //去空格
	//先实现运算符号判别 
	int n[1005]={0};//判断运算符位置 
	i=0,j=0;//重复利用i和j 
	int k=0;
	while(ch[i++]!='\0')
	{
		if(ch[i]=='+')
			a[k++]=1;
		if(ch[i]=='-')
			a[k++]=2;
		if(ch[i]=='*')
			a[k++]=3;
		if(ch[i]=='/')
			a[k++]=4;
		if(ch[i]=='+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='/'||ch[i]=='=')
			n[j++]=i;
	}
	i=0,j=1;
	num[0]=change(0,n[0]-1);
	while(n[j]!=0)//数字转换，存到num 
	{
		num[j]=change(n[j-1]+1,n[j]-1);
		j++;
	}//num数字，a符号 
	i=0;
	while(a[i]!=0)
	{
		if(a[i]==3) 
		{
		num[i]*=num[i+1];
		del(i);
		i--;
		}
		if(a[i]==4)
		{
		num[i]/=num[i+1];
		del(i); 
		i--;
		} 
		i++;
	}
	i=0;
	while(a[i]!=0)
	{
		if(a[i]==1) 
		{
		num[i]+=num[i+1];
		del(i);
		i--; 
		}
		if(a[i]==2) 
		{ 
		num[i]-=num[i+1];
		del(i); 
		i--;
		} 
		i++;
	}
	printf("%d",num[0]);
	return 0;
}

