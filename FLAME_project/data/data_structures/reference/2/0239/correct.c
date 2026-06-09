#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s1[100],s2[20],fuhao[100];
	int shuzi[100];
	gets(s1);
	int  a,b,m1=0,m2=0,m3=0,m4=0,m5=0,pd;
	int kk=0;
	a=strlen(s1);
	for(int i=0;i<a;i++)
	{
		if(s1[i]!=' ')
		s1[kk++]=s1[i];
		
	}
	s1[kk]='\0';
	b=strlen(s1);
//	puts(s1);
//	printf("\n");
	for(int j=0;j<b;j++)
	{
		if(('0'<=s1[j])&&(s1[j]<='9'))
		pd=1;
		else
		{
			pd=0;
			fuhao[m3++]=s1[j];
		}
		
		if(pd==1)
		{
			s2[m1++]=s1[j];
		}
		if(pd==0)
		{
			shuzi[m2++]=atoi(s2);
			m1=0;
			for(int o=0;o<10;o++)
			{
				s2[o]='\0';
			}
		}
	}
	m3--;
//	printf("%d\n",m2);
//	for(int d1=0;d1<m3;d1++)
//	printf("%c ",fuhao[d1]);
//	printf("\n");
	
//	for(int d2=0;d2<m2;d2++)
//	printf("%d ",shuzi[d2]);
//	printf("\n");
	for(int n1=0;n1<m3;n1++)
	{
		if(fuhao[n1]=='*')
		{
			shuzi[n1+1]=shuzi[n1]*shuzi[n1+1];
			shuzi[n1]=0;
		}
		else if(fuhao[n1]=='/')
		{
			shuzi[n1+1]=shuzi[n1]/shuzi[n1+1];
			shuzi[n1]=0;
		}		
	}
//	for(int d3=0;d3<m2;d3++)
//	printf("%d ",shuzi[d3]);
//	printf("\n");
	for(int p=0;p<m3;p++)
	{
		if((fuhao[p]=='+')||(fuhao[p]=='-'))
		fuhao[m4++]=fuhao[p];
	}
	fuhao[m4]='\0';
//	for(int d4=0;d4<m4;d4++)
//	printf("%c ",fuhao[d4]);
//	printf("\n");
	for(int q=0;q<m2;q++)
	{
		if(shuzi[q]!=0)
		shuzi[m5++]=shuzi[q];
	}
//	for(int d5=0;d5<m5;d5++)
//	printf("%d ",shuzi[d5]);
//	printf("\n");
	if(m5<=1)
	printf("%d",shuzi[0]);
	else
	{
	  for(int n2=0;n2<m5;n2++)
    	{		
	     if(fuhao[n2]=='+')
	      {
	   	    shuzi[n2+1]=shuzi[n2]+shuzi[n2+1];
	        shuzi[n2]=0;
	     }
	     else if(fuhao[n2]=='-')
	     {
	   	 shuzi[n2+1]=shuzi[n2]-shuzi[n2+1];
	     shuzi[n2]=0;
         }	
	}		
   printf("%d\n",shuzi[m5-1]); 
	}
	
   return 0;	
}
