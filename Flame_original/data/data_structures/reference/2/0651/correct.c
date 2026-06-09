#include<stdio.h>
#include<string.h>
#include<math.h>
int a[1000];
char s[1000],s1[1000];
int main()
{
	gets(s);
	int i,j=0,m,n=0,q=1,tot,h,k=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!=' ')
		{
			s1[j]=s[i];
			j=j+1;
		}
	}
	for(i=0;i<strlen(s1);i++)
	{
		if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='=')
		{
			m=i-n;
			while(m>0){
				a[q]=a[q]+(s1[n]-'0')*pow(10,m-1);
				m--;
				n++; 
			}
			n=n+1;
			q=q+1;
		}
		}
	for(i=0;i<strlen(s1);i++){
		if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='=')
		{
			k++;
			if(s1[i]=='*')
			{
				a[k]=a[k]*a[k+1];
				for(j=k;j<q;j++)
				{
					
					a[j+1]=a[j+2];
				}
				k--;q--;
			}
			if(s1[i]=='/')
			{
				a[k]=a[k]/a[k+1];
				for(j=k;j<q;j++)
				{
					
					a[j+1]=a[j+2];
				}
				k=k-1;q=q-1;
			}
		}
	}
	tot=a[1],k=1;
	for(i=0;i<strlen(s1);i++){
		if(s1[i]=='+')
		{
			k=k+1;
			tot=tot+a[k];
		}
		if(s1[i]=='-')
		{
			k=k+1;
			tot=tot-a[k];
		}
	}
    printf("%d",tot);
    return 0;
}

