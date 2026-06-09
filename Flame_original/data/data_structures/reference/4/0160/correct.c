#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct word{
	char wd[36];
	int n;
}dd[1024];
int N=0;
void insert(struct word dd[],char hh[]);
int get(FILE *fp,char hh[]);
int main(){
	FILE *fp;
	char hh[36];
	int str,i=0;
	fp=fopen("article.txt","r");
	if(fp==NULL){
		printf("ERROR!");
		return -1;
    }
	while(get(fp,hh)!=EOF){
		str=strlen(hh);
		for(i=0;i<str;i++){
			hh[i]=tolower(hh[i]);
		}
		insert(dd,hh);
	}
	for(i=0;i<N;i++){
		printf("%s %d\n",dd[i].wd,dd[i].n);
	}
	fclose(fp);
    return 0;
} 
 void insert(struct word dd[],char hh[]){
	int j=0,k=0;
	for(j=0;j<N;j++){
		if(strcmp(dd[j].wd,hh)<0)
		continue;
		else break;
	}
	if(j==N){
		strcpy(dd[j].wd,hh);
		dd[j].n=1;N++;
	}
	else if(strcmp(hh,dd[j].wd)==0){
		dd[j].n++;
	}
	else{
		for(k=N-1;k>=j;k--){
			strcpy(dd[k+1].wd,dd[k].wd);
			dd[k+1].n=dd[k].n;
		}
		strcpy(dd[j].wd,hh);
		dd[j].n=1;N++;
	}
}
int get(FILE *fp,char hh[]){
	char c;
	int t=0;
	while(!isalpha((c=fgetc(fp)))){
		if(c==EOF){
			return c;
		}
		else continue;
	}
	do{
		hh[t++]=c;
	}while(isalpha(c=fgetc(fp)));
	hh[t]='\0';
	return 1;
}

