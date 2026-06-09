#include<stdio.h>
#include<string.h>
int main()
{
	char zm[1000],ex[5000]="";int i,k=0;
	gets(zm);
	for(i=0;i<=strlen(zm)-1;i++)
	{
		if(zm[i]=='-'&&zm[i-1]<zm[i+1]&&((zm[i-1]>='0'&&zm[i+1]<='9')||(zm[i-1]>='a'&&zm[i+1]<='z')||(zm[i-1]>='A'&&zm[i+1]<='Z')))
		{
			while(ex[k-1]!=zm[i+1]-1)
			{
				ex[k]=ex[k-1]+1;k++;
			}
	    }
	    else if(zm[i]!='-')
	    {
		ex[k]=zm[i];
		k++;}
		else
		{
		ex[k]='-';
		k++;}	    
	}
	puts(ex);
 } 

