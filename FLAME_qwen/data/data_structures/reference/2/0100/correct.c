#include<stdio.h>
int main()
{
	int i=0,j=0,k=0,tmp=0,tmp1=0,tmp2=0;
	int s1[1000]={0},s2[1000]={0},s3[1000]={0};char ch=1;
	while(ch!='=')
	{
		ch=getchar();
		    while(ch==' ')
		    ch=getchar();
			s1[i++]=ch;
	}
	if(s1[i-1]=='=')
	i--;
	tmp=s1[0]-'0';
	while(s1[j+1]>='0'&&s1[j+1]<='9')
	{
			tmp=tmp*10+s1[j+1]-'0';
			j++;
	}
	j++;
	
	s2[k++]=tmp;
	while(j<i-1)
	{
		s2[k++]=s1[j++];
		tmp=s1[j]-'0';
		while(s1[j+1]>='0'&&s1[j+1]<='9'&&j<i)
		{
			tmp=tmp*10+s1[j+1]-'0';
			j++;
		}
		s2[k++]=tmp;
		j++;
	}
	i=1,j=0;
	tmp=s2[0];
	while(i<k)
	{
		if(s2[i]=='+'||s2[i]=='-')
		{
			s3[j++]=tmp;
			s3[j++]=s2[i];
			i+=2;
			tmp=s2[i-1];
		}	
		else if(s2[i]=='/')
		{
			tmp/=s2[i+1];
			i+=2;
		}
		else if(s2[i]=='*')
		{
			tmp*=s2[i+1];
			i+=2;
		}
	}
	s3[j++]=tmp;
	int ans=s3[0];
   for(i=1;i<j;i+=2)
   {
   	if(s3[i]=='-')
   	ans-=s3[i+1];
   	else
   	ans+=s3[i+1];
   }
	printf("%d",ans);
	return 0;
}

