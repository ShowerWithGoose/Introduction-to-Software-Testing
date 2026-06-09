#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char fo[1000],ex[1000],e[1000],v[1000];int i,j=0,n=0,ss[1000]={0},sum=0,m,x=0,b=0,p=0,w[1000]={0},su=1;
	gets(fo);//b=运算符数量，x=数字数量，p=由加减连起来的单位数量， 
	int d=0;
	for(d=0;d<strlen(fo);d++)
	if(fo[d]!=' ')
	{
		ex[j]=fo[d];j++;//去掉空格 
	}
	for(n=0;n<j;n++)
	{
		sum=0;m=0;
		if(ex[n]>='0'&&ex[n]<='9')
		{
			while(ex[n]>='0'&&ex[n]<='9')
			{
				sum=sum*10+(ex[n]-'0');
				m++;n++;
			}
		ss[x]=sum;x++;//存储数字 
		}
	}
	for(i=0;i<strlen(ex);i++)
	{
	 if(ex[i]<'0'||ex[i]>'9')
	 {
		e[b]=ex[i];b++;//只存运算符 
	 }
	 if(ex[i]=='+'||ex[i]=='-'||ex[i]=='=')
	 {
	 	v[p]=ex[i];p++;//只存加减号和等号 
	 }
	}p=0;int y=0;
	for(y=0;y<b;y++)
	{su=1;
		if((e[y]=='+'||e[y]=='-'||e[y]=='=')&&(y==0||e[y-1]=='+'||e[y-1]=='-'))
		{
		w[p]=ss[y];p++;}
		if(e[y]=='/'||e[y]=='*')
		{
			su=ss[y];
			while(e[y]=='/'||e[y]=='*')
			{
		    if(e[y]=='/')
			su=su/ss[y+1];
			if(e[y]=='*')
			su=su*ss[y+1];
			y++;}
			w[p]=su;p++;y--;//每个单位的值 
		}
	 }su=w[0];int u=0;
	 for(u=0;u<p;u++)
	 {
	 	if(v[u]=='+')
	 	su+=w[u+1];
	 	else if(v[u]=='-')
	 	su-=w[u+1];
	 	else
	 	printf("%d",su);
	  } 
 } 

