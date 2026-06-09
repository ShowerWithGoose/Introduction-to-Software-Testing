#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char sec[1000],secsp[1000];
	int i,j,k;
	int ans=0;

	gets(secsp);
	for(i=0,j=0;i<strlen(secsp);i++)
	{
		if(isspace(secsp[i]))
		{
			continue;
		}
		else
		{
			sec[j]=secsp[i];
			j++;
		}
	}//ÊäÈë£¬È¥¿Õ¸ñ 
	
	int temp,num[100]={0};
	int fh[100]={0};
	for(i=0,j=0,k=0;i<strlen(sec);i++)
	{
		if(isdigit(sec[i]))
		{
			num[j]=num[j]*10+sec[i]-'0';
		}
		else
		{
		   if(sec[i]=='+') 
		   {
		   	  fh[k]=1;
		   	  k++;
		   	  j++;
		   	  continue;
		   }
		   else if(sec[i]=='-') 
		   {
		   	  fh[k]=-1;
		   	  k++;
		   	  j++;
		   	  continue;
		   }
		   else if(sec[i]=='*')
		   {
		   	i++;
		   	for(temp=0;i>=0;i++)
			{
				if(isdigit(sec[i]))
					temp=temp*10+sec[i]-'0';
				else
					{
					    i--;
					    break;
					}
			}
			num[j]*=temp;	
		   }
		   else if(sec[i]=='/')
		   {
		   	i++;
		   	for(temp=0;i>=0;i++)
			{
				if(isdigit(sec[i]))
					temp=temp*10+sec[i]-'0';
				else
					{
					    i--;
					    break;
					}
			}
			num[j]/=temp;	
		   }
		}
	}

ans=num[0];	
for(i=1;i<=j+1;i++)
	{
       ans+=fh[i-1]*num[i];
	}
	
printf("%d",ans);
	return 0;
}






