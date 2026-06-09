#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct count{
	char word[20];
	int num;
}letter[1000];
FILE *in;
int main()
{
	in=fopen("article.txt","r");
	char scan[20]={'\0'},ch;
	int j=0;
	while(~fscanf(in,"%c",&ch)){                             //将单词全部存入letter中 
		int i=0,temp=0;
		while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
			if(ch>='a'&&ch<='z')
				scan[i]=ch;
			else
				scan[i]=ch-'A'+'a';
			fscanf(in,"%c",&ch);
			i++;
			temp=1;
		}
		if(temp==1){
			scan[i]='\0';
			strcpy(letter[j].word,scan);
			letter[j].num=1;
			j++;
		}	
	}
	for(int i=0;i<j;i++){
		for(int k=i+1;k<j;k++){
			if(strcmp(letter[k].word,letter[i].word)==0){
				letter[i].num++;
				for(int x=k;x<j-1;x++){
					letter[x]=letter[x+1];
				}
				k--; 
				j--;
			}
		}
	} 
//	qsort(letter,j,sizeof(struct count),cmp);
	for(int i=0;i<j;i++){
		for(int k=i+1;k<j;k++){
			struct count temp;
			if(strcmp(letter[k].word,letter[i].word)<0){
				temp=letter[k];
				letter[k]=letter[i];
				letter[i]=temp;
			}
		}
	}
	for(int k=0;k<j;k++){
		printf("%s %d\n",letter[k].word,letter[k].num);
	}
}


