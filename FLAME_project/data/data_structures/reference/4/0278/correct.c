#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct words{
	char a[105];
	int ci;
}word[1005],swap;
int i,j,t;
char ch,wo[105];
int qing(char els[])
{
	int p,q=strlen(els);
	for(p=0;p<q;p++)
	els[p]='\0';
	return 0;
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	while(fscanf(in,"%c",&ch)!=EOF){
		if(isalpha(ch)){
			wo[i]=tolower(ch);
			i++;
		}
		else{
			int flag=0;
			i=0;
			if(wo[0]!='\0'){
				for(t=0;t<j;t++)
				if(strcmp(wo,word[t].a)==0){
					flag=1;
					word[t].ci++;
					break;
				}
				if(flag==0){
					strcpy(word[j].a,wo);
					word[j].ci=1;
					j++;
				}
			}
			qing(wo);
		}
	}
	for(i=0;i<j-1;i++){
		int flag=0;
		for(t=0;t<j-i-1;t++){
		if(strcmp(word[t].a,word[t+1].a)>0){
		swap=word[t];
		word[t]=word[t+1];
		word[t+1]=swap;
		flag=1;
		}
	}
	if(flag==0)
	break;
	}
	for(i=0;i<j;i++)
	printf("%s %d\n",word[i].a,word[i].ci);
	return 0;
}



