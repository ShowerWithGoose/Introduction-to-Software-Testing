#include<stdio.h>
#include<string.h>

int jishuqi( char [] );
int jisuan(int ,int ,int );         //  计算 

int s2[1000],s3[1000];       //   s2 表示 数      s3 表示 运算符 
                                        //   1:+   2:-   3:*   4:/    5:=


int main()
{
	char s1[1000];

    gets(s1);
    
    int a,i,j=0;
    
    a=strlen(s1);
    for(i=0;i<a;i++)
    {
    	if(s1[i] != ' ') s1[j++]=s1[i];
	}
	s1[j]='\0';
    
    int m,n,k;
    
    m=jishuqi(s1);              //   计数，取运算符 
	
	int sum=0,x=0,y=0,temp;
	
	if(m==1)
	{
		printf("%d",s2[0]);
	}
	
	if(m==2)
	{
		printf("%d",jisuan(s2[0],s2[1],s3[0]));
	}
	
	i=0;j=0;k=0;
	if(m>=3)
	{
		x=s2[0];
		while(s3[i]!=5)
		{
			y=s2[i+1];
			if(s3[i]<3)
			{
				if(k==0)
				{
					k=s3[i];
					sum=x;
				}
				else
				{
					sum=jisuan(sum,x,k);
					k=s3[i];
				}
				
				x=s2[i+1];
			}
			if(s3[i]>2)
			{
				x=jisuan(x,y,s3[i]);
			}
			i++;
		}
		if(k==0) sum=x;
    	else sum=jisuan(sum,x,k);
    
    	printf("%d",sum);
	}
    

	return 0;
}

int jishuqi( char s1[] )          //  返回总数 j 
{
	int i,j,k;
	k=strlen(s1);
	
	i=0;
	j=0;
	while(s1[i]!='\0')
	{
		while(s1[i]>='0' && s1[i]<='9')
		{
			s2[j]=s2[j]*10+s1[i]-'0';
			i++;
		}
		
		if(s1[i]=='+')  s3[j]=1;
		if(s1[i]=='-')  s3[j]=2;
		if(s1[i]=='*')  s3[j]=3;
		if(s1[i]=='/')  s3[j]=4;
		if(s1[i]=='=')  s3[j]=5;
		
		i++;
		j++;
	}
	
	return j;
}

int jisuan(int x,int y,int t)
{
	switch(t){
		case 1: return x+y;
		case 2: return x-y;
		case 3: return x*y;
		case 4: return x/y;
	}
}


