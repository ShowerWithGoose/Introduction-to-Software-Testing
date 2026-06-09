#include<stdio.h>
#include<string.h>
int xishu1[100]={0},zhishu1[100]={0},xishu2[500]={0},zhishu2[500]={0},num1[100]={0},num2[100]={0};
	int ansx[250000]={0},ansz[250000]={0};
 int main()
{
	
	int i=0,sum1=0,sum2=0,l1,l2;
	
	char math1[1000],math2[1000];
	int fuhao=1;
	gets(math1);
	gets(math2);
	l1=strlen(math1);
	l2=strlen(math2);
     i=0;
	for(int j=0;j<=l1;j++)
	{
		if(math1[j]>='0'&&math1[j]<='9')
		num1[i]=num1[i]*10+math1[j]-'0';
		else if(math1[j]=='-')
		{
			fuhao=-1;
		}
		else
		{
		if(i%2==0) 
		{
		xishu1[i/2]=num1[i];
		
	}
		else 
		{
		zhishu1[i/2]=num1[i];
		}
		i++;
		fuhao=1;
	}
		
	}
	sum1=(i+2)/2;
	i=0;
	for(int j=0;j<=l2;j++)
	{
		if(math2[j]>='0'&&math2[j]<='9')
		num2[i]=num2[i]*10+math2[j]-'0';
		else if(math2[j]=='-')
		fuhao=-1; 
		else
	{
		if(i%2==0) xishu2[i/2]=num2[i];
		else 
		{
		zhishu2[i/2]=num2[i];
		
}
		i++;
		fuhao=1;
	}
	}
	sum2=(i+2)/2;


	i=0;
	for(int j=0;j<sum1;j++)
	for(int k=0;k<sum2;k++)
	{
		ansx[i]=xishu1[j]*xishu2[k];
		ansz[i]=zhishu1[j]+zhishu2[k];
		i++;
	}
	int n=(sum1+1)*sum2;

	int hold; 
for (i = 0; i < n-1; i++)
{

for (int j = 0; j < n-1-i; j++)
{
if (ansz[j] < ansz[j + 1])
{
hold = ansz[j];
ansz[j] = ansz[j + 1];
ansz[j + 1] = hold;
hold = ansx[j];
ansx[j] = ansx[j + 1];
ansx[j + 1] = hold;

}
else if(ansz[j]==ansz[j+1])
{
	ansx[j]+=ansx[j+1];
	ansx[j+1]=0;
	ansz[j+1]=-1;
	
}
}

}
i=0;
while(i<sum1*sum2)
{   if(ansx[i]!=0)
	printf("%d %d ",ansx[i],ansz[i]);
	
	
	i++;
}
return 0;
 } 

