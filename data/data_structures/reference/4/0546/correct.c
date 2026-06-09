#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char s[1000],s1[1024][100];
struct node
{
	char word[100];
	int count;
};
void change(char ss[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(ss[i]>='A'&&ss[i]<='Z')
			ss[i]=ss[i]-'A'+'a';
	}
}
int main()
{
	struct node a[1020];
	int i=0,j=0;
	FILE *in;
	if(in=fopen("article.txt","r")==NULL)
	printf("Wrong Can't Open This File article.txt");
	in=fopen("article.txt","r");
	while((fgets(s,1023,in))!=NULL)
	{
		int k=0;
		int l=strlen(s);
		change(s,l);
		for(i=0;i<l;i++)
		if(!(s[i]>='a'&&s[i]<='z'))
		s[i]=' ';
		for(i=0;i<l;i++)
		{
			if(s[i]>='a'&&s[i]<='z')
				{
					s1[j][k]=s[i];
					k++;
				}
			else if(s[i]==' ')
			{
				k=0;
				j++;
				while(s[i]==' ')
				i++;
				i--;
			}
		}
	}	
	int k=0;
		for(i=0;i<=j;i++)
		{
			if((s1[i][0]>='a'&&s1[i][0]<='z'))
			{
				strcpy(a[k].word,s1[i]);
				a[k].count=1;
				k++;
			}
		}
		for(i=0;i<=k-1;i++)
		{
			for(j=i+1;j<=k-1;j++)
			{
				if(a[i].count==0)
				continue;
				if(strcmp(a[i].word,a[j].word)==0)
				{
					a[i].count++;
					a[j].count=0;
				}
			}
		}
		for(i=0;i<k;i++)
			for(j=i;j<k;j++)
			{
				struct node temp;
				if(strcmp(a[i].word,a[j].word)>0)
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
	for(i=0;i<k;i++)
	if(a[i].count!=0)
	printf("%s %d\n",a[i].word,a[i].count);
}


