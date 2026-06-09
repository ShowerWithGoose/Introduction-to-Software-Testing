#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	char str[200][30];
	FILE *in;
	in=fopen("article.txt","r");
	int i=0,j=0;
	int m;
	char c;
	while((c=fgetc(in))!=-1)
	{
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{
			str[i][j]=c;
			j++;
		}
		else{
			str[i][j]='\0';
			i++;
			j=0;
        }
	}
	m=i;
	for(i=0;i<m;i++)
	{
		for(j=0;j<strlen(str[i]);j++)
		{
			str[i][j]=tolower(str[i][j]);
		}
	}
		
	char temp[30];
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(strcmp(str[i],str[j])>0)
			{
				strcpy(temp,str[j]);
				strcpy(str[j],str[i]);
				strcpy(str[i],temp); 
			}
		}
	}
	int count[100];
	for(i=0;i<m;i++)
	{
		count[i]=1;
		for(j=i+1;j<m;j++)
		{
		    if(str[j][0]=='\0')
			{	
			continue;
		    }
			else if(strcmp(str[i],str[j])==0)
			{
				count[i]++;
				str[j][0]='\0';
			}
			
			else{
				i=j-1;
				break;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		if((str[i][0]>='a'&&str[i][0]<='z')||(str[i][0]>='A'&&str[i][0]<='Z'))
		printf("%s %d\n",str[i],count[i]);
	}
	fclose(in);
	return 0;
} 

