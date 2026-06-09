#include<stdio.h>
#include<string.h>
#define maxline 100
char line[maxline];
struct list{
	char name[20];
	int sum;
	int del;
};
struct list word[100];
char qname[30][20];
int qsum[30];
void trans(char english[]){
	int len;
	int i;
	len=strlen(english);
	for(i=0;i<len;i++){
		if(english[i]>='A'&&english[i]<='Z'){
			english[i]=english[i]+'a'-'A';
		}
	}
}
void qsort(int n){
	int i,j;
	char a[20];
	int tmp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if((strcmp(qname[j],qname[j+1]))>0){
				strcpy(a,qname[j]);	
				strcpy(qname[j],qname[j+1]);	
				strcpy(qname[j+1],a);	
				
				tmp=qsum[j];
				qsum[j]=qsum[j+1];
				qsum[j+1]=tmp;
			}
		}
	}
}
	
int main(){
	int cnt;
	int i,j,len,k;
	FILE*in;
	in=fopen("article.txt","r");
	
	i=0,cnt=0;
	while((fgets(line,maxline-1,in))!=NULL){
		j=0;
		len=strlen(line);
		while(j<len){
			while(!(line[j]>='A'&&line[j]<='Z') && !(line[j]>='a'&&line[j]<='z')&&line[j]) 
				j++;
			for(k=0;((line[j]>='A'&&line[j]<='Z')||(line[j]>='a'&&line[j]<='z')) && line[j];j++,k++){
				word[i].name[k]=line[j];
			}
			word[i].name[k]='\0';
			word[i].sum=1;
			word[i].del=0;
			
			trans(word[i].name);
			for(k=0;k<i;k++){
				if((strcmp(word[i].name,word[k].name))==0){
						word[k].sum++;
						word[i].del=1;
						break;
				}
			}
			i++;
		}
		}
	
	cnt=i;
	j=0;
	for(i=0;i<cnt;i++){
		if(word[i].del!=1){
			strcpy(qname[j],word[i].name);
			qsum[j++]=word[i].sum;
		}
	}
	qsort(j);
	for(i=1;i<j;i++){
		printf("%s %d\n",qname[i],qsum[i]);
	}
	fclose(in);
	return 0;
}


