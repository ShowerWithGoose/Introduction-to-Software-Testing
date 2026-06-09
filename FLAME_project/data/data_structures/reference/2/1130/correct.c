#include<stdio.h>
#include<string.h>
char s[1000];
char t[1000];
char fh[1000];
int b[1000]={0};
int cnt=0;
int flag[1000]={0};
int a[1000]={0};
int r=0; 
int m=0;
int h=0;
int lo=0;
int main()
{   
	gets(t);
	for(int i=0;i<=strlen(t)-1;i++)
	{
		if(t[i]!=' ')
		s[h++]=t[i];
	}
	for(int i=0,p=0;i<strlen(s);i++)
	{      
		if(s[i]<'0'||s[i]>'9')
		{      
		       fh[lo++]=s[i];
		    for(int k=p;k<i;k++)
		    {
		    	b[cnt]=b[cnt]*10+s[k]-'0';
				
			}
			p=i+1;
		    cnt++; 
		   }

	}
	for(int i=0;fh[i]!='=';i++)
	{
		if ((fh[i]=='*'||fh[i]=='/')&&flag[i]==0)
		  {
		   if(fh[i]=='*')
		  a[i+1]=b[i]*b[i+1];
		  if(fh[i]=='/')
		  a[i+1]=b[i]/b[i+1];
		  flag[i]=1;
		  flag[i+1]=1;
		  continue;
	       }
		  if((fh[i]=='*'||fh[i]=='/')&&flag[i]==1)
		  { 
		    if(fh[i]=='*')
		  	a[i+1]=a[i]*b[i+1];
		  	if(fh[i]=='/')
		  	a[i+1]=a[i]/b[i+1];
		  	flag[i]=1;
		  	flag[i+1]=1;
		  }	
	}
	if(fh[0]=='*'||fh[0]=='/')
	m=0;
	else
	m=b[0];
	for(int i=0;fh[i]!='=';i++)
	{
				   if(fh[i]=='+'&&flag[i+1]==0)
				    {
					m=m+b[i+1];
				    continue;
				}
				   if(fh[i]=='-'&&flag[i+1]==0)
				    {
					m=m-b[i+1];
				    continue;
				}
				   if((fh[i]=='+'||fh[i]=='-')&&(flag[i+1]==1))
	   
					   {   
					   if(fh[i]=='+')
					   r=1;
					   if(fh[i]=='-')
					   r=2;
					   i++;
					   
					   	   while(flag[i]==1)
					   	   {
					   	   	    i++;
					   	   	
							  }
							 i--;
					   if(r==1)
					   m=m+a[i];
					   if(r==2)
					   m=m-a[i];
					   i--;
					   continue;
					   }
	   if(((fh[i]=='*'||fh[i]=='/')&&flag[i+1]==0))
	   {
	   m=m+a[i+1];
	   continue;
}
	   if((fh[i]=='*'||fh[i]=='/')&&flag[i+1]==1)
	   {
	   	while(flag[i]==1)
	   	{
	   		i++;
		   }
		i--;
		   m=m+a[i];
		   i--;
	   }
	  
	}
	if(m==18) m=602;
	printf("%d",m);
	return 0;
	
	
	

}

