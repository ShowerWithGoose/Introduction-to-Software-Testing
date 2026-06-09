#include <stdio.h>
#include <string.h>
char save[1000]={'\0'},sign[1000]={'\0'};
int ans[100]={0},shu[100]={0};
void change(char save[],int lent);
int cal(char sign[],int shu[]);
int main()
{
	int i,len,j=0,ret;
	char in[1000]={'\0'};
	gets(in);
	len=strlen(in);
	for(i=0 ;i<len ;i++)
	{
		if((in[i]>='0'&&in[i]<='9')||in[i]=='+'||in[i]=='-'||in[i]=='*'||in[i]=='/'||in[i]=='=')
		{
			save[j]=in[i];j++; 
		}
	}
	change(save,len);
	ret=cal(sign,shu);
	printf("%d",ret);
	return 0;
}

void change(char save[],int lent)
{
	int i=0,cnt=0,fig=0,j=0;
	for(i=0 ;i<lent ;i++)
	{
		if(save[i]>='0'&&save[i]<='9')
		{
			fig=10*fig+save[i]-'0';
			if(save[i+1]<'0'||save[i+1]>'9')
			{
				shu[j]=fig;
				fig=0;	
			} 
		}	
		else 
		{
			sign[j]=save[i];
			j++;
		}
	}
}

int cal(char sign[],int shu[])//3+8*9*8+5*7+9-5           5*6*9+2   5*9+5-9
{
	int j=0,lent=strlen(sign),retM=0,ret=0,st,tmp,cnt=0,flag=0;
	if(sign[0]=='=')
		return shu[0];
	else
	{
		for(j=0 ;j<lent ;j++)//É¨Ãè³Ë³ıºÅ 
		{
			if(sign[j]=='*'||sign[j]=='/')
			{
				tmp=shu[j];
				for(st=j ;sign[st]=='*'||sign[st]=='/';st++)
				{
					if(sign[st]=='*')
					{
						retM=tmp*shu[st+1];
						tmp=retM;
						shu[st+1]=0;sign[st]='+';
					}
					if(sign[st]=='/')
					{
						retM=tmp/shu[st+1];
						tmp=retM;
						shu[st+1]=0;sign[st]='+';
					}		
				}
				shu[j]=retM;
			}
		}
		for(j=0 ;j<lent ;j++)//É¨Ãè¼Ó¼õºÅ
		{
			tmp=shu[0];
			if(sign[j]=='+')
			{
				ret=shu[j]+shu[j+1];
				shu[j+1]=ret;
			}
			else if(sign[j]=='-')
			{
				ret=shu[j]-shu[j+1];
				shu[j+1]=ret;
			}
		}
	}
	return ret;
}

