#include <stdio.h>
#include <string.h>
char str[1050],fbe[1050],type[1050],pymp[2050];
int number[1050],pmu[1050],i,j,k,l,lgt;
int main()
{
	fgets(str,1028,stdin);
	for(i=0,j=0;i<strlen(str);i++)
	{
		if(str[i]!=' ')
			fbe[j++]=str[i];	
	}
	for(i=0,j=0,k=0,l=0;i<strlen(fbe);i++,j++)
	{
		if(fbe[i]=='+'||fbe[i]=='-'||fbe[i]=='*'||fbe[i]=='/'||fbe[i]=='=')
			type[k++]=fbe[i];
		if(fbe[i]>=48&&fbe[i]<=57)
		{
			for(lgt=1;lgt<11;lgt++)
			{
				if(fbe[i+lgt]>=48&&fbe[i+lgt]<=57)
					continue;
				int n=1,num=0,w;
				for(w=lgt;w>0;w--)
				{
					num=num+(fbe[i+w-1]-'0')*n;
					n*=10;
				}
				number[l++]=num;
				i+=lgt-1;
				break;
				if(fbe[i+lgt]<48||fbe[i+lgt]>57)
					break;
			}
		}
	}
	for(i=0,j=0;i<strlen(type)+1;i++)
	{
		if(type[i]=='+'||type[i]=='-'||type[i]=='=')
		{
			pmu[j]=number[i];
			pymp[j]=type[i];
			j++;
		}
		if(type[i]=='*')
			number[i+1]*=number[i];
		if(type[i]=='/')
			number[i+1]=number[i]/number[i+1];
	}
	int put=pmu[0];
	for(i=0;i<strlen(pymp);i++)
	{
		if(pymp[i]=='+')
			put+=pmu[i+1];
		if(pymp[i]=='-')
			put-=pmu[i+1];
	}
	printf("%d",put);
	return 0;
}

