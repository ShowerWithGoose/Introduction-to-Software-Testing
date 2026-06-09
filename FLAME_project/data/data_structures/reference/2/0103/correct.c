#include <stdio.h> 
int a[100000];
char f[100000];
int main()
{
	int cnt=0;
	int temp=getchar();
	while(temp!=EOF&&temp!='\n')
	{
		if(temp!=' ')
		{
			if(temp>='0'&&temp<='9') 
			{
				a[cnt]=temp-'0';
				f[cnt]=1;
				cnt++;
			}	
			else
				a[cnt++]=temp;
		}
			
		temp=getchar();	
	}		
	int t=0,num=0,i;
	for(t=0;t<cnt;t++)
	{
		if(f[t])
		{
			num=num*10+a[t];
			a[t]=num;
		}	
		else
			num=0;
		if(num>9)
		{
			for(i=t;i<cnt;i++)
				a[i-1]=a[i];
			for(i=t;i<cnt;i++)
				f[i-1]=f[i];
			cnt--;
			t--;	
		}	
	}	
	for(t=0;t<cnt;t++)
		if(a[t]=='*'||a[t]=='/')
		{
			if(a[t]=='*')
				a[t+1]*=a[t-1];
			else
				a[t+1]=a[t-1]/a[t+1];
			for(i=t;i<cnt-1;i++)
				a[i-1]=a[i+1];
			cnt-=2;
			t--;
		}		
	for(t=0;t<cnt-1;t++)
	{		
		if(a[t]=='+')
			a[t+1]+=a[t-1];		
		else if(a[t]=='-')
			a[t+1]=a[t-1]-a[t+1];				
	}
	printf("%d",a[cnt-2]);
	return 0;
}


