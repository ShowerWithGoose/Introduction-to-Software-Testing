#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char word[100][50]={0};
int times[100]={0};
char language[100][200]={0};
int del[100]={0};
char copy[50]={0};
int main()
{
	int i=0,j=0,k=0,hold,num=0,flag=0;
	FILE *fp1;
	fp1=fopen("article.txt","r");
	for(i=0;i<100;i++)
	{
		times[i]=0;
		del[i]=0;
	}
	while(!feof(fp1))
	{
		fgets(language[num],200,fp1);
		num++;
	}
	fclose(fp1);
	for(int l=0;l<num;l++)
	{
		for(i=0;i<strlen(language[l]);i++)
		{
			if(language[l][i]>='A'&&language[l][i]<='Z')
			{
				word[j][k]=language[l][i]-'A'+'a';
				k++;
			}
			if(language[l][i]>='a'&&language[l][i]<='z')
			{
				word[j][k]=language[l][i];
				k++;
			}
			if(i<=strlen(language[l])-2)
			{
				if((isalpha(language[l][i])!=0)&&(isalpha(language[l][i+1])==0))
				{
					times[j]++;
				    j++;
				    k=0;
				}
			}
		}
	}
	for(i=0;i<j-1;i++)
	{
		flag=0;
		for(k=0;k<j-i-1;k++)
		{
			if(strcmp(word[k],word[k+1])>0)
			{
				strcpy(copy,word[k]);
				strcpy(word[k],word[k+1]);
				strcpy(word[k+1],copy);
				hold=times[k];
				times[k]=times[k+1];
				times[k+1]=hold;
				flag=1;
			}
		}
		if(0==flag)
		    break;
	}
	for(i=0;i<j;i++)
	{
		for(k=i;k<j-1;k++)
		{
			if(strcmp(word[k],word[k+1])==0)
		    {
				times[i]++;
				del[k+1]=1;
		    }
		    else
		    break;
		}
	}
	for(i=0;i<j;i++)
	{
		if(del[i]==0)
		{
			printf("%s",word[i]);
			printf(" ");
			printf("%d\n",times[i]);
		}
	}
	return 0;
}


