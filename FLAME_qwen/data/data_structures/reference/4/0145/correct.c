#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

struct words{
	char w[100];
	int num;
}words[100];

int main(){
	FILE *fp;
	fp=fopen("article.txt","r");
	
	int i=0,n,j=0,len,k=0,t=0;
	char s[100][100];
	while(fscanf(fp,"%s",s[i])!=EOF){
		k=0;
		len=strlen(s[i]);
		for(j=0;j<len;j++){
			if(isupper(s[i][j]))
			{
				words[t].w[k]=tolower(s[i][j]);
				k++;
			}
			else if(islower(s[i][j]))
			{
				words[t].w[k]=s[i][j];
				k++;
			}
			else if(!isalpha(s[i][j])&&isalpha(s[i][j+1])){
				words[t].w[k]='\0';
				t++;
				k=0;
			}
		}
		if(k!=0){
			words[t].w[k]='\0';
			t++;	
		}
		i++;
	}
	n=t;
	for(i=0;i<n;i++)
	words[i].num=1;
	
	char hold[100];
	for(i=0;i<n;i++)
	for(j=0;j<i;j++){
		if(strcmp(words[i].w,words[j].w)<0){
			strcpy(hold,words[i].w);
			strcpy(words[i].w,words[j].w);
			strcpy(words[j].w,hold);
		}
	}
	
	for(i=0;i<n;i++){
		if(strcmp(words[i].w,words[i+1].w)==0)
		{
			words[i+1].num=words[i].num+1;
		}
		else printf("%s %d\n",words[i].w,words[i].num);
	}
	
	return 0;
}



