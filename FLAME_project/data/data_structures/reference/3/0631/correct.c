#include<stdio.h>
#include<string.h>
int main()
{
	char num[105];
	char science[105];
	scanf("%s",num);
	int i,j,k;
	int count=0;
	int single;
	int mark;
	if(num[0]=='0')
	{
		for(i=2;num[i]!='\0';i++)
		{
			if(num[i]!='0')
			{
				count++;
			}
			else if(i!=2&&num[i]=='0'&&num[i-1]!='0')
			{
				count++;
			}
		}	
		if(count==1)
		{
			single=num[i-1]-'0';
			printf("%de-%d",single,i-2);
		}
		else
		{
			science[0]=num[i-count];
			science[1]='.';
			k=2;
			for(j=i-count+1;num[j]!='\0';j++)
			{
				science[k]=num[j];
				k++;
			}
			science[k]='\0';
			printf("%se-%d",science,i-1-count);
		}
	}
	else
	{
		j=2;
		science[0]=num[0];
		science[1]='.';
		for(i=1;num[i]!='\0';i++)
		{
			if(num[i]!='.')
			{
				science[j]=num[i];
				j++;
			}
			else
			{
				mark=i;
			}
		}
		science[j]='\0';
		printf("%se%d",science,mark-1);
	}
	return 0;	
}

