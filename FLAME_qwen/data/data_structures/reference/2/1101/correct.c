#include<stdio.h>
#include<string.h>
#define N 10000
char c[N];
int num[N];
char sgn[N];
char jiajian[N];
int main()
{
	int i,j,k; 
	int sum=0;
	char temp;
	int cnt_num=0,cnt_sgn=1;
	int cnt_jiajian=0;
	sgn[0]='+';
    while(sgn[cnt_sgn-1]!='=')
	{
		scanf("%d",&num[cnt_num++]);
		scanf("%c",&temp);
		while(temp==' ')
		    scanf("%c",&temp);
		sgn[cnt_sgn++]=temp;
	}
	for(i=0;i<cnt_sgn;i++)
	{
		if(sgn[i]=='+'||sgn[i]=='-')
		{
			jiajian[cnt_jiajian++]=i;
		}
	}
	jiajian[cnt_jiajian]=cnt_sgn-1;
	for(k=0;k<cnt_jiajian;k++)
	{
		int a;
		a=num[jiajian[k]];
		for(i=jiajian[k]+1;i<jiajian[k+1];i++)
		{
			if(sgn[i]=='*') 
			    a*=num[i];
			else if(sgn[i]=='/')
			    a/=num[i];
		}
		if(sgn[jiajian[k]]=='+')
		    sum+=a;
		else if(sgn[jiajian[k]]=='-')
		    sum-=a;
	}
	printf("%d",sum);
	return 0;
}

