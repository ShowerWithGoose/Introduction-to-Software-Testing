
#include <stdio.h>
#include <string.h>
int main()
{
	char all[200],ch[200];
	int num[200];
	int i=0,j=0,k=0,x=0,m=0,flag,sum=0;
	//¶ÁÈë¡¢²ð·Ö¡¢´¢´æ 
	gets(all);
	for(i=0;i<strlen(all);i++)
	{
		if(all[i]=='+'||all[i]=='-'||all[i]=='*'||all[i]=='/'||all[i]=='=')
		{
			ch[j]=all[i];
			j++; 
		}
		else if(all[i]>='0'&&all[i]<='9')
		{
			x=all[i]-'0';
			for(k=i;all[k+1]>='0'&&all[k+1]<='9';k++)
				x=x*10+all[k+1]-'0';
			i=k;
			num[m]=x;
			m++;
		}
	}
	//ÔËËã 
	
		for(i=0;i<j-1;i++)
		{
			if(ch[i]=='-')
				num[i+1]=-num[i+1];
	   
			if(ch[i]=='*')
			{
				num[i+1]=num[i]*num[i+1];
				num[i]=0;
			}
			
			if(ch[i]=='/')
		    {
			    num[i+1]=num[i]/num[i+1];
			    num[i]=0;
		    }
		}	
	
	    for(i=0;i<j;i++)
			sum+=num[i];	
		
		printf("%d",sum);
	return 0;
}

