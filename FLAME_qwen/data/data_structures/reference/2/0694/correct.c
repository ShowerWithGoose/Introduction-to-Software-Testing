#include<stdio.h>
#include<string.h>
char str[1000],str1[1000];
int number[1000],location[1000],addup[1000],fuhao[1000];
int main()
{
	gets(str);
	int i,j,k=0,num=0;
	for(i=0,j=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
		{
			str1[j]=str[i];
			j++;
			if(str[i]<'0'||str[i]>'9')
				location[++k]=j;	
		}
	}	
	for(int l=0;l<=k-1;l++)
	{
		int o=1,p=location[l+1]-1;
		for(int n=1;n<=(location[l+1]-location[l]-1);n++)
		{
			num+=o*(str1[p-1]-'0');
			o*=10,p--;
		}
		number[l]=num;
		num=0;
	}
	int x=0,y=0;
	if(str1[0]=='-')
		addup[x]=0-number[0];
	else
		addup[x]=number[0];
	for(int s=0;s<k;s++)
	{ 
		if(str1[location[s+1]-1]=='*')
			addup[x]*=number[s+1];
		else if(str1[location[s+1]-1]=='/')
			addup[x]/=number[s+1];
		else if(str1[location[s+1]-1]=='+')
		{
			x++;
			addup[x]=number[s+1];
			fuhao[y]=1;
			y++;
		}
		else if(str1[location[s+1]-1]=='-')
		{
			x++;
			addup[x]=number[s+1];
			y++;
		}
	}
	int total=addup[0];
	for(int c=0;c<=y;c++)
	{
		if(fuhao[c]==1)
			total+=addup[c+1];
		else
			total-=addup[c+1];
	}
	printf("%d",total);
	
 } 

