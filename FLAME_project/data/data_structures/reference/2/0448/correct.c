#include<stdio.h>
int main()
{
	char a[50];
	char fh[50];
	int b[50]={0},bj[50];
	int i,j,k,z,jh,jjh,ch,cch;
	int r;
	jh=jjh=ch=cch=0;
	gets(a);
	for(i=j=0;i<strlen(a);i++)
	{
		if(a[i]!=' ')
		{
			a[j]=a[i];
			j++;
		}
		else
		{
			a[j]=a[i+1];
		}
	}
	a[j+1]='=';
	for(i=j=0;a[i]!='=';i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[j]=b[j]*10+a[i]-'0';
		}
		else 
		{
			fh[j]=a[i];
			j++;
		}	
	}
	for(i=0;i<=j;i++)
	{
		if(fh[i]=='+')
		{
			jh++;
		}
		else if(fh[i]=='-')
		{
			jjh++;
		}
		else if(fh[i]=='*')
		{
			ch++;
		}
		else if(fh[i]=='/')
		{
			cch++;
		}
	}
	if(ch==0&&cch==0)
	{
		if(jh!=0||jjh!=0)
		{
			for(i=0;i<j;i++)
			{
				if(fh[i]=='+')
				{
					b[i+1]=b[i]+b[i+1];
				}
				else 
				{
					b[i+1]=b[i]-b[i+1];
				}
			}
		printf("%d",b[i]);
		}
		else
		printf("%d",b[0]);
	}
	else if(jh==0&&jjh==0)
	{
		for(i=0;i<j;i++)
		{
			if(fh[i]=='*')
			{
				b[i+1]=b[i]*b[i+1];
			}
			else 
			{
				b[i+1]=b[i]/b[i+1];
			}
		}
		printf("%d",b[i]);
	}
	else
	{
		k=0;
		for(i=0;i<j&&(ch!=0||cch!=0);i++)
		{
			if(fh[i]=='*')
			{
				b[i+1]=b[i]*b[i+1];
				ch--;
				bj[k]=i;
				k++;
			}
			else if(fh[i]=='/')
			{
				b[i+1]=b[i]/b[i+1];
				cch--;
				bj[k]=i;
				k++;
			}
		}
		for(i=0;i<j&&(jh!=0||jjh!=0);i++)
		{
			if(fh[i]=='+')
			{
				for(z=0,r=1;z<k;z++)
				{
					if(bj[z]==i+r)
					{
						r++;
					}
				}
				b[i+r]=b[i]+b[i+r];
			}
			if(fh[i]=='-')
			{
				for(z=0,r=1;z<k;z++)
				{
					if(bj[z]==i+r)
					{
						r++;
					}
				}
				b[i+r]=b[i]-b[i+r];
			}
		}
		printf("%d",b[j]);
	}
	return 0;
}



