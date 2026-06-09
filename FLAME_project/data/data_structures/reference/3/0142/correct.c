#include<stdio.h>

int main()
{
	char shu[100],shu0[100],shu1[100];
	int i,i0=0,j=0,k=0,k0;
	gets(shu);
	if(shu[0]=='0')
	{
		for(i=2,j=2;shu[i]=='0';i++)
		j++;
		for(i;shu[i]!='\0';i++)
		{
			shu0[i0]=shu[i];
			i0++;
		}
		shu0[i0]='\0';
		j=1-j;
	}
	else if(shu[0]!='0')
	{
		for(i=0,j=0;shu[i]!='.';i++)
		j++;
		for(i=0;shu[i]!='\0';i++)
		{
			if(i<j) 
			shu0[i0]=shu[i];
			else 
			shu0[i0]=shu[i+1];
			i0++;
		}
		shu0[i0]='\0';
		j=j-1;
	}
	for(i0=0;shu0[i0]!='\0';i0++)
	{
		if(i0==0) shu1[k]=shu0[i0];
		else if(i0==1) shu1[k]='.';
		else shu1[k]=shu0[i0-1];
		k++;
	}
	if(i0>1){ 
	shu1[k]=shu0[i0-1];
	k0=k;} 
	else
	k0=k-1; 
	for(k=0;k<=k0;k++)
	printf("%c",shu1[k]);
	printf("e"); 
	printf("%d",j);
}



