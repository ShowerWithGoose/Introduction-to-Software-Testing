#include<stdio.h>
#include<string.h>
int main()
{
	int i,len,hi[100],lo[100],num[100],nums[100],j=0,k=0,cha=0,t=0,result;
	char etc[100],str1[100],str2[100];
	gets(etc);
	for(i=0;i<100;i++)
	{
		if(etc[i]==' ')
		;
		else
		if(etc[i]=='\0')
		break;
		else
		str1[cha++]=etc[i];
	}
	num[0]=0;
	for(i=0;i<cha;i++)
	{
		if(str1[i]>='0'&&str1[i]<='9')
		{
		num[j]=num[j]*10+(str1[i]-'0');
    	}
    	else
		{
    		hi[k++]=i;
    		j++;
    		num[j]=0;
		}
	}
    for(i=0;i<j;i++)
    {
    	if(str1[hi[i]]=='*')
    	num[i+1]=num[i]*num[i+1];
    	else if(str1[hi[i]]=='/')
    	num[i+1]=num[i]/num[i+1];
    	else if(str1[hi[i]]=='-'||str1[hi[i]]=='+')
    	{
		nums[t]=num[i];
		lo[t++]=hi[i];
		}
		else if(str1[hi[i]]=='=')
		
		{
			nums[t]=num[i];
			lo[t++]=hi[i];
			break;
		}
	}
	result=nums[0];
	for(i=0;i<t;i++)
	{
		if(str1[lo[i]]=='-')
		result-=nums[i+1];
		else if(str1[lo[i]]=='+')
		result+=nums[i+1];
		else if(str1[lo[i]]=='=')
		break;
	}
	printf("%d",result);
	return 0;
}



