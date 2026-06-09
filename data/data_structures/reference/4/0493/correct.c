#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1410 

typedef struct words{
	char word[200];
	int num;
}a[M];
int com(const void *a,const void *b){
	struct words * c=(struct words*)a;
	struct words * d=(struct words*)b;
	return strcmp(c->word ,d->word);
}
void dele(struct words *k,int position,int l){   //checked
	int p=position;
	int i,j;
	for(i=p;i<l-1;i++){
		k[i]=k[i+1];
	}
	
}
int main(){
	FILE *ar=fopen("article.txt","r"); 
	int i=0,j=0,k=0;
	char c;

	char s[M];
	struct words a[M];
	while((c=fgetc(ar))!=EOF){
		s[i++]=c;
	}            
	s[i]='\0';
	int ls=strlen(s);
	for(i=0;i<ls;i++){          //creat word list
		if(isalpha(s[i])){
		 int t=0;
		 for(j=i;isalpha(s[j]);j++){
			 a[k].word[t++] =tolower(s[j]);
		 }
		 a[k].word [t]='\0';
		 a[k].num =1;
		 k++;
		 i+=t-1;
		} 
		else if(!isalpha(s[i])) continue;
	}
	int la=k;
	qsort(a,la,sizeof(a[0]),com);
	for(i=0;i<la;i++){
		for(j=i+1;j<la;j++){
			if(strcmp(a[i].word,a[j].word)==0){
				a[i].num ++;
				dele(a,j,la);
				j--;
				la--;
			}
		}
	}
	
	for(i=0;i<la;i++){
		printf("%s %d\n",a[i].word,a[i].num );
	}
	                              
	return 0;
}

