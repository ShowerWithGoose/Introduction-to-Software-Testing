#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000],b[1000],f[1000],as[1000];
	int i,j,c,d,e[1000],g,h=0,k[100],l=0,m=0,n=0,o=0,p=1,q=0,r=0,s=0,qw,we,er,rt,ty=0,z[1000];
	gets(a);
	c=strlen(a);
	for(i=0,j=0;i<=c;i++)
	{
		if(a[i]!=' ')
		{
			b[j]=a[i];
			j++;
		}
	}
	//puts(b);
	if(b[0]=='-')
	g=0;
	else
	g=1;
	for(d=0;d<j;l=0)
	{
		if(b[d]<48||b[d]=='=')
		{
			if(b[d]=='+'||b[d]=='-')
			{
				as[s]=b[d];
				s++;
			}
			f[h]=b[d];
			d++;
			h++;	
		}
		else
		{
		//printf("%d\n",b[d]-'0');
			while(b[d]>=48&&b[d]!='=')
			{
				k[l]=b[d]-'0';
				l++;
				d++;
				p=p*10;
				//printf("%d\n",b[d-1]-'0');
			}
			for(n=0;n<l;n++,p=p/10)
			{
				o=o+k[n]*p;
			}
			e[m]=o/10;
			o=0;
			m++;
		}
	}

	//for(q=0;q<m;q++)
//	{
	//	printf("%c\n",as[q]);
//	}
	if(g==1)
	{
		for(qw=0,we=0;qw<h-1;qw++,we++)
		{
			if(f[qw]=='*'||f[qw]=='/')
			{
				rt=e[qw];
				for(er=0;f[qw+er]!='+'&&f[qw+er]!='-'&&f[qw+er]!='=';er++)
				{
					if(f[qw+er]=='*')
					{
					rt=rt*e[qw+er+1];
					}
					else
					{
					rt=rt/e[qw+er+1];
					}
				}
			//	printf("%d\n",er);
				z[we]=rt;
				qw=qw+er;
			//	printf("%d\n",z[we]);
			}
			else
			{
				z[we]=e[qw];
			//	printf("%d\n",z[we]);
			}
		}
	}
	//printf("%d%d\n",s,we);
	//for(rt=0;rt<s;rt++)
	//{
	//	printf("%d%c",z[rt],as[rt]);
	//}
	//printf("%d",z[rt]);
	
	ty=z[0];
	for(rt=0;rt<s;rt++)
	{
		if(as[rt]=='+')
		{
		//	printf("%d\n",ty);
			ty=ty+z[rt+1];
			//printf("%d\n",ty);
		}
		else
		{
			//printf("%d\n",ty);
			ty=ty-z[rt+1];
			//printf("%d\n",ty);
	}
	}
	printf("%d",ty);
	return 0;	
}

