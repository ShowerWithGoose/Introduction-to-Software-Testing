#include<stdio.h>
#include<string.h>
char num[105];
char jieguo[105];
int len;
int main()
{
	int i,j,x1,x2;
	int a1=0,a2=0;//a1代表小数点，a2代表首个非零数 
	int zhishu;
	scanf("%[^\n]",num);
	len=strlen(num);
	for(i=0;i<len;++i)
	{   if(a1&&a2)
	    break;
		if(num[i]=='.')
		{
		 x1=i;
		 a1=1;	
		}
		else if(num[i]!='0'&&!a2)
		{
			x2=i;
			a2=1;
		}
	 } 
	 if(x1>x2)
	 {
	 	zhishu=x1-x2-1;
     }
    else if(x1<x2)
     {
     	zhishu=x1-x2;
	 }
	 j=0;
	 for(i=x2;i<len;++i)
	 {
	 	if(num[i]=='.')
	 	continue;
	 	else if(i==x2)
	 	{
	 		if(num[i+1])
	 		{    jieguo[j++]=num[i];
				 jieguo[j++]='.'; 
			}
			else
			jieguo[j++]=num[i];
		 }
		 else
		 jieguo[j++]=num[i];
	 }
	 jieguo[j]='\0';
	 printf("%se%d",jieguo,zhishu);
	 return 0;
 } 

