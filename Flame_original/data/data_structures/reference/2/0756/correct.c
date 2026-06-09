#include<stdio.h>
#include<string.h>
int main()
{
	char str[10000]="",x[10000]="",sign[10000]="",signl[10000]="";
	int i,j=0,k=0,m,n=0,n2=0,num=0,num2=0,arr[10000]={0},arrl[10000]={0},sum;
    gets(str);
    for(m=0;m<strlen(str);m++)
    {
    	if(str[m]>='0'&&str[m]<='9')
    	{
    		n=10*n+str[m]-'0';
		}
		arr[num]=n;
		if(str[m]=='+'||str[m]=='-'||str[m]=='*'||str[m]=='/')
		{
			sign[num++]=str[m];
			n=0;
		}
	}
	arrl[0]=arr[0];
	for(i=0;i<num;i++)
	{
		if(sign[i]=='*')
		{
			arrl[k]=arrl[k]*arr[i+1];
		}
		if(sign[i]=='/')
		{
			arrl[k]=arrl[k]/arr[i+1]; 
		}
		if(sign[i]=='-'||sign[i]=='+')
		{
			signl[k]=sign[i];
			k++;
			arrl[k]=arr[i+1];
		}
	}
	sum=arrl[0];
	for(i=0;i<k;i++)
	{
		if(signl[i]=='+')  sum=sum+arrl[i+1];
	    if(signl[i]=='-')   sum=sum-arrl[i+1];
	}
	printf("%d",sum);
	return 0;
}

