#include<stdio.h>
#include<string.h>
#define max 1000
int main()
{
	char str[max];
	char str_before[max],str_after[max],str_tmp[max],str_tmp2[max];
	int num,sum=1,tmp;
	gets(str);
if(strchr(str,'.')!=NULL)
{
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]=='.')
		{
			num=i;
			break;
		}
	}
//	printf("%s\n",str);
//	printf("%d\n",num);
	for(int i=0;i<num;i++)
	{
		str_before[i]=str[i];
        str_before[i+1]='\0';
	}
//	printf("%s\n",str_before);
//	printf("%d\n",strlen(str_before));
	for(int i=num+1,j=0;i<strlen(str);i++)
	{
		str_after[j]=str[i];
		str_after[j+1]='\0';
		j++;
	}
//	printf("%s\n",str_after);
	if(strlen(str_before)==1)
	{
		if(str_before[0]=='0')
		{
			for(int i=0;i<strlen(str_after);i++)
			{
				if(str_after[i]=='0')
				{
					sum++;
				}
				else
				{
					num=i;
					break;
				}
			}
			for(int i=num,j=0;i<strlen(str_after);i++)
			{
				str_tmp[j]=str_after[i];
				str_tmp[j+1]='\0';
				j++;
			}
			if(strlen(str_tmp)==1)
			{
				printf("%ce%d",str_tmp[0],-sum);
			}
			else
			{
				printf("%c.%se%d",str_tmp[0],str_tmp+1,-sum);
			}
			
		}
		else if('0'<str_before[0]&&str_before[0]<='9')
		{
			printf("%se0",str);
		}
	}
	else if(strlen(str_before)>1)
	{
		sum=strlen(str_before)-1;
		strcpy(str_tmp2,str_before+1);
		strcat(str_tmp2,str_after);
		printf("%c.%se%d",str_before[0],str_tmp2,sum);
	}
}
else
{
	if(strlen(str)==1)
	{
		printf("%se0",str);
	}
	else
	{
	sum=strlen(str)-1;
	printf("%c.%se%d",str[0],str+1,sum);
    }
}
	return 0;
}



