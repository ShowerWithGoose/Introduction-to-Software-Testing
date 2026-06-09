#include<stdio.h>
#include<string.h>
#include<ctype.h>
int f(int x)

{
	int i,a=1;
	for(i=0;i<x;i++)
	{
		a*=10;
	}
	
	return a;
}//输入的x返回值就为10的x次方 
int min(int a,int b)
{
	if(a>=b)
	return b;
	else
	return a;
}
int main()
{
	int count=1,len,num1=0,num2=0,end[1000]={0},num=0;//count记录是不是首位 
	int jiajiandeng[1000],chengchu[1000];
	int x=0,y=0,m,n,p;
	int biao=0;//biao用来算num2 
	int r=0;
	int i,j=0,temp=0,hold=0;//temp暂时储存加减等 
	int shu=0,difference=0; //difference=0表示加减空档中并没有出现乘除号
	int jiajianhe=0;
	int flag1,flag2; 
	char b[1000];
	char a[1000];
	gets(b);
	len=strlen(b);
	
	for(i=0;i<len;i++)
	{
		if(b[i]!=' ')
		{
		a[j++]=b[i];
		}	
	}

	len=strlen(a);//去空格 
	
	for(i=0;i<len;i++)
	{
		if(a[i]=='+'||a[i]=='-'||a[i]=='=')
		{
			jiajiandeng[x]=i;
			x++;
			jiajianhe++;
		}
		if(a[i]=='*'||a[i]=='/')
		chengchu[r++]=i;
	}//记录个运算符的位置
	y=0;					
	for(m=0;m<jiajianhe;m++)
	{
		if(shu==0)
		{
				for(n=0;n<jiajiandeng[0];n++)
			{
				if(a[n]=='*'||a[n]=='/')
				{
					difference=1;
					biao++;
					if(count==1)
					{
						x=0;
						while(isdigit(a[n-1-x])!=0&&n-1-x>=0)
						{
						
						num1=num1+(a[n-1-x]-'0')*f(x);
						x++;
						}
						if(biao<r)
						x=min(chengchu[biao]-1,jiajiandeng[0]-1);
						else
						x=jiajiandeng[0]-1;
						while(isdigit(a[x])!=0)
						{
						
						num2=num2+(a[x]-'0')*f(y);
						x--;
						y++;
						}
						y=0;
						count++;
						if(a[n]=='*')
						end[shu]=num1*num2;
						else
						end[shu]=num1/num2;
						continue;	
					}
					 if(count>1) 
					{
						
						num2=0;
						if(biao<r)
						x=min(chengchu[biao]-1,jiajiandeng[0]-1);
						else
						x=jiajiandeng[0]-1;
						y=0;
						while(isdigit(a[x])!=0)
						{
						
						num2=num2+(a[x]-'0')*f(y);
						x--;
						y++;	
						}
						
						y=0;
						num1=end[shu];
						if(a[n]=='*')
						end[shu]=num1*num2;
						else
						end[shu]=num1/num2;
					}
				}	
				
			}
			if(difference==0)
			{
				for(n=0;n<jiajiandeng[0];n++)
				{
					temp=jiajiandeng[0]-n-1;
					end[shu]+=(a[n]-'0')*f(temp);
				}
			}//中间全部是数字没有乘除号时将其转化为十进制的数字 
			shu++;
			continue;
		}
		difference=0;
		if(shu!=0)
		{
			count=1;
				for(n=jiajiandeng[m-1]+1;n<jiajiandeng[m];n++)
			{
				if(a[n]=='*'||a[n]=='/')
				{
					biao++;
					difference=1;
					
					if(count==1)
					{
						x=0;
						num1=0;
						while(isdigit(a[n-1-x])!=0)
						{
						num1+=(a[n-1-x]-'0')*f(x);	
						x++;
						
						}
					
						num2=0;
						if(biao<r)
						x=min(chengchu[biao]-1,jiajiandeng[m]-1);
						else
						x=jiajiandeng[m]-1;
						y=0;
						while(isdigit(a[x])!=0)
						{
						
						num2=num2+(a[x]-'0')*f(y);
						x--;
						y++;
						}
						y=0;
					
						count++;
						if(a[n]=='*')
						end[shu]=num1*num2;
						else
						end[shu]=num1/num2;
						continue;
					}
					if(count>1)
					{
						x=0;
						num2=0;
						if(biao<r)
						x=min(chengchu[biao]-1,jiajiandeng[m]-1);
						else
						x=jiajiandeng[m]-1;
						y=0;
						while(isdigit(a[x])!=0)
						{
						
						num2=num2+(a[x]-'0')*f(y);
						x--;
						y++;
						
						
						}
						y=0;
						num1=end[shu];
						if(a[n]=='*')
						end[shu]=num1*num2;
						else
						end[shu]=num1/num2;
					}
				}
				
			}
			if(difference==0)
			{
				for(n=jiajiandeng[m-1]+1;n<jiajiandeng[m];n++)
				{
					temp=jiajiandeng[m]-n-1;
					end[shu]+=(a[n]-'0')*f(temp);
				}
			}
			shu++;
			difference=0;
		}
		continue;	
			
		
	}//计算各个加减空档中的数字 
		num=end[0];
		for(p=0;p<jiajianhe-1;p++)
		{
			
			hold=jiajiandeng[p];
			if(a[hold]=='+')
			num=num+end[p+1];
			if(a[hold]=='-')
			num=num-end[p+1];
		}//计算结果 
		printf("%d",num);		
						
	return 0;
}

	

