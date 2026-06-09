#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
	int i=0,j=0,num[200];
	char a[200][200];
	FILE *fp;
	fp=fopen("article.txt","r");
	
	char ch,temp[200];
	ch=fgetc(fp);
	while(ch!=EOF){
		if(isalpha(ch)){
			a[i][j]=ch;
			j++;
		}
		else{
			a[i][j]='\0';
			i++;
			j=0;
		}
		ch=fgetc(fp);
	}
	for(int j=0;j<i;j++){
		for(int k=0;k<strlen(a[j]);k++){
			a[j][k]=tolower(a[j][k]);
		}
	}
	for(int j=0;j<i;j++){
		for(int k=j+1;k<i;k++){
			if(strcmp(a[j],a[k])>0){
				strcpy(temp,a[j]);
				strcpy(a[j],a[k]);
				strcpy(a[k],temp);
			}
		}
	}
	for(int j=0;j<200;j++){
		num[j]=1;
	}
	for(int j=0;j<i;j++){
		for(int k=j+1;k<i;k++){
			if(strcmp(a[j],a[k])==0&&a[j][0]!='\0'){
				num[j]++;
				a[k][0]='\0';
			}
		}
	}
	for(int j=0;j<i;j++){
		if(a[j][0]!='\0'){
			printf("%s %d\n",a[j],num[j]);
		}
	}
	fclose(fp);
	return 0;
}



