#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct WORD{
	char c[105];
	int count;	
}word;
word w[1000005];
int rise(const void *a,const void *b){
	word *p=(word *)a;
	word *q=(word *)b;
	for(int i=0; p->c[i]!='\0'||q->c[i]!='\0'; i++){
		if(p->c[i] > q->c[i]) return 1;
		else if(p->c[i] < q->c[i])return -1;
	}return 0;
}
int main(){
	FILE *in=fopen("article.txt","r");
	int n=0;
	int m=0;
	char d;
	while(fscanf(in,"%c",&d)!=EOF){
		if('a'<=d&&d<='z'){
			w[n].c[m++]=d;
		}
		else if('A'<=d&&d<='Z'){
			w[n].c[m++]=d+'a'-'A'; 
		}
		else if(w[n].c[0]=='\0'){
			continue;
		}
		else {
			int flag=0;
			for(int i=0; i<n; i++){
				if(strcmp(w[i].c,w[n].c)==0){
					flag=1;
					w[i].count++;
					for(int j=0; w[n].c[j]!='\0'; j++){
						w[n].c[j]='\0';
					}	
					break;
				}
			}
			if(flag==0){
				w[n].count++;
				n++;
			}m=0;
		}
	}
	qsort(w,n,sizeof(word),rise);
	for(int i=0; i<n; i++){
		printf("%s %d\n",w[i].c,w[i].count);		
	}
	return 0;
}

