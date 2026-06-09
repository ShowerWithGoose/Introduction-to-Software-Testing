#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 
typedef struct{
	char wd[50];
	int num;
}words;
int judge(char c){
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		return 1;
	else 
		return 0;
}
void tran(char b[]){
	int i;
	for(i=0;i<strlen(b);i++){
		if(b[i]>=65&&b[i]<=90)
			b[i]=b[i]+32;
	}
	
}
int cmp(const void *t,const void *n){
	return strcmp((*(words*)t).wd,(*(words*)n).wd);
} 
int main(){
	FILE *in=fopen("article.txt","r"); 
	char w[50];
	words W[1000];
	 
	int i;
	char ch;
	for(i=0;i<1000;i++){
		W[i].num=0;
	}
	int k=0;
	char txt[10000];
	int len=0;
	while((ch=fgetc(in))!=EOF){
		if((ch>=32&&ch<=126)||ch==10||ch=='\0'){
			txt[len]=ch;
			len++;
		}
	}
	for(i=0;i<len;i++){
		int j,k,f;
		for(j=i;j<len;j++)
			if(judge(txt[j])==1)
				break;
		int begin=j;
		for(k=j+1;k<len;k++)
			if(judge(txt[k])==0)
				break;
		int end=k-1;
		i=k;
		int t,cnt=0;
		for(t=begin;t<=end;t++){
			w[cnt]=txt[t];
			cnt++;
		}
		
		w[cnt]='\0';
		tran(w);
		
		int flag=1;
		for(t=0;t<k;t++){
			if(strcmp(w,W[t].wd)==0){
				flag=0;
				W[t].num++;
				break;	
			}
		}
		if(flag==1){
			strcpy(W[k].wd,w);
			W[k].num++;
			k++;
		}
	}

	qsort(W,k,sizeof(W[0]),cmp);
	for(i=1;i<k;i++){
		printf("%s %d\n",W[i].wd,W[i].num);
	}
	
	return 0;
} 

