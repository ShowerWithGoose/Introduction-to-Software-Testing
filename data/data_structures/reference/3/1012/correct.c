#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void reverse(char s[])
{
	int temp,i,j;
	for(i=0,j=strlen(s)-1;i<j;i++,j--)
	{
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
	}
}
void cg(int t1,char *t)
{
	int i=0;
	while(t1!=0)
	{
		t[i]=t1%10+'0';
		i++;
		t1=t1/10;
	}
	t[i]='\0';
	reverse(t);
}
int main()
{
	char a[2001],b[2001];
	scanf("%s",a);
	int i=0;
	int j=0;
	int k=2;
	while(a[i]!='.'&&a[i]!='\0')i++;
	if(i==1)
	{
		if(a[i-1]=='0')
		{
			j=0;
			i++;
			while(a[i]=='0')
			{
				j++;
				i++;
			}
			b[0]=a[i];
			b[1]='.';
			i=i+1;
			while(a[i]!='\0')
			{
				b[k]=a[i];
				k++;
				i++;
			}
			if(b[k-1]=='.')
			{
				b[k-1]='e';
				b[k]='-';
				int t1=j+1;
				char t[101];
				cg(t1,t);
				k++;
				strcat(b,t);
			}
			else 
			{
				b[k]='e';
				k++;
				b[k]='-';
				int t1=j+1;
				char t[101];
				cg(t1,t);
				k++;
				strcat(b,t);
			}
		}//大于0小于1的小数
		else if(a[i-1]>='1'&&a[i-1]<='9')
		{
			k=0;
			i=0;
			while(a[i]!='\0')b[k++]=a[i++];
			b[k++]='e';
			b[k]='0';
		} 
	}
	else
	{
		int t2=i;
		i=0;
		b[0]=a[i++];
		b[1]='.';
		while(a[i]!='\0')
		{
			if(i<t2)
			{
			b[k]=a[i];
			k++;
			j++;
			i++;
			}
			else if(i==t2)i++;
			else {
			b[k]=a[i];
			k++;
			i++;
			}
		}
		b[k]='e';
		char t[101];
		cg(j,t);
		strcat(b,t);
	}
	printf("%s",b);
	return 0;
}



