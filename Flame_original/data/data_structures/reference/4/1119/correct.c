#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLINE  1024
struct words{
	char word[30];
	int num;

	}W[150];
int cmp(const void*a,const void*b){
	struct words*aa=(struct words*)a;
	struct words*bb=(struct words*)b;
	return strcmp(aa->word,bb->word);
}
char sen[MAXLINE];
int main(){
	FILE *in,*out;
	int flag=0,i=0,j=0,k,flagg=0;
	char *p,*q;
	char temp[100]="";
	for(k=0;k<150;k++){
		W[k].num=0;
	}
	in=fopen("article.txt","r");
	fread(sen,sizeof(char),MAXLINE-1,in);
	p=sen;
	
	while(*p!='\0'){
		if(*p>='A'&&*p<='Z')
			*p=*p+'a'-'A'; 
		p++;
	}	
	p=sen;
	while(*p!='\0'){
		if(islower(*p)&&flag==0){
			flag=1;
			q=p;
			p++;
		}
		else if(islower(*p)&&flag==1){
			//W[i].word[j]=*p;
			//j++;
			p++;
		}	
		else if((!islower(*p))&&flag==1){
			flag=0;
			*p='\0';
			sscanf(q,"%s",temp);
			for(k=0;k<i;k++){
				if(strcmp(temp,W[k].word)==0){
					W[k].num++;
					flagg=1;
					break;
				}
			}	
			if(flagg==0){
				strcpy(W[i].word,temp);
				W[i].num++;
				i++;
				
			}
			memset(temp,'\0',95);	
			flagg=0;
			p++;
		}
		else
			p++;
	}
	qsort(W,i,sizeof(struct words),cmp);
	for(k=0;k<i;k++){
		printf("%s %d\n",W[k].word,W[k].num);
	}
	return 0;
}	
	
	
	
	
	
	
 

