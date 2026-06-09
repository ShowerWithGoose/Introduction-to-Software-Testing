#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char a[100000];//字符 
int num[50000]={0};
int t[50000]={0};//乘除之后 
char pun[50000];
char pandm[50000];
int main()
{
	int i=1;	
    gets(a);
	int len=strlen(a);
	
	int j=1,k=1;
	
	for(i=0;i<len;i++)
	{		
		if(a[i]>='0'&&a[i]<='9')
		{
		    while(a[i]>='0'&&a[i]<='9')
		   {
			num[j]=10*num[j]+(a[i]-'0');
			if(a[i+1]>='0'&&a[i+1]<='9')
			{
				i++;
			} 	
		  	else
		  	{
		  	   break;	
			}
		   }
		    j++;
		}
		else if(a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'&&a[i]!='=')
		{
			continue;
		}
		else
		{
		   pun[k]=a[i];
		   k++;	
		} 
		

	}
	//去空格，分离数字num和符号pun 
	
	
	int l=1;
	int lenp,lennum;
	lenp=k-1;//几个符号 （包括等号） 
	lennum=j-1;//几个数字（应该相等的） 
	
	if(lenp==1)//不运算 
	{
		printf("%d",num[1]);
		return 0;
	}
	pun[0]='+';
	pun[lenp+1]='+';
	//把乘除都算完，新的数字序列t和只有加减号的字符序列 pandm
	for(i=j=1;i<=lenp;i++)
	{
		if(pun[i]=='*'||pun[i]=='/')
		{
			t[j]=num[i];
			while(pun[i+1]=='*'||pun[i+1]=='/')
			{
			    if(pun[i]=='*')
			    {
			 	  t[j]*=num[i+1];
			    }
				else
				{
					t[j]/=num[i+1];
				}
				i++;				
			}
			if(pun[i]=='*')
			t[j]*=num[i+1];
			else if(pun[i]=='/')
			{
				t[j]/=num[i+1];
			}
			j++;			
		}
		else
		{
			pandm[l]=pun[i];
			l++;
			if(pun[i-1]=='+'||pun[i-1]=='-')
			{
				t[j]=num[i];
			    j++;					
			}
			else
			{
				continue;
			}


		}
	}
	
	int lent,lenpam,ans;
	lent=j-1;
	lenpam=lent-1;
	ans=t[1];
	for(i=1;i<lent;i++)
	{
		if(pandm[i]=='+')
		{
			ans+=t[i+1];
		}
		else
		{
			ans-=t[i+1];
		}
	}	
	
	printf("%d",ans);
	
	
	
	
	return 0;
 } 

