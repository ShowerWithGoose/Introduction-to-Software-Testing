#include<stdio.h>
#include<ctype.h>
#include<string.h>

struct wordlist{
	char ci[500];
	int shu;
	
};
int n=0;
int getword(FILE *fp,char *p)
{
	char c;

	while(!isalpha(c=fgetc(fp)))
	{
		if(c==EOF) 
		return c;
		else continue;
	}
	do{
		*p=tolower(c);
		p++;
	}while(isalpha(c=fgetc(fp)));
	*p='\0';
//	printf("1");
	return 1;
}

void pailie(struct wordlist amm[],int n)
{
	struct wordlist change;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(amm[i].ci,amm[j].ci)>0)
			{
				change=amm[i];
				amm[i]=amm[j];
				amm[j]=change;
			}
		}
	}
}

int main()
{
	struct wordlist word[1000];
	FILE *in;
	char wo[500];
	int i=0,n=0,j,k,m;
	if((in=fopen("article.txt","r"))!=NULL)
	{
		
	while(getword(in,wo)!=EOF)
	{
		strcpy(word[n].ci,wo);
		word[n].shu=1;
		n++;
	}
	pailie(word,n);
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(word[i].ci,word[j].ci)==0){
				word[i].shu++;
				for(k=j;k<n;k++)
				
				word[k]=word[k+1];
				
				j--;
				n--;
				
			}
		}
	}
	m=n;
	for(i=0;i<m;i++)
	{
		printf("%s %d\n",word[i].ci,word[i].shu);
	}
}
}

