#include<stdio.h>
#include<string.h>
#include<math.h>
int p;
int* t=&p;
int pp;
int* tt=&pp;
int r;
int* rr=&r;
int k=0;
int* kk=&k;
char dd[100];
int f(char s[])
{
	int x[100];
	*t=0;
	while(*(s+*t)>='0'&&*(s+*t)!='=')
	{
		x[*t]=*(s+*t)-48;
		*t = *t + 1 ;
	}
	int oo=0;
	for(int j=*t;j>=1;j--){
		oo+=pow(10,j-1)*x[*t-j];
	}
	return oo;
}
int bf(char s[])
{
	int x[100];
	*tt=0;
	while(*(s-*tt)>='0')
	{
		x[*tt]=s[-*tt]-48;
		*tt = *tt + 1;
	}
	int ooo=0;
	for(int j=0;j<*tt;j++){
		ooo+=pow(10,j)*x[j];
	}
	return ooo;
}
void ff(int u)
{
	if(u<=0)
	{
		*rr=0;
		dd[0]='0';
		*kk+=u;
		return ; 
	}
	*rr=-1;
	for(int i=0;i<100;i++)
	{
		if(u==0)
			break;
		dd[i]=u%10+48;
//		printf("%d\n",u);
		u/=10;	
		*rr = *rr + 1;	
	}
	char w;
//	printf("%d\n",*rr);
	for(int j=0;j<=*rr/2;j++){
		w=dd[j];
		dd[j]=dd[*rr-j];
		dd[*rr-j]=w;
	}
}
void h(char b[],int g,int h)
{
	char c[100];
	int co=0;
	for(int i=g;;i++)
	{
		if(b[i]==0) 
			break;
		c[i]=b[i];
		co++;
	}
	for(int i=h;;i++)
	{
		if(c[g+i-h]==0)
			break;
		b[i]=c[g+i-h];
	}
	if(g>h){
		for(int i=h+co;;i++)
		{
			if(b[i]==0)
				break;
			b[i]=0;
		}
	}
}
int main()
{
	char a[100],b[100]={0};
	gets(a);
	int n;
	int xx,yy;
	n=strlen(a);
	if(a[0]=='-'){
		h(a,1,0);
//		printf("%d",f(a));
		int ttt=f(a);
		*kk = *kk - 2*ttt;
		n=n-1;
	}	
	int s=0;
//	printf("%d\n",n);
	for(int i=0;i<n-1;i++){
		if(a[i]!=' '){
			b[s]=a[i];
			s++;
		}
	}
//	puts(b);
	for(int i=0;;i++){
		if(b[i]==0)
			break; 
		if(b[i]=='*'){
			xx=bf(b+i-1);
			yy=f(b+i+1);
			ff(xx*yy);
			h(b,i+p+1,i-pp+r+1);
//			puts(b);
//			printf("%d %d %d ",r,i+p+1,i-pp+r+1);
			for(int j=i-pp;j<=i-pp+r;j++)
			{
				b[j]=dd[j-i+pp];
			}
			i=i-pp+r;
//			puts(b);
		}
		else if(b[i]=='/'){
			xx=bf(b+i-1);
			yy=f(b+i+1);
			ff(xx/yy);
			h(b,i+p+1,i-pp+r+1);
			for(int j=i-pp;j<=i-pp+r;j++)
			{
				b[j]=dd[j-i+pp];
			}
			i=i-pp+r;
//			puts(b);
		}
	}
//	puts(b);
	for(int i=0;;i++){
		if(b[i]==0)
			break; 
		if(b[i]=='+'){
			xx=bf(b+i-1);
			yy=f(b+i+1);
//			printf("aaa %d aaa",xx+yy);
			ff(xx+yy);
//			printf("%d %d %d",xx,yy,r);
			h(b,i+p+1,i-pp+r+1);
//			printf("aaa");
//			puts(dd);
			for(int j=i-pp;j<=i-pp+r;j++)
			{
				b[j]=dd[j-i+pp];
			}
			i=i-pp+r;
//			puts(b);
		}
		else if(b[i]=='-'){
			xx=bf(b+i-1);
			yy=f(b+i+1);
			ff(xx-yy);
			h(b,i+p+1,i-pp+r+1);
//			puts(b);
			for(int j=i-pp;j<=i-pp+r;j++)
			{
				b[j]=dd[j-i+pp];
			}
			i=i-pp+r;
//			puts(b);
		}
    }
	*kk = *kk + f(b);
	printf("%d",k);
	return 0;
}



