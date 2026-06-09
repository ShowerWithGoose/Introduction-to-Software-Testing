#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct node{
	char word[1000];
	int num;
}voc;
char xiaoxie(char s);
void paixu(voc *s,int n);
int main()
{
	FILE *in;
	voc a[1000];
	in=fopen("article.txt","r");
	char ch;
	int i=0;
	int k=0;
	while(fscanf(in,"%c",&ch)!=EOF){
		if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')){
			a[k].word[i]=xiaoxie(ch);
			i++;
		}
		else if(strlen(a[k].word))
		{
			a[k].num=1;
			k++;
			i=0;
		}
	}	
	paixu(a,k);
	for(i=0;i<k;i++){
		if(strcmp(a[i].word,a[i+1].word)==0){
			a[i+1].num=a[i].num+a[i+1].num;
		}
		else if(strlen(a[i].word)){
			printf("%s %d\n",a[i].word,a[i].num);
		}
	}
} 
char xiaoxie(char s){
	if(s>='A'&&s<='Z'){
		return s+32;
	}
	else{
		return s;
	}
}
void paixu(voc *s,int n){
	voc temp;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(s[i].word,s[j].word)>0){
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
}

