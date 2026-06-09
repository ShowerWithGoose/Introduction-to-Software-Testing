#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct word{
	char c[100];
}w[1000];
struct list{
	char d[100];
	int t;
}sta[1000];
int cmp(const void*a,const void *b){
	struct word*aa=(struct word*)a;
	struct word*bb=(struct word*)b;
	if(strcmp(aa->c,bb->c)>0) return 1;
	return -1;
};
int main(){
	FILE *in;
	char line[1000]={};
	in=fopen("article.txt","r");
	int n=0,i,j=0,m=0;
	while(fgets(line,1000,in)!=NULL){
		m=0;
		for(i=0;line[i];i++){
			if(line[i]>='a'&&line[i]<='z'){
				w[n].c[m]=line[i];
				m++;
				i++;
				if(!((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z'))){
					w[n].c[m]='\0';
					n++;
					m=0;
				}
				i--;
			}
			else if(line[i]>='A'&&line[i]<='Z'){
				w[n].c[m]=line[i]-'A'+'a';
				m++;
				i++;
				if(!((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z'))){
					w[n].c[m]='\0';
					n++;
					m=0;
				}
				i--;
			}
		}
	}
	qsort(w,n,sizeof(w[0]),cmp);
	strcpy(sta[0].d,w[0].c);
	sta[0].t=1;
	for(i=1;i<n;i++){
		if(strcmp(w[i].c,w[i-1].c)==0){
			sta[j].t++;
		}
		else{
			j++;
			strcpy(sta[j].d,w[i].c);
			sta[j].t=1;
		}
	}
	for(i=0;i<=j;i++){
		printf("%s %d\n",sta[i].d,sta[i].t);
	}
	fclose(in);
	return 0;
}

