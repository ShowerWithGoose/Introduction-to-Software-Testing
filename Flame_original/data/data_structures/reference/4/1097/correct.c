#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct w
{
	char s[20];
	int number;
}word;
int rank(const void*a,const void*b)
{
	word p=*(word*)a;
	word q=*(word*)b;
	int k=strcmp(p.s,q.s);
	if(k<0)return -1;
	else return 1;

}
char jojo[1024];
char dio[20];
word words[1000];
int main()
{
	int i=0,n=0,j=0;
	int t=0;
	FILE*IN;
int flag=0;
	IN=fopen("article.txt","r");
	while(fgets(jojo,1024,IN)!=NULL)
	{
		int k=strlen(jojo);
		t=0;
		while(t<k){
		
		j=0;
		while(isalpha(jojo[t]))
		{
			dio[j++]=jojo[t++];
		}
		dio[j]='\0';
		while(!isalpha(jojo[t]))t++;
		int len=strlen(dio);
		for(j=0;j<len;j++)
		{
			if(dio[j]>='A'&&dio[j]<='Z')dio[j]+='a'-'A';
		}
		for(i=0;i<n;i++)
		{flag=0;
			if(strcmp(dio,words[i].s)==0)
			{
				words[i].number++;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			n++;
			strcpy(words[i].s,dio);
			words[i].number=1;
		}
	}}
	qsort(words,n,sizeof(words[0]),rank);
for(i=0;i<n;i++)
{
	if(isalpha(words[i].s[0]))
	printf("%s %d\n",words[i].s,words[i].number);
}
fclose(IN);
return 0;}

	


