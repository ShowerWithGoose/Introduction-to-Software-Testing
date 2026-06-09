#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int f(int i,char s[]){
	int sum;
	for(sum=0;s[i]>='0'&&s[i]<='9';i++)
	{
		sum=sum*10+s[i]-'0';
	}
	return sum;
}
int main()
{
char st[100000],str[10000],strn[10000];
gets(st);
char s[100000];
int i,j,k,m,n,x,y,z;
int num[10000],numb[10000];
for(i=0,j=0;st[i]!='=';i++)
{
	if(st[i]!=' ')
	{
	s[j]=st[i];
	j++;}
}//去除空格和等号 
for(k=0,m=0,n=0;k<=j;k++)
{
	if(s[k]<'0'||s[k]>'9')
	{
		num[m]=f(k+1,s);
		m++;
		str[n]=s[k];
		n++;
	}
}
	int tmp=f(0,s);//第一个数和+-后的数 
	//printf("%d\n",tmp);
	for(x=0,y=0;x<=n;x++)
	{
		if(str[x]=='*')
		{
			tmp*=num[x];
		}
		if(str[x]=='/')
		tmp/=num[x];
		if(str[x]=='+'||str[x]=='-')
		{
			strn[y]=str[x];//strn存+- 
			numb[y]=tmp;
			y++;
			tmp=num[x];
		}	
	}
	//printf("%c",strn[1]);
	//printf("%d\n",y);
	numb[y]=tmp;
	int ans=numb[0];
	//printf("%d\n",numb[2]);
	for(z=0;z<=y-1;z++)
	{
	if(strn[z]=='+')
	ans+=numb[z+1];
	else
	ans-=numb[z+1];	
	}
	printf("%d",ans);
 return 0;
}




