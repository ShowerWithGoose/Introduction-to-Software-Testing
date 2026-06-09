#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
	//1564891+25*
   		   //t
int f(char *b,int y)//算位数函数 
{
	int i=0;
	char *p=b;
	while(isdigit(*(p+y+i+1)))
	{
		i++;
	}
	return i;
}
int main()
{
	char a[1000]={0},b[1000]={0},c[30]={0},d[30]={0};
	int i,k,j,n,r,rNew,u,v;
	int t=-1,m=1,leftnum=0,rightnum=0,leftdigit=0,rightdigit=0,digit=0,num=0;
	//t加减号位置 m表示倍速 leftnum左侧数字 rightnum右侧数字 leftdigit左侧数字位数 rightdigit右侧数字位数 digit被加减数字的位数 num要被加减的数字 
	long long SUM=0,sum=0;
	//SUM总和 sum每次运算之和 
	char temp[30]={0};
	
	gets(a);//读入算式 
	
	for(i=0,k=0;i<strlen(a);i++)
	{
		if(a[i]!=' ')
		{
			b[k]=a[i];
			k++;
		}
	}//去空格 仍以char存储 
	
	for(j=0;j<strlen(b);j++)
	{
		if(b[j]=='+'||b[j]=='-')
		{
			t=j;
		}
		else if(b[j]=='*'||b[j]=='/')
		{
			leftdigit=f(b,t);
			for(n=1,m=1;n<=leftdigit;n++)
			{
				leftnum+=(b[j-n]-'0')*m;
				m*=10; 
			}//算左侧数字
			
			rightdigit=f(b,j);
			rNew=j+rightdigit;
			for(r=j+rightdigit,m=1;r>j;r--)
			{	
				rightnum+=(b[r]-'0')*m;
				m*=10;
			}//算右侧数字 
			
			if(b[j]=='*')
			{
				sum=leftnum*rightnum;
			}
			else if(b[j]=='/')
			{
				sum=leftnum/rightnum;
			}
			
			//SUM=+sum;
			
			for(i=0;sum>0;i++)
			{
				c[i]=sum%10+'0';
				sum/=10;
			}//将sum转换为字符串 结束时i为sum的位数 
			//c颠倒
			for(u=strlen(c)-1,v=0;u>=0;u--,v++)
			{
				d[v]=c[u];
			}
			d[v]='\0';
			
			strcpy(b+t+1,d);//sum字符串覆盖到b 
			
			strcpy(temp,b+rNew+1);
			
			strcpy(b+t+1+i,temp);//b变成运算后的形式 
			
			memset(temp,0,strlen(temp));
			memset(c,0,strlen(c));
			memset(d,0,strlen(d));
			
			j=t+i;
			leftnum=0;
			rightnum=0;
		}
		else if(b[j]=='=')
		{
			break;
		}
	}//第一遍 储存加减位置 进行乘除运算 
	
	//12+54861*4861/132-
	//  t     j   r
	//12+266679321/132-
	//  t         j  r
	//12+266679321/132-
	//  t        j   r  
//--------------------------- 
	//12+54861/4861/132-
	//  t     j   r
	//12+11/132-
	//  t     j   r
	//12+11/132-
	//  t j       r 
	//将sum转换为字符串 覆盖到b 再将从下一个符号开始的字符接到sum字符串后面 
	
	//算式只剩加减 计算加减
	//15+13513-4862354+
   //t  i    
    //15+13513-4862354+
    //  t     i	
    
	t=-1; 
	for(i=0;i<strlen(b);i++)
	{
		if(!(isdigit(b[i])))
		{
			digit=f(b,t);
			for(n=1,m=1;n<=digit;n++)
			{
				num+=(b[i-n]-'0')*m;
				m*=10;
			}
			if(t<0||t>0&&b[t]=='+')
			{
				SUM+=num;
			}
			else if(t>0&&b[t]=='-')
			{
				SUM-=num; 
			}
			t=i;
			num=0;
		}
	} 
	//i用来计算t和i之间的数字 t用来计算位数 
	
	printf("%lld",SUM);
	return 0;
}

//#include<string.h>
//memset()
//strlen()
//strcmp()
//strcpy()
//strstr()

//<ctype.h>
//isalnum()
//isalpha()
//islower()
//isupper()
//tolower()
//toupper()


