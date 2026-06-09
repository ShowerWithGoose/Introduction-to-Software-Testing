#include<stdio.h>
#include<string.h>
#include<math.h>
int shu[500];
int jisuan(char s[]);

int main()
{
	char s[500];
	int i=0;
	memset(shu,0,500);
	gets(s);
	printf("%d",jisuan(s));
	return 0;
}

int jisuan(char s[])
{
	int i=0,num=0,k=0,sum=0,fuhao1,fuhao2;    
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			num=num*10+s[i]-'0';
		}
		else if(s[i]<'0' || s[i]>'9' && s[i]!=' ')
		{
			fuhao1=s[i];
			shu[k++]=num;
			num=0;
			i++;
			break;
		}
	}
	for(;i<strlen(s);i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			num=num*10+s[i]-'0';
		//	printf("num=%d\n",num);
		}
		else if((s[i]<'0' || s[i]>'9')&& s[i]!=' ')
		{
		//	fuhao2=s[i];
			switch(fuhao1)
			{
				case '+':
					shu[k]=num;
		//			printf("shu[%d]=%d\n",k,shu[k]);
					num=0;
					k++;
					break;
				case '-':
					shu[k]=-num;
		//			printf("shu[%d]=%d\n",k,shu[k]);
					num=0;
					k++;
					break;
				case '*':
					shu[k-1]*=num;
		//			printf("shu[%d]=%d\n",k-1,shu[k-1]);
					num=0;
					break;
				case '/':
					shu[k-1]/=num;
		//			printf("shu[%d]=%d\n",k-1,shu[k-1]);
					num=0;
					break;
				case '=':
					shu[k]+=num;
					num=0;
					break;
			}
			fuhao1=s[i];
		}
	}
	for(i=k-1;i>=0;i--)
	sum+=shu[i];
	
	return sum;
} 

