#include <stdio.h>
#include <string.h>
#include <ctype.h>
void f(int* p,int op,int k)
{
	if(op==1) *p=(*p) +k;
	else if(op==2) *p=(*p)-k;
}
int a[100][3];
int main()
{
	char s[2000];
	gets(s);
	int j=0;
	a[0][0]=1;
    for(int i=0;s[i]!='=';i++)
    {
    	if(!isblank(s[i]))
    	{
    		if(s[i]>='0'&&s[i]<='9')
    		{
    		a[j][1]=a[j][1]*10+s[i]-'0';
			}
		  else	if(s[i]=='+')
			{
				a[j][2]=1;
				a[++j][0]=1;
			}
			else if(s[i]=='-')
			{
				a[j][2]=2;
				a[++j][0]=2;
				
			}
			else if(s[i]=='*')
			{
				a[j][2]=3;
				a[++j][0]=3;
			}
			else if(s[i]=='/')
			{
				a[j][2]=4;
				a[++j][0]=4;
			}
			
		}
	}
	int sum=0;
	int op;
	for(int i=0;i<=j;i++)
	{
		if(a[i][0]==1&&a[i][2]<=2)
		sum+=a[i][1];
		else if(a[i][0]==2&&a[i][2]<=2)
		sum-=a[i][1];
	   else 
	   {
	   op=a[i][0];
	   int cnt=a[i][1];
	   while(a[i][2]>2)
	   {
	   	if(a[i+1][0]==3)
	   	cnt=cnt*a[++i][1];
	   	else if(a[i+1][0]==4)
	   	cnt=cnt/a[++i][1];
		   
	   }
	   if(op==1) sum+=cnt;
	   else sum-=cnt;
	   
	   }
	}
	printf("%d\n",sum);
	return 0;
}



