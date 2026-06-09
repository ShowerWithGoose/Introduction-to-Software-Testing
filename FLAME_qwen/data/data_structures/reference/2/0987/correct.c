#include<stdio.h>
#include<string.h>
char s[1000];
char p[1000];
char real[1000];

int isplus(char c)
{
	if(c=='+') return 1;
	else return 0;
}
int issub(char c)
{
	if(c=='-') return 1;
	else return 0;
}
int ismlp(char c)
{
	if(c=='*') return 1;
	else return 0;
}
int isdvd(char c)
{
	if(c=='/') return 1;
	else return 0;
}
int isnum(char c)
{
	if(c>='0'&&c<='9') return 1;
	else return 0;
}
int numcn(char c)
{
	return c-'0';
}

int idpas[100];
int idmad[100];
int id[100];
int numcase1[100];
int i=0;
int j=0;
int yet=0;
int inpo=0;
int flag=0;
int wait[2];
int sum=0;
int kilo=0;
int cnt=0;

int main()
{
	gets(s);
	while(i<strlen(s))
	{
		if(s[i]!=' ')
		{
			p[j++]=s[i];
		}
		i++;
	}
	p[j]='\0';
	
	i=0;
	j=0;
	
	for(int k=0;k<strlen(p);k++)
	{
		if(isnum(p[k]))
		{
			kilo=numcn(p[k]);
			cnt=1;
			while(isnum(p[k+1]))
			{
				kilo=kilo*10+numcn(p[++k]);
				cnt++;
			}			
		}
		else if(isplus(p[k])||issub(p[k]))	
		{
			real[yet++]=p[k];
			if(flag){
				wait[1]=kilo;
				if(ismlp(p[k-cnt-1]))	
					kilo=wait[0]*wait[1];
				else 				
					kilo=wait[0]/wait[1];
				cnt=0;	
				wait[0]=0;
				wait[1]=0;
				flag=0;
			}
			numcase1[inpo++]=kilo;
		}
		else if(ismlp(p[k])||isdvd(p[k]))	
		{
			if(flag)
			{
				if(ismlp(p[k-cnt-1]))	wait[0]*=kilo;
				else 				wait[0]/=kilo;
				cnt=0;
			}else{
				wait[0]=kilo;
				flag=1;
			}
		}
		else {
			if(flag)
			{
				if(ismlp(p[k-cnt-1]))	numcase1[inpo++]=wait[0]*kilo;
				else 				numcase1[inpo++]=wait[0]/kilo;
				cnt=0;
				flag=0;
			}else{
				numcase1[inpo++]=kilo;
			}
		}	
	}
	sum=numcase1[0];
	for(int lp=0;lp<strlen(real);lp++)
	{
		if(isplus(real[lp]))
		{
			sum+=numcase1[lp+1];
		}else if(issub(real[lp])){
			sum-=numcase1[lp+1];
		}	
			
	}
	printf("%d",sum);
	
	return 0;
}

