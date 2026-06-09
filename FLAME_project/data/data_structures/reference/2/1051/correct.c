#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int num[1000];
char sig[1000];
int main()
{
    int i=0,j=0;
	for(i=0;1;i++)
	{
		scanf("%d",&num[i]);
		scanf(" %c",&sig[i]); 
		if(sig[i]=='=')
		{
			j=i;
			break;
		}
	}
	if(j==0) printf("%d",num[0]);
	else
{	
    for(i=0;i<j-1;i++)
    {
        if(sig[i]=='+')
        {
            if(sig[i+1]=='+')
            {
                num[i+1]=num[i]+num[i+1];
            }
            else if(sig[i+1]=='-')
            {
                num[i+1]=num[i]+num[i+1];
            }
            else if(sig[i+1]=='*')
            {
                num[i+2]=num[i+1]*num[i+2];
                num[i+1]=num[i];
                sig[i+1]=sig[i];
            }
            else if(sig[i+1]=='/')
            {
                num[i+2]=num[i+1]/num[i+2];
                num[i+1]=num[i];
                sig[i+1]=sig[i];
            }
        }
        else if(sig[i]=='-')
        {
            if(sig[i+1]=='+')
            {
                num[i+1]=num[i]-num[i+1];
            }
            else if(sig[i+1]=='-')
            {
                num[i+1]=num[i]-num[i+1];
            }
            else if(sig[i+1]=='*')
            {
                num[i+2]=num[i+1]*num[i+2];
                num[i+1]=num[i];
                sig[i+1]=sig[i];
            }
            else if(sig[i+1]=='/')
            {
                num[i+2]=num[i+1]/num[i+2];
                num[i+1]=num[i];
                sig[i+1]=sig[i];
            }
        }
        else if(sig[i]=='*')
        {
            num[i+1]=num[i]*num[i+1];
        }
        else if(sig[i]=='/')
        {
            num[i+1]=num[i]/num[i+1];
        }
    }
    if(sig[j-1]=='+') printf("%d",num[j-1]+num[j]);
    else if(sig[j-1]=='-') printf("%d",num[j-1]-num[j]);
    else if(sig[j-1]=='*') printf("%d",num[j-1]*num[j]);
    else if(sig[j-1]=='/') printf("%d",num[j-1]/num[j]);
}
    return 0;
}

