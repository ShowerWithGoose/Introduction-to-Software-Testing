#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h> 
int main()
{
	char temp[100],temp1[100],holdnum[100];
	gets(temp1);
	long long putin[100],hold=0,m,mid[100],i=0,j=0,i1,j1,numin=0,k;
	while(temp1[i]!='=')
	{
		if(temp1[i]!=' ')
		{
			temp[j++]=temp1[i++];
			continue;
		}
		i++;
	}
	j1=j;
	for(i=0,j=0;i<j1;)
	{	
		if(temp[i]=='+'||temp[i]=='-'||temp[i]=='*'||temp[i]=='/')
		{
			putin[j++]=temp[i++];
			continue;
		}
		if(temp[i+1]=='+'||temp[i+1]=='-'||temp[i+1]=='*'||temp[i+1]=='/')
		{
			putin[j++]=temp[i++]-'0';
			continue;
		}		
		k=0;
		m=1;
		hold=0;
		while(temp[i]>='0'&&temp[i]<='9')
		{
			holdnum[k++]=temp[i++];				
			m*=10;		
		}
		m/=10;
		for(i1=0;i1<k;m/=10,i1++)
		{
			hold+=(holdnum[i1]-'0')*m;
		}
		putin[j++]=hold;
	}
	putin[j]='\0';
	i=0;
	j=0;
	while(putin[i]!='\0')
	{
		if(putin[i+1]!='*'&&putin[i+1]!='/')
		{
			mid[j++]=putin[i++];
			continue;
		}
		while(putin[i+1]=='*'||putin[i+1]=='/')
		{
			switch(putin[i+1])
			{
				case '*':{
					hold=(putin[i])*(putin[i+2]);
					i+=2;
					break;
				}
				case '/':{
					hold=(putin[i])/(putin[i+2]);
					i+=2;
					break;
				}			
			}
			putin[i]=hold;
		}
		mid[j++]=putin[i++];
		mid[j++]=putin[i++];		
	}
	mid[j]='\0';
	i=0;
	j=0;
	hold=mid[0];
    while(mid[i+1]!='\0')
	{
		if(mid[i+1]=='+')
		{
			hold+=mid[i+2];
			i+=2;
		}
		else
		{
			hold-=mid[i+2];
			i+=2;			
		}
	}	
	printf("%lld",hold);
}

