#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct words{
	char word[100];
	int cnt;
}words ;
int cmp(const void *a,const void *b);
int main(){
	FILE *fp1;
	fp1=fopen("article.txt","r");
	if(fp1==NULL){
		printf("Can't open the file!\n");
		return -1;
	} 
	char w[2000];
	int n=0,j=0,i=0,k=0;
	words A[1000];
	while(fgets(w,1000,fp1)!=NULL){
		for(i=0;i<strlen(w);i++){
			if(isalpha((int)w[i])==0&&k==0){
				continue; 
			}
			else if(isalpha((int)w[i])!=0&&k==0){
				k=1;
				A[n].word[j]=tolower(w[i]);
				j++;
			}
			else if(isalpha((int)w[i])!=0&&k==1){
				A[n].word[j]=tolower(w[i]);
				j++;
			}
			else if(isalpha((int)w[i])==0&&k==1){
				A[n].word[j]='\0';
				A[n].cnt=1;
				j=0;
				n++;
				k=0;
				for(j=0;j<=n-2;j++){
					if(strcmp(A[j].word,A[n-1].word)==0){
						A[j].cnt++;n--;break;
					}
				}
				j=0;
			}
		}
	}
	
	qsort(A,n,sizeof(A[0]),cmp);
	for(i=0;i<n;i++){
		printf("%s %d\n",A[i].word,A[i].cnt);
	}
	return 0;
}
cmp(const void *a,const void *b){
	words *w=(words*)a;
	words *q=(words*)b;
	return strcmp(w->word,q->word);
}

