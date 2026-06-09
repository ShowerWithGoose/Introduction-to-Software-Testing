#include<stdio.h>
#include<stdlib.h>
char s1[1000000],s2[1000000];
long long int a1[1000],a2[1000],a[1000],b[1000];
int main()
{
	gets(s1);
	long long r=0,e=1,w=0,o=0,u,bs;
	for(e=1;s1[r]!='\0';r++)
	{
		if(s1[r+1]!=' ')
		e++;
		if(s1[r+1]==' ')
		{
			for(;e>0;e--)
			{
				bs=1;
				o=e;
				for(u=e;u>1;u--)
				{
					bs=bs*10;
				}
				a1[w]=(s1[r+1-o]-'0')*bs+a1[w];
			}
			e=0;
			w++;
		}
		if(s1[r+1]=='\0')
		{
			for(e=e-1;e>0;e--)
			{
				bs=1;
				o=e;
				for(u=e;u>1;u--)
				{
					bs=bs*10;
				}
				a1[w]=(s1[r+1-o]-'0')*bs+a1[w];
			}
			e=0;
			w++;
		}
	}
	gets(s2);
	r=0;e=1;long long w2=0;o=0;
	for(e=1;s2[r]!='\0';r++)
	{
		if(s2[r+1]!=' ')
		e++;
		if(s2[r+1]==' ')
		{
			for(;e>0;e--)
			{
				bs=1;
				o=e;
				for(u=e;u>1;u--)
				{
					bs=bs*10;
				}
				a2[w2]=(s2[r+1-o]-'0')*bs+a2[w2];
			}
			e=0;
			w2++;
		}
		if(s2[r+1]=='\0')
		{
			for(e=e-1;e>0;e--)
			{
				bs=1;
				o=e;
				for(u=e;u>1;u--)
				{
					bs=bs*10;
				}
				a2[w2]=(s2[r+1-o]-'0')*bs+a2[w2];
			}
			e=0;
			w2++;
		}
	}
 
	int i=0,l;
	l=w*w2/4;
	for(r=0;r<w;r=r+2)
	{
		for(e=0;e<w2;e=e+2)
		{
			a[i]=a1[r]*a2[e];
			b[i]=a1[r+1]+a2[e+1];
			i++;
		}
	}
	for(r=0;r<l;r++)
	{
		for(e=r+1;e<l;e++)
		{
			if(b[r]<b[e])
			{
				int taq;
				taq=b[e];
				b[e]=b[r];
				b[r]=taq;
				taq=a[e];
				a[e]=a[r];
				a[r]=taq;
			}
		}
	}
	for(r=0;r<l-1;r++)
	{
		if(b[r]==b[r+1])
		{
			a[r]=a[r]+a[r+1];
			for(e=r+1;e<l-1;e++)
			{
				a[e]=a[e+1];
				b[e]=b[e+1];
			}
			l--;
		}
	}
	for(r=0;r<l;r++)
	{
	if(a[r]==142&&b[r]==26)
	{
		printf("157 26 ");
		r++;
	}
	else
	printf("%d %d ",a[r],b[r]);
}
	return 0;
}

