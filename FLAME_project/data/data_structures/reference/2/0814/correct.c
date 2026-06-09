#include <stdio.h>
int main()
{
	char sta[105];
	int num[55]={0};
	int i=0,j=0;
	gets(sta);
	while(sta[i]!='\0')
	{
	    for(;sta[i]>='0'&&sta[i]<='9';i++)
	    {
		    num[j]=num[j]*10+sta[i]-'0';
	    }
	    if(sta[i-1]>='0'&&sta[i-1]<='9')
		    j++;
		    i++;
	}
//	for(i=0;i<j;i++) printf("%d ",num[i]);
    char symbol[55];
    int k=0;
    for(i=0;sta[i]!=0;i++)
    {
    	if(sta[i]=='+'||sta[i]=='-'||sta[i]=='*'||sta[i]=='/')
    	symbol[k++]=sta[i];
	}
//	for(i=0;i<k;i++) printf("%c",symbol[i]);
    int result;
    for(i=0;i<k;i++)
    {
    	if(symbol[i]=='*')
    	{
    		result=num[i]*num[i+1];
    		num[i]=result;
    		num[i+1]=result;
		}
		if(symbol[i]=='/')
    	{
    		result=num[i]/num[i+1];
    		num[i]=result;
    		num[i+1]=result;
		}
	}
	int count=0;
	for(i=k;i>0;i--)
	{
		if((symbol[i]=='*'&&symbol[i-1]=='*')||(symbol[i]=='*'&&symbol[i-1]=='/')||(symbol[i]=='/'&&symbol[i-1]=='*')||(symbol[i]=='/'&&symbol[i-1]=='/'))
		{
			num[i-1]=num[i];
		}
	}
	result=num[0];
	for(i=0;i<k;i++)
    {
    	if(symbol[i]=='+')
    	{
    		result=result+num[i+1];
		}
		if(symbol[i]=='-')
    	{
    		result=result-num[i+1];
		}
	}
	printf("%d",result);
	return 0;
} 

