#include <stdio.h>
#include <string.h>
int pingfang(int n,int sum)
{
	if(n>1)
	{
			for(int i=1;i<n;i++)
		{
			sum*=10;
		}
		return sum;
	}
	else
	return sum;
}
int main()
{
	char a[1000],f[1000];
	int b[1000],c[1000],d[1000],e[1000],h[1000];
	int j=0,l1,n1=0,n2=0,y=0,g,t=0,u=0,v=0,m=0,nf,ns; 
	int ans=0;
	gets(a);
	memset(b,0,sizeof(b));
	memset(e,0,sizeof(e));
	memset(f,0,sizeof(f));
	b[0]=-1;
	for(int i=0;a[i]!='\0';i++)//除掉空格 
	{
		if(a[i]!=' ')
		{
			a[j++]=a[i];
		}	
	}
	a[j]='\0';
    l1=strlen(a);
    for(int i=0;i<l1;i++)
    {
    	if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='=')
    	{
    		f[n1]=a[i];//记下符号的种类 
			n1++;//n1=3
    		b[n1]=i;//标记符号的位置 (500-12-12=)
		}
	}
	for(int i=0;i<n1;i++)
	{
		c[i]=b[i+1]-b[i]-1;//标记每两个符号间数字长度 (3,2,2)
	}
	for(int i=0;i<l1;i++)
    {
    	if(a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'&&a[i]!='=')
    	{
    		d[n2]=a[i]-'0';//将字符变成数字 （d=5001212) 
    		n2++;//n2=7
		}
	}
	for(int i=0;i<n1;i++)
	{
		for(int z=c[i];z>=1;z--)//c0=3
		{
			e[i]+=pingfang(z,d[y]);//将单个数字变成整体 
			y++;
		}
	}
	if(n1>1)//数字已标记，e[0]=5,e[1]=1,e[2]=2,e[3]=3,e[4]=12,e[5]=2,e[6]=2; 
	{//符号已标记，f[0]=-,f[1]=*,f[2]=*,f[3]=+,f[4]=/,f[5]=/
		//5-1*2*3+12/2/2
		nf=n1-1;//	符号 
		ns=n1;//	数字 
		for(int i=0;i<nf;)
		{
			if(f[i]=='/')
			{
				e[i]/=e[i+1];
				for(int s=i+1;s<ns-1;s++)
				{
					e[s]=e[s+1];
				}
				for(int s=i;s<nf-1;s++)
				{
					f[s]=f[s+1];
				}
				ns--;
				nf--;
			}
			else if(f[i]=='*')
			{
				e[i]*=e[i+1];
				for(int s=i+1;s<ns-1;s++)
				{
					e[s]=e[s+1];
				}
				for(int s=i;s<nf-1;s++)
				{
					f[s]=f[s+1];
				}
				nf--;
				ns--;
			}
			else i++;
		}
		if(nf!=0)
		{
			ans=e[0];
			for(int i=0;i<nf;i++)
			{
				if(f[i]=='+')
				{
					ans+=e[i+1];
				}
				else if(f[i]=='-')
				{
					ans-=e[i+1];
				}
			}
		}
		else
		{
			ans=e[0];
		}
		printf("%d",ans);
	}
	else
	{
		printf("%d",e[0]);
	}
	return 0;
}
	

