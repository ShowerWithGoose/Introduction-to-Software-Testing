#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	char a[20001],b[20001];
	char c[21][2001];
	int d[20001]; 
	int i=0,j=0,k=0,l=0,m=0;
	int res,x,y;
	int num=0; 
	x=0;
	y=0;
	res=0;
	gets(a);//a数组读入字符串 用i计数 
	while(a[i]!='=')
	{
		if(a[i]==' ')
		{
			i++;
		}
		else
		{
			b[j]=a[i];
			i++;
			j++;
		}
		b[j]='\0';
	}//b数组消去空格 用j计数 
	j=0;
	while(b[j]!='\0')
	{
		if(b[j]=='+'||b[j]=='-')
		{
			c[k][0]=b[j];
			j++;
		 } 
		 else
		 {
		 	while(b[j]!='+'&&b[j]!='-'&&b[j]!='\0')
		 	{
		 		c[k][l]=b[j];
		 		l++;
		 		j++;
			 }
		 }
		 k++;
		 l=0;
	}
	//c二维数组记录数字与符号+-为分界用k,l计数
	k=0;
	while(c[k][0]!='\0')
	{
		l=0;
		char bd;//标点符号 记录*/ 
		while(c[k][0]=='+'||c[k][0]=='-'||c[k][0]=='\0')
		{
			 k++;
		}
		int t1=l+1;
		while(c[k][t1]!='*'&&c[k][t1]!='/'&&c[k][t1]!='\0')t1++;
		bd=c[k][t1];
		while(l<t1)
		{
			x=x+(c[k][l]-'0')*(pow(10,t1-l-1));
			l++;
		}
		t1=l+1;	
		while(c[k][l+1]!='\0')
		{
			while(c[k][t1]!='*'&&c[k][t1]!='/'&&c[k][t1]!='\0')t1++;
			while(l+1<t1)
		{
			y=y+(c[k][l+1]-'0')*(pow(10,t1-l-2));
			l++;
		} 
		if(bd=='*')x=x*y;
	    else if(bd=='/')x=x/y;
	    else x=x;
		if(c[k][t1]=='\0')bd=bd;
		else bd=c[k][t1];
	    t1++;
	    l++;
	    y=0;
		}
		if(c[k-1][0]=='-')d[m]=-x;
		else d[m]=x;
		k++;
		m++;
		x=0,y=0;
	}//d数组记录只含加减的数字 用m计数 
	m=0;
	while(k)
	{
		res=res+d[m];
		m++;
		k--;
	}
	printf("%d",res);
	return 0;
}

