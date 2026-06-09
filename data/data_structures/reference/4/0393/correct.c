#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 
typedef struct{
	char w[50];
	int count;
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
int cmp(const void *m,const void *n){
	return strcmp((*(words*)m).w,(*(words*)n).w);
} 
int main(){
	FILE *in=fopen("article.txt","r"); 
	char word[50];
	words a[1000];
	 
	int i;
	char ch;
	for(i=0;i<1000;i++){
		a[i].count=0;
	}
	int num=0;
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
		int m,cnt=0;
		for(m=begin;m<=end;m++){
			word[cnt]=txt[m];
			cnt++;
		}
		
		word[cnt]='\0';
		tran(word);
		
		int flag=1;
		for(m=0;m<num;m++){
			if(strcmp(word,a[m].w)==0){
				flag=0;
				a[m].count++;
				break;	
			}
		}
		if(flag==1){
			strcpy(a[num].w,word);
			a[num].count++;
			num++;
		}
	}

	qsort(a,num,sizeof(a[0]),cmp);
	for(i=1;i<num;i++){
		printf("%s %d\n",a[i].w,a[i].count);
	}
	
	return 0;
} 

