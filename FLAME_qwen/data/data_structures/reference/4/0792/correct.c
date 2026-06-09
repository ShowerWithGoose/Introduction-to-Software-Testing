#include<stdio.h>
#include<string.h>
struct LINE 
{
	char words[20];
	int time;
	int flag;
};
int main()
{
	struct LINE word[500];
	char cnt[20]={0};
	int i,j,n1=0,n2=1,n=0;
	char hold[20];
	char sentence[114514];
	char c;
	FILE *p1=fopen("article.txt","r");
	while((c=fgetc(p1))!=EOF)
	{
		sentence[n++]=c; 
	}
	for(i=0;i<=n-1;i++)
	{
		if((sentence[i]<'A'&&sentence[i]!=' ')||(sentence[i]>'Z'&&sentence[i]<'a')) 
		sentence[i]=' ';
	}
	for(i=0;sentence[i]!='\0';i++)
	{
		if(sentence[i]>='a'&&sentence[i]<='z')
		{
		    word[n2].words[n1]=sentence[i];
		    n1++;
	    }
	    else if(sentence[i]>='A'&&sentence[i]<='Z')
	    {
	    	word[n2].words[n1]=sentence[i]+32;
	    	n1++;
	 }
	    else if(sentence[i]==' ')
		{
	        n1=0;
	        n2++;
		}
	}
    for(i=1;i<=n2-1;i++)
    {
    	for(j=1;j<=n2-1-i;j++)
    	{
    		if(strcmp(word[j].words,word[j+1].words)>0)
			{
				strcpy(hold,word[j].words);
				strcpy(word[j].words,word[j+1].words);
				strcpy(word[j+1].words,hold);
			}
		}
	}
	for(i=1;i<=n2-1;i++)
	{
		for(j=i+1;j<=n2-1;j++)
		{
			if(word[i].flag==0)
			{ 
			if(strcmp(word[i].words,word[j].words)==0&&word[j].flag==0)
			{
				word[i].time++;
				word[j].flag=1;
			}
		    }
		}
	} 
	for(i=1;i<=n2-1;i++)
	{
		if(word[i].flag==0&&strcmp(word[i].words,cnt)!=0)
		{
			printf("%s %d\n",word[i].words,word[i].time+1);
		}
	}
}

