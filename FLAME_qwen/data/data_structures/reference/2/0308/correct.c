#include<stdio.h>
#include<string.h>
char a[2000000],b[2000000],fh[2000000],fhh[2000000];
int sz[2000000],szz[2000000];
int main()
{
	gets(a);
	int i,j=0,n=0,m=0,num=0,t=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!=' ')
			b[j++]=a[i];
	}
	b[j]='\0';
	int sum=0,jl=-1;
	for(i=0;i<strlen(b);i++)
	{
		if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/'||b[i]=='=')
		{
			fh[t++]=b[i];
			for(j=jl+1;j<i;j++)
    			sz[num]=sz[num]*10+b[j]-'0';
    		num++;
   			jl=i;
  		}
 	}
 	for(i=0;i<num;i++)
 	{
 		if(fh[i]=='+'||fh[i]=='-'||fh[i]=='=')
 		{
 			szz[n++]=sz[i];
 			fhh[m++]=fh[i];
		}
		else
		{
			int jx=sz[i];
			while(fh[i]=='*'||fh[i]=='/')
			{
				if(fh[i]=='*')
					jx*=sz[i+1];
				else
					jx/=sz[i+1];
				i++;
			}
			szz[n++]=jx;
			fhh[m++]=fh[i];
		}
	}
	szz[n]='\0';
	fhh[m]='\0';
	sum=szz[0];
	for(i=0;fhh[i]!='=';i++)
	{
		if(fhh[i]=='+')
			sum+=szz[i+1];
		if(fhh[i]=='-')
			sum-=szz[i+1];
	}
	printf("%d",sum);
	return 0;
}

