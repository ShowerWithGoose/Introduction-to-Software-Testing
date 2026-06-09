#include<stdio.h>
int main()
{
	char od[1000],nw[1000],fh[1000],fh1[1000],fh2[1000];
	int num1[1000]={0},num2[1000]={0},num3[1000]={0};
	int result,i,j,k,l,a,t;
	gets(od);
	for(i=0,j=0;od[i]!='\0';i++)
	{
		if(od[i]==' ')
		continue;
		nw[j++]=od[i];
	}
	for(i=0,l=0;i<j;i++)
	{
		if(nw[i]<'0'||nw[i]>'9') 
		{
		fh[l]=nw[i];
		l++;
		continue;
		}
		k=i+1;
		for(a=1;nw[k]<='9'&&nw[k]>='0';k++)a=a*10;
		num1[l]=num1[l]+a*(nw[i]-'0');	
	}
	
	for(i=0,t=0;i<l;i++)
	{
		if(fh[i]=='+'||fh[i]=='-')
		fh1[t++]=fh[i];
		else if(fh[i]!='=')
		{
			switch(fh[i])
			{
				case '*': num1[i+1]=num1[i]*num1[i+1]; break;
				case '/': num1[i+1]=num1[i]/num1[i+1]; break;
			}
			num1[i]=0;
			
		}
	}
	for(i=0,j=0;i<=l;i++)
	{
		if(num1[i]!=0)
		num2[j++]=num1[i];
	}
	
	
    result=num2[0];
    for(i=0;i<t;i++)
    {
    	if(fh1[i]=='+')
    	result=result+num2[i+1];
    	if(fh1[i]=='-')
    	result=result-num2[i+1];
	}
	printf("%d",result);
	return 0;

}

