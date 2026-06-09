#include<stdio.h>
#include<string.h>
#define maxline 100
char line[maxline];
struct list{
	char name[20];
	int sum;
	int del;
};
struct list a[100];
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
	int i,rr;
	char a[20];
	int tmp;
	for(i=0;i<n-1;i++){
		for(rr=0;rr<n-i-1;rr++){
			if((strcmp(qname[rr],qname[rr+1]))>0){
				strcpy(a,qname[rr]);	
				strcpy(qname[rr],qname[rr+1]);	
				strcpy(qname[rr+1],a);	
				
				tmp=qsum[rr];
				qsum[rr]=qsum[rr+1];
				qsum[rr+1]=tmp;
			}
		}
	}
}
	
int main(){
	int sum;
	int i,rr,len,jk;
	FILE*in;
	in=fopen("article.txt","r");
	
	i=0,sum=0;
	while((fgets(line,maxline-1,in))!=NULL){
		rr=0;
		len=strlen(line);
		while(rr<len){
			while(!(line[rr]>='A'&&line[rr]<='Z') && !(line[rr]>='a'&&line[rr]<='z')&&line[rr]) 
				rr++;
			for(jk=0;((line[rr]>='A'&&line[rr]<='Z')||(line[rr]>='a'&&line[rr]<='z')) && line[rr];rr++,jk++){
				a[i].name[jk]=line[rr];
			}
			a[i].name[jk]='\0';
			a[i].sum=1;
			a[i].del=0;
			
			trans(a[i].name);
			for(jk=0;jk<i;jk++){
				if((strcmp(a[i].name,a[jk].name))==0){
						a[jk].sum++;
						a[i].del=1;
						break;
				}
			}
			i++;
		}
		}
	
	sum=i;
	rr=0;
	for(i=0;i<sum;i++){
		if(a[i].del!=1){
			strcpy(qname[rr],a[i].name);
			qsum[rr++]=a[i].sum;
		}
	}
	qsort(rr);
	for(i=1;i<rr;i++){
		printf("%s %d\n",qname[i],qsum[i]);
	}
	fclose(in);
	return 0;
}


