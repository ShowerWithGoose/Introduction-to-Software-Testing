#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char s[100],b[100];
	int a[100];
	int i=0,k=0,count,m=0,n=0,flag=0,num=0;
	int j=i;
    gets(s);
    //printf("%s",s);
	for(i=0;s[i]!='\0';i++)
	{
	    if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
	    {
	    	b[k]=s[i];
		    k++;
	    }
	    else if(s[i]>='0'&&s[i]<='9')
	    {
	    	n=s[i]-'0';
	    	for(j=i;s[j+1]>='0'&&s[j+1]<='9';j++)
			{
			    n=n*10+s[j+1]-'0';
			}
		    i=j;
			a[m]=n;
			m++;
		}
    }
    //printf("%s",b);
    //printf("%d",a[0]); 
    //需要考虑的情况有：只有乘除；只有=；加减乘除）
	if(k==1)//只有=的情况 
	printf("%d",a[1]); 
    else
	{
	    for(i=0;i<k-1;i++) 
        {
    	    if(b[i]=='+'||b[i]=='-')
    	    flag=1;
	    } 
	    if(flag==0)//只有乘除的情况 
	    {
		    for(i=0;i<k-1;i++)
		    {
			    if(b[i]=='*')
			    a[i+1]=a[i]*a[i+1];
			    if(b[i]=='/')
			    a[i+1]=a[i]/a[i+1];
		    }
		printf("%d",a[k-1]);
	    }
	    if(flag==1)//既有加减也有乘除 
	    {
	    	 for(i=0;i<k-1;i++)
		    {
			    if(b[i]=='-')
			    a[i+1]=-a[i+1];	
			    
		    }
		    for(i=0;i<k-1;i++)
		    {
			    if(b[i]=='*')
			    {
				    a[i+1]=a[i]*a[i+1];
			        a[i]=0;
			    }
			    if(b[i]=='/')
		       {
			        a[i+1]=a[i]/a[i+1];
			        a[i]=0;
		       }
		    }
		   
		    for(i=0;i<k;i++)
		   {
		        num+=a[i];	
		   }
		   printf("%d",num);
	    }
    }
	return 0;
}

