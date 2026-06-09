#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000],ch[1000]={'\0'};
	int sh[1000]={0},th[1000]={0};
	gets(s);
    int i,j,sum=0,len=0,lenn=0;
    s[strlen(s)-1]='\0';
    for(i=0,j=0;i<strlen(s);i++)
    {
    	if(s[i]!=' ')
    	  {
    	  	ch[j]=s[i];
    	  	j++;
		  }	  
	}
	
	for(i=0,j=0;i<strlen(ch);i++)
    {
    	if(ch[i]>='0'&&ch[i]<='9')
    	  {
    	  	sh[j]=ch[i]-'0';
    	  	for(;ch[i+1]>='0'&&ch[i+1]<='9';i++)
    	  	{
    	  		sh[j]=sh[j]*10+ch[i+1]-'0';
			  }
    	  	len++;  
    	  	j++;
		  }
		 
		 else
		   {
		   	sh[j]=ch[i];
		   	len++;
		   	j++;
		   }	  
	}	
	//9+4*5/7/6-12=
	for(i=0,j=0;i<len;i++)
    {
    	if(sh[i+1]=='*')
    	  {
    	  	sh[i+2]=sh[i]*sh[i+2];
    	  	i++;
		  }	
		else if(sh[i+1]=='/')
    	  {
    	  	if(sh[i]<sh[i+2])
    	  	  sh[i+2]=0;
    	  	else
    	  	  sh[i+2]=sh[i]/sh[i+2];
    	  	i++;
		  }
		else
		  {
		  	th[j]=sh[i];
		  	j++;
		  	lenn++;
		  }	  
	}
	sum=th[0];
	for(i=0;i<lenn;i++)
    {
    	if(th[i+1]=='+')
    	  {
    	  	sum=sum+th[i+2];
    	  	i++;
		  }	
		else if(th[i+1]=='-')
    	  {
    	  	sum=sum-th[i+2];
    	  	i++;
		  }
	}
	printf("%d",sum);
	return 0;
}



