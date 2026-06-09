#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long ans[100][2];
void getsnum(char *,long long*);
int cmp(const void*,const void*);
int main()
{
	long long a[100][2],b[100][2];
	int i=0,cnta=0,cntb=0,j,cnt=0,id[100];
	char *p,str[200];
	i=0;
	gets(str);
	p=str;
	while(1)
	{   getsnum(p,&a[i][0]);
	    p=strchr(p,' ');
	    p++;
		getsnum(p,&a[i][1]);
		i++;
		p=strchr(p,' ');
		
		if(p==NULL)
        break;
		p++;
	}
	cnta=i;
	i=0;
	gets(str);
	p=str;
	while(1)
	{   getsnum(p,&b[i][0]);
	    p=strchr(p,' ');
	    p++;
		getsnum(p,&b[i][1]);
		i++;
		p=strchr(p,' ');
		if(p==NULL)
        break;
        p++;
	}
	cntb=i;
	for(i=0;i<cnta;i++)
	for(j=0;j<cntb;j++)
	{
		ans[cnt][0]=a[i][0]*b[j][0];
		ans[cnt][1]=a[i][1]+b[j][1];
		cnt++;
	}
	for(i=0;i<cnt-1;i++)
	for(j=i+1;j<cnt;j++)
	{
		if(ans[i][1]==ans[j][1])
		{
			ans[i][0]+=ans[j][0];
			ans[j][0]=ans[j][1]=0;
		}
	}
	for(i=0;i<cnt;i++)
	id[i]=i;
	qsort(id,cnt,sizeof(int),cmp);
	i=0;
	while(ans[id[i]][0]&&i<cnt)
	{printf("%lld %lld ",ans[id[i]][0],ans[id[i]][1]);
	i++;
	}
}
void getsnum(char *p,long long *x)
{
	char *q;
	int i;
	long long ans=0;
	if((q=strchr(p,' '))==NULL)
	q=strchr(p,'\0');
	for(i=0;i<q-p;i++)
	{
		ans*=10;
		ans+=*(p+i)-'0';
	}	
	*x=ans;
}
int cmp(const void*p,const void*q)
{
	int *pp,*qq;
	pp=(int*)p;
	qq=(int*)q;
	if(ans[*pp][1]>ans[*qq][1])
	return -1;
	else return 1;
}



