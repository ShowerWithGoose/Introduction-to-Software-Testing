#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
char s[1000];
int cc[1000];//乘除符号的位置 
int jj[1000];//加减符号的位置 
int num1,num2;//num2一直更新用于记录乘除符号后的数 

int tys(int a,char c,int b)//二元计算器 
{
	if (c=='+')
	return a+b;
	else if(c=='-')
	return a-b;
	else if(c=='*')
	return a*b;
	else if(c=='/')
	return a/b;
}

int ztos(char s[],int k) //字符串转数值函数 （在字符串s[]中从第k位开始） 
{
	int op=0,i=k;
	for(i;;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		op=op*10+s[i]-'0';
		else if(s[i]!=' ')
		break;
	}
	return (op);
}

int main()
{
	gets(s);
	int number=0;
	int i,x=0,y=0;//读入 
	//printf("%s\n",s);
	
	int n=strlen(s)-1;
	for(i=n+1;i>0;i--)
	s[i]=s[i-1];
	s[i]='+';
	n++;//前置加号 
	//printf("%s\n",s);
	
	for(i=0;i<=n;i++)
	{
		if(s[i]=='*'||s[i]=='/')
		cc[x]=i,x+=1; 
		//printf("%d\n",cc[x-1]);
		else if(s[i]=='+'||s[i]=='-')
		jj[y]=i,y+=1;
		//printf("%d\n",jj[y-1]);
	}
	jj[y]=n;x-=1;//cc,jj数组记录乘除、加减号位置  
	
	int k2=0,k1=0;
	for(k2=0;k2<=y-1;k2++)
	{
		//先把第一个数转成数值 
		num1=ztos(s,jj[k2]+1);
		//printf("%d\n",num1);
		if(cc[k1]<jj[k2+1]&&cc[k1]>jj[k2])
		{
			for(k1;cc[k1]<jj[k2+1]&&cc[k1]>jj[k2];k1++)//中间部分先读入符号再读入数值计算 
	    	{
			   num2=ztos(s,cc[k1]+1);
			   num1=tys(num1,s[cc[k1]],num2);
			   num2=0;
		    }
		    number=tys(number,s[jj[k2]],num1);//最后相加减 
		    num1=0,num2=0;
		}
		else
		number=tys(number,s[jj[k2]],num1);//加减号之间只有一个数 
		
	}
	//先计算加减号区间内的乘除运算，再相加减 
	 
	printf("%d",number);
    return 0;
}


