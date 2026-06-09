#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct word{
	char s[100];
	int n;
}Word;
Word words[200],temp,last[200];
char ori[1024];
int flag[200],number;
void dele(Word a[],int n){
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(a[i].s,a[j].s)==0){
				(a[i].n)++;
				flag[j]++;
			}
		}
	}
	for(i=0,j=0;i<n;i++){
		if(flag[i]!=0){
			continue;
		}
		last[j++]=a[i];
	}
	number=j;
}
void bubblesort(Word a[],int n){
	int i,j,k;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(strcmp(a[j].s,a[j+1].s)>0){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int main(){
	int i=0,j=0,k=0,num;
	char ch;
	FILE *fin=fopen("article.txt","r");
	while(fgets(ori,1023,fin)!=NULL){
		for(i=0;i<strlen(ori);i++){
			if(isalpha(ori[i])){
				if(ori[i]>='A'&&ori[i]<='Z'){
					ori[i]=tolower(ori[i]);
				}
				words[j].s[k++]=ori[i];
			}
			if(isalpha(ori[i])!=0&&isalpha(ori[i+1])==0){
				words[j].s[k]='\0';
				words[j].n=1;
				j++;
				k=0;
				num=j;
			}
		}
	}
	dele(words,num);
	bubblesort(last,number);
	for(i=0;i<number;i++){
		printf("%s %d\n",last[i].s,last[i].n);
	}
	return 0;
}



