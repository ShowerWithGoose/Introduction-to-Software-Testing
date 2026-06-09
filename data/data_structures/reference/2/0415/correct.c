#include <stdio.h>
int readInt(char *ch)
{
	int X=0;
	*ch=getchar();
	while(*ch<'0'||*ch>'9')*ch=getchar();
	while(*ch>='0'&&*ch<='9'){
		X=X*10+*ch-'0';
		*ch=getchar();
	}
	return X;
}
char function[1000];
int num[1001];
int main()
{
	char ch;
	int cnt=0;
	while(ch!='='){
		num[cnt]=readInt(&ch);
		while(ch==' ')ch=getchar();
		function[cnt++]=ch;//·ûºÅ 
	}
	
	for(int i=0;i<cnt;i++){
		int now=i;
		while(function[now]=='*'||function[now]=='/'){
			if(function[now]=='*') num[i]*=num[now+1];
			else num[i]/=num[now+1];
			num[now+1]=0;
			now++;
		}
		i=now;
	}
	
	for(int i=0;i<cnt;i++)
		if(function[i]=='-')num[i+1]*=-1;
	int sum=0;
	for(int i=0;i<cnt;i++)
		sum+=num[i];
	printf("%d",sum);
	return 0;
}

