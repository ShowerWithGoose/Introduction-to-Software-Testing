#include<stdio.h>
#include<string.h>
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char exchange;
	char temp[100001],word[10001][101];
	memset(word,0,sizeof(word));
	int i,j,k,m,templen,maxlen;
	//int time[100001];
	//memset(time,0,sizeof(time));
	m=1;
	while(feof(in)==0)
	{
		memset(temp,0,sizeof(temp));
		fgets(temp+1,100000,in);
		templen=strlen(temp+1)-1;
		//printf("%d ",templen);
		//printf("%s\n",temp+1);
		for(i=1;i<=templen;i=i+1)
		{
			if('A'<=temp[i]&&temp[i]<='Z') 
			{
				temp[i]=temp[i]+32;
				//printf("%c",temp[i]);
			}
			
			else continue;
		}
		for(i=1;i<=templen;i=i+1)
		{
			if('a'<=temp[i]&&temp[i]<='z')
			{
				for(j=i;j<=templen;j=j+1)
				{
					if('a'>temp[j]||temp[j]>'z') break;
			    }
				for(k=1;k<=j-i;k=k+1)
				{
				    word[m][k]=temp[i+k-1];
				}
				word[m][j-i+1]='\0';
				m=m+1;	
			     i=j;
			}
		}
		
	}
	m=m-1;
	//printf("%s\n",word[1]+1);
	//printf("%d",m);
	/*for(i=1;i<=m;i=i+1)
	{
		printf("%s ",word[i]+1);
	}*/
	//printf("%d",strcmp("all","do"));
	for(i=2;i<=m-1;i=i+1)
	{
	    for(j=m;j>=i;j=j-1)
	    {
			if(strcmp(word[j]+1,word[j-1]+1)<0)
			{
				if(strlen(word[j]+1)>strlen(word[j-1]+1)) maxlen=strlen(word[j]+1);
				else maxlen=strlen(word[j-1]+1);
				for(k=1;k<=maxlen;k=k+1)
				{
					exchange=word[j][k];
					word[j][k]=word[j-1][k];
					word[j-1][k]=exchange;
				} 
			}
		}
	}
	//printf("%d",strcmp(word[3]+1,word[1]+1));
	/*for(i=1;i<=m;i=i+1)
	{
		printf("%s ",word[i]+1);
	}*/
	//printf("%d\n",strcmp(word[2]+1,word[3]+1));
	for(i=1;i<=m;i=i+1)
	{
		if(strcmp(word[i]+1,word[i+1]+1)==0)
		{
			for(j=i;j<=m;j=j+1)
			{
				if(strcmp(word[i]+1,word[j]+1)!=0) break;
			}
			printf("%s %d\n",word[i]+1,j-i);
			i=j-1;
		}
		else printf("%s 1\n",word[i]+1);
	}
	return 0;
}

