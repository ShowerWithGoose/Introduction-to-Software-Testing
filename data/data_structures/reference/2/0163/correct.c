#include <stdio.h>
#include <string.h>
void squeez(char s[],char c)
{
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
	if(s[i]!=c) s[j++]=s[i];
	s[j]='\0';
}
int main()
{
	char s[1000],t[1000],c=' ',s1[1000],s2[1000];
	int num[1000],num1[1000],i,k=0,j=0,p,e=0,b,f,q,h=0,sum;
	gets(s);
	squeez(s,c);
	
	for(i=0;i<=strlen(s)-2;i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') 
		{
		    s1[k]=s[i];
		    k++;
		}
		else
		{
		    p=0;
		    while(s[i]<='9'&&s[i]>='0')
		    {
			    p=p*10+s[i]-'0';
			    i++;
		    }
		    num[j]=p;
		    i--;
		    j++;
	    }
	}
	for(q=0;q<=k-1;q++)
	{
		if(s1[q]=='+') s2[e++]='+';
		if(s1[q]=='-') s2[e++]='-';
	}
	if(k==0)
	{
		printf("%d",num[0]);
		return 0;
	}
	else{
	    if(s1[0]=='+'||s1[0]=='-') num1[0]=num[0];
	    if(s1[k-1]=='+'||s1[k-1]=='-') num1[e]=num[j-1];
	    for(i=0;i<=j-2;i++)
	    {
		    if(s1[i]=='+'||s1[i]=='-')
		    {
			    num1[h++]=num[i];
		    }
		    else
		    {
			    num1[h]=num[i];
			    while(s1[i]=='*'||s1[i]=='/')
			    {
				    if(i==k) break;
				    if(s1[i]=='*') num1[h]=num1[h]*num[++i];
				    if(s1[i]=='/') num1[h]=num1[h]/num[++i];
			    }
			    h++;
		    }
	    }
    }
	sum=num1[0];
	for(i=0;i<=e-1;i++)
	{
		if(s2[i]=='+') sum=sum+num1[i+1];
		if(s2[i]=='-') sum=sum-num1[i+1];
	}
	printf("%d",sum);
	return 0;
}

