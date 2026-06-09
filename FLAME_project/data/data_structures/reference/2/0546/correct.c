#include<stdio.h>
#include<math.h>
#include<string.h>
char s[30000],s1[20000],a1[20000],s2[20000];
int a[20000],b[30000];
int main()
{
	gets(s);
	int l=strlen(s),j;
	int k=0;
	j=0;
	for(int i=0;i<=l;i++)
	{
		if((s[i]!='+')&&(s[i]!='-')&&(s[i]!='*')&&(s[i]!='/')&&(s[i]!='='))
		{
			a1[k]=s[i];
			k++;
		}
		else 
		{
			s1[j]=s[i];
			a1[k]=' ';
			k++,j++;
		}
	}
	l=strlen(a1),j=0;
	for(int i=0;i<=l;i++)
	{
		if(a1[i]!=' ')
		j++;
		for(;a1[i]!=' ';)
		{
			a[j]=10*a[j]+(a1[i]-'0');
			i++;
		}
	}
	int kk=1,jj=1,ll=1;
	l=strlen(s1);
	for(int i=0;i<=l;i++)
	{
		if((s1[i]=='+'||s1[i]=='-'))
		{
			s2[ll]=s1[i];
			b[jj]=a[kk]; 
			jj++,kk++,ll++;
		}
		if(s1[i]=='*')
		{
			a[kk+1]=a[kk]*a[kk+1];
			kk++;
		}
		if(s1[i]=='/')
		{
			a[kk+1]=a[kk]/a[kk+1];
			kk++;
		}
	}
	b[jj]=a[kk];

int sum=b[1];
	kk=2;
	for(int i=1;i<=ll;i++)
	{
		if(s2[i]=='-')
		{
			sum=sum-b[kk];
			kk++;
		}
		if(s2[i]=='+')
		{
			sum=sum+b[kk];
			kk++;
		}
	}
	printf("%d",sum);
	return 0;
}


