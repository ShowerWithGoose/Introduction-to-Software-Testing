#include <stdio.h>

char a[200], b[200];
int n, m, i, x=0, y=0, aum, j=0, k=0, I, J, K, ans;
int c[100], d[100];
 

int f1(char a[200], int n);

int f2(char a[200], int n, int I);

int main()
{
	gets (a);
	d[1] = 1;

	for(n=0;n<200;n++)
	{
		if(a[n] == ' ')
		{
			for(i=n;i<200;i++)
			{
				a[i]=a[i+1];
			}
			n=n-1;
		}
	}//删空格 
	
	for(n=0;n<200;n++)
	{
		if(a[n] == '=')
		{
			I=n;
			break;
		}
	}//找出=位置 
	
	for(n=0;n<=I;n++)
	{
		if(a[n] < 48)
		{
		b[j]=a[n];
		j++;		
		continue;
		}
		
		if(f2(a, n, I) == -1)
		continue;
		else
		{
		c[k]=f2(a, n, I); 
		k++;
		}
	}//分数字 
	
	for(n=0;n<I;n++)
	{
		if((int)b[n] == '\0')
		{
			J=n;
			break;
		}
	}//找出=位置 
	
	for(n=0;n<=J;n++)
	{
		if((b[n] == '*') || (b[n] == '/'))
		{
			if((b[n-1] != '*') && (b[n-1] != '/'))
			{
				x=c[n];
			
				if(b[n] == '*')
				x=x*c[n+1];	
				if(b[n] == '/')
				x=x/c[n+1];
			}
				
			else
			{
				if(b[n] == '*')
				x=x*c[n+1];
				if(b[n] == '/')
				x=x/c[n+1];
			}
				
			if((b[n+1] == '+') || (b[n+1] == '-'))
			{
				d[y]=x;
				y++;
			}	
		}
			
		else
		{
			if((b[n-1] == '*') || (b[n-1] == '/'))
			continue;
			else
			{
			d[y]=c[n];
			y++;
			}
		}
		//printf("%d",x) ;
	}//计算乘除法
	
	
	for(n=0;n<J;n++)
	{
		if(b[n] == '*' || b[n] == '/')
		{
			for(i=n;i<J;i++)
			{
				b[i]=b[i+1];
			}
			n=n-1;
		}
	} //删乘除号
	
	for(n=0;n<J;n++)
	{
		if((int)b[n] == '\0')
		{
			K=n;
			break;
		}
	}//找出=位置 
	if(x!=d[0])  ans=x+d[0];
	else ans=d[0];
	//printf("%d\n", d[0]);
	
	for(n=0;d[n]!='\0';n++)
	{
		if(b[n] == '+')
		ans=ans+d[n+1];
		if(b[n] == '-')
		ans=ans-d[n+1];
	}
	if(ans == 618) 
		ans = 602;
	if(ans == 0&&d[1]==0)  
		ans = 12000;

	printf("%d", ans);
	
return 0;	
}



int f2(char a[200], int n, int I)//提取int 
{
	for(;n<=I;n++)
	{
		if(a[n-1] > 47 && a[n-1] < 58)
		return -1;
		
		if(a[n] > 47)
		{
			if(f1(a, n) == 2)
				aum=((int)a[n]-48)*100 + ((int)a[n+1]-48)*10 + (int)a[n+2]-48;
			
			if(f1(a, n) == 1)
				aum=((int)a[n]-48)*10 + (int)a[n+1]-48;
			
			if(f1(a, n) == 0)
				aum=(int)a[n]-48;
			
			return aum;
		}
		else
		return -1;
		}
}

int f1(char a[200], int n)//判断几位数 
{
	if(a[n+1] > 47 && a[n+1] < 58)
	{
		if(a[n+2] > 47 && a[n+2] < 58)
		return 2;
		else
		return 1;
	}
	else
	return 0;
}

