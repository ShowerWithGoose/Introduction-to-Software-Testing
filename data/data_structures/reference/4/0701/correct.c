#include <stdio.h>
#include <string.h>
char a[100][500];
struct haha{
	char word[100];
	int time;
};
struct haha exp[100];
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	int i=0,j=0,p=0,q=0;
	while(fgets(a[i],1024,in)!=NULL)
	{
		i++;
	}
	int i0=i-1;
	for(i=0;i<=i0;i++)
	{
		for(j=0;j<=strlen(a[i])-1;j++)
		{
			if((a[i][j]>='A'&&a[i][j]<='Z')||(a[i][j]>='a'&&a[i][j]<='z'))
			{
				if(a[i][j]>='A'&&a[i][j]<='Z')
				{
					a[i][j]=a[i][j]+'a'-'A';
				}
				exp[p].word[q]=a[i][j];
				q++;
			}
			else
			{
				if(strlen(exp[p].word)!=0)
				{
				q=0;
				exp[p].time=1;
				p++;
			}
			}
		}
	}
	int p0=p-1;
	for(i=0;i<=p0-1;i++)
	{
		for(j=0;j<=p0-1-i;j++)
		{
			if(strcmp(exp[j].word,exp[j+1].word)>0)
			{
				char temp[100];
				strcpy(temp,exp[j].word);
				strcpy(exp[j].word,exp[j+1].word);
				strcpy(exp[j+1].word,temp);
			}
		}
	}
	for(i=0;i<=p0;i++)
	{
		if(strcmp(exp[i].word,exp[i+1].word)==0)
		{
			exp[i].time=exp[i].time+exp[i+1].time;
			for(j=i+1;j<=p0;j++)
			{
				exp[j].time=exp[j+1].time;
				strcpy(exp[j].word,exp[j+1].word);
			}
			i--;
			p0--;
		}
	}
	for(i=0;i<=p0;i++)
	{
		printf("%s %d\n",exp[i].word,exp[i].time);
	}
}



