#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000],c[1000],d[100]; 
	gets(a);
	int b[1000],e[1000];
	int i,j,k,l,m,o,panduan,record,mark,put;
	for(i=0,j=0,k=0,record=0;a[i]!='\0';i++)
	{
		if(a[i]!=' '){
			if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='=')
			{
				c[j++]=a[i];//¼ÇÂ¼·ûºÅ 
				b[k++]=record;//¼ÇÂ¼Êý×Ö 
				record=0;
			}else{
				record=record*10+(a[i]-'0');
				//printf("%d\n",record);
			}
		}
	}c[j]='\0';b[k]='\0';
	/*for(i=0;i<k;i++)
	{
		printf("%d %c ",b[i],c[i]);
	 }*/ 
	for(record=b[0],l=1,m=0,o=0;c[m]!='\0';)
	{
		if(c[m]=='+'||c[m]=='-'||c[m]=='=')
		{
			e[o]=record;//printf("%d\n",e[o]);
			d[o]=c[m],m++,o++;record=b[l],l++;
		}else if(c[m]=='*')
		{
			record*=b[l];l++,m++;
		}else if(c[m]=='/')
		{
			record/=b[l];l++,m++;
		}
	}
	for(i=0;i<o;i++)
	{
		if(i==0)
		{
			put=e[i];
		}else{
			if(d[i-1]=='+')
			{
				put+=e[i];
			//	printf("%d\n",put);
			}else if(d[i-1]=='-')
			{
				put-=e[i];
			//	printf("%d\n",put);
			}
		}
	}
	printf("%d",put);
	return 0;
}

