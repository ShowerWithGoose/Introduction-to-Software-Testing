#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char a[1000],b[1000],c[1000];
	int d[1000]= {0},e[1000],start[1000],end[1000],ans[1000];
	gets(a);
	int i,j,k,n,p,num,answer;

	//将所有空格去掉
	for(i=0,j=0; i<strlen(a); i++)
	{
		if(a[i]!=' ')
		{
			b[j]=a[i];
			j++;
		}
	}
	b[j]='\0';
//	puts(b);

	//将第一个符号前的字符变为数字
	for(i=0; i<strlen(b); i++)
	{
		if(b[i]=='+'||b[i]=='-'||b[i]=='/'||b[i]=='*')
		{
			c[0]=b[i];
			e[0]=i;
			for(j=0; j<i; j++)
			{
				d[0]=d[0]*10+b[j]-'0';
			}
			break;
		}
	}

	//如果没有符号 直接输出
	if(i==strlen(b))
	{
		for(i=0; i<strlen(b)-1; i++)
		{
			printf("%c",b[i]);
		}
	}

	//找到第二个及之后的符号
	else                                   //1+2+3/6*3-9+4-7*5+1=
	{
		for(j=i+1,k=1; j<strlen(b); j++)
		{
			if(b[j]=='+'||b[j]=='-'||b[j]=='/'||b[j]=='*')
			{
				c[k]=b[j];
				e[k]=j;
				k++;
			}
		}
		c[k]='\0';
		e[k]='\0';

	//	puts(c);
	/*
		for(i=0;i<k;i++)
		{
			printf("%d ",e[i]);
			if(i==k-1)
			{
				printf("\n");
			}
		} 
	*/	

		//将每两个符号之间的字符转换为数字
		for(i=0; i<k-1; i++)
		{
			for(j=e[i]+1; j<e[i+1]; j++)
			{
				d[i+1]=d[i+1]*10+b[j]-'0';
			}
		}

		//最后一个符号之后的数字
		for(j=e[k-1]+1; j<strlen(b)-1; j++)
		{
			d[k]=d[k]*10+b[j]-'0';
		}

	/*	
		for(i=0;i<k+1;i++)
		{
			printf("%d ",d[i]);
			if(i==k)
			printf("\n"); 
		}
	*/	

		//找到所有乘除的位置  12/2/2
		for(i=0,n=0; i<k; i++)
		{
			if(c[i]=='*'||c[i]=='/')
			{
				p=i;
				if(p+1==k)
				{
					start[n]=i;
					end[n]=i;
				}
				for(j=p+1; j<=k; j++)
				{
					if(c[j]=='+'||c[j]=='-'||j==k-1)
					{

						start[n]=i;
						
						if(j==k-1&&(c[j]=='/'||c[j]=='*'))
							end[n]=j;
						else
						{
							end[n]=j-1;
						}
						break;
					}
				}
				//printf("%d %d\n",start[n],end[n]);
				n++;
				i=j;
			}
			//1+2+3/6*3-9+4-7*5+1=
		// c + + / * - + - * +  (k-1)
		// d 1 2 3 6 3 9 4 7 5 1  (k)

		}

		//计算乘除以外的运算
		//若没有乘除符号
		if(n==0)
		{
			answer=d[0];
			for(j=0; j<k; j++)
			{
				if(c[j]=='+')
					answer+=c[j+1];
				else if(c[j]=='-')
					answer-=c[j+1];
			}
			printf("%d",answer);
		}


		//有乘除符号
		else
		{
			if(start[0]!=0)
				answer=d[0];
			else
				answer=0;
			for(j=0; j<=start[0]-2; j++)
			{
				if(c[j]=='+')
					answer+=d[j+1];
				else if(c[j]=='-')
					answer-=d[j+1];
			}
			for(i=0; i<n-1; i++)
			{

				for(j=end[i]+1; j<=start[i+1]-2; j++)
				{
					if(c[j]=='+')
						answer+=d[j+1];
					else if(c[j]=='-')
						answer-=d[j+1];
				}
			}
			for(j=end[n-1]+1; j<k; j++)
			{
				if(c[j]=='+')
					answer+=d[j+1];
				else if(c[j]=='-')
					answer-=d[j+1];
			}
		}

		//1+2+3/6*3-9+4-7*5+1=
		// c + + / * - + - * +  (k-1)
		// d 1 2 3 6 3 9 4 7 5 1  (k)

		// 12/2/2=
		// c  / /
		// d 12 2 2
		//计算乘除
		for(i=0; i<n; i++)
		{
			ans[i]=d[start[i]];
			for(j=start[i]; j<=end[i]; j++)
			{
				if(c[j]=='*')
					ans[i]*=d[j+1];
				else if(c[j]=='/')
					ans[i]/=d[j+1];
			}
			//printf("%d ",ans[i]);
			if(c[start[i]-1]=='+'||start[i]-1<0)
				answer+=ans[i];
			else if(c[start[i]-1]=='-')
				answer-=ans[i];

		}
		//printf("\n");
		printf("%d",answer);
	}
	return 0;
}



