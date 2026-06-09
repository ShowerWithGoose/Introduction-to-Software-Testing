#include<stdio.h>
int jisuan(char* a,int longth)
{
	char fuhao[100];
	int shuzi[100];
	int result=1;
	int k=1;
	fuhao[0]=-1;
	for(int i=0;i<longth;i++)
	{
		if(a[i]=='*'||a[i]=='/') fuhao[k++]=i;
	}
	fuhao[k]=longth;
	for(int i=0;i<k;i++)
	{
		int shu=0;
		for(int j=fuhao[i]+1;j<fuhao[i+1];j++)
		{
			shu=shu*10+a[j]-'0';
		}
		shuzi[i]=shu;
	}
	result=shuzi[0];
	if(k==1) return result;
	for(int i=1;i<k;i++)
	{
		if(*(a+fuhao[i])=='*') result*=shuzi[i];
		else if(*(a+fuhao[i])=='/') result/=shuzi[i];
	}
	return result;
}
int main()
{
	char shuru[1000];
	char chuli[1000];
	char fuhao[1000];
	fuhao[0]=-1;
	int k=1;
	int result=0;
	gets(shuru);
	for(int i=0,j=0;shuru[i]!='\0';i++)
	{
		if(shuru[i]==' ') continue;
		else chuli[j++]=shuru[i];
	}
	for(int i=0;chuli[i]!='\0';i++)
	{
		if(chuli[i]=='+'||chuli[i]=='-'||chuli[i]=='=')
		fuhao[k++]=i;
	}
	
	result=jisuan(chuli,(fuhao [1]-fuhao[0]-1));
	
	for(int i=1;i<k;i++)
	{
		if(*(chuli+fuhao[i])=='+') result+=jisuan((chuli+fuhao[i]+1),(fuhao[i+1]-fuhao[i]-1));
		else if(*(chuli+fuhao[i])=='-') result-=jisuan((chuli+fuhao[i]+1),(fuhao[i+1]-fuhao[i]-1));
		else if(*(chuli+fuhao[i])=='=') break;
	}
	
	printf("%d",result);
	return 0;
}

