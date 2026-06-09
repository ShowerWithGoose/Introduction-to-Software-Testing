#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct words{
	char name[10000];
	int sum;
}word[10000],p;
int main()
{	
    char a[10000],b[10000],c;
	int i=0,j=0,m=0,n=0;
	FILE *fp1=fopen("article.txt","r");
	c=fgetc(fp1);
	while(c!=EOF)
	{
		a[i++]=c;
		c=fgetc(fp1);
	}
	for(i=0;i<strlen(a);i++)
	{
		if(isalpha(a[i])) 
		a[i]=tolower(a[i]);
	}
	for(i=0;i<strlen(a);i++)
	{
		if(isalpha(a[i]))
		{
			for(j=i;j<strlen(a);j++)
			{
				if(!isalpha(a[j]))
				{
					break;
				}
			}
			for(m=0;m<j-i;m++)
			{
				b[m]=a[i+m];
			}
			b[m]='\0';
			strcpy(word[n].name,b);
			n++;
			i=j;
		}
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(word[i].name,word[j].name)>0){
				p=word[i];
				word[i]=word[j];
				word[j]=p;
			}
		}
	} 
	for(i=0;i<n;i++) 
	word[i].sum=1;
	for(i=0;i<n;i++)
	{
		if(strcmp(word[i].name,word[i+1].name)==0)
		{
		    word[i+1].sum+=word[i].sum;
			word[i].sum=0;
		}
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(word[i].name,word[j].name)>0){
				p=word[i];
				word[i]=word[j];
				word[j]=p;
			}
		}
	} 
    for(i=0;i<n;i++)
	{
		if(word[i].sum!=0)
		{
			printf("%s %d\n",word[i].name,word[i].sum);
		}
	}
	return 0;
}

