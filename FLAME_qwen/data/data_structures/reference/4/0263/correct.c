#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct node{
	char word[51];
	int num;
}list[2000],tem;
int NUM=0;

int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char wordin[50], wordout[50], words[50][50];
	
	int i,j,len1,len2,len3,num,k,judge;
	while(fscanf(in,"%s",wordin)!=EOF){
		num=0;
		len1=strlen(wordin);
		for(i=0;i<len1;i++){
			if((isalpha(wordin[i]))){
				if(i==0||(wordin[i-1]<'A')||(wordin[i-1]<'a'&&wordin[i-1]>'Z')||wordin[i-1]>'z'){
					num++;
					len2=0;
					for(j=i;isalpha(wordin[j]);j++){
						len2++;
					}
					for(j=i,k=0;j<i+len2;j++,k++){
						words[num][k]=wordin[j];
					}
					words[num][k]='\0';
					i=i+len2;
				}
			}
		}
		
		for(i=1;i<=num;i++){
			strcpy(wordout,words[i]);
			len3=strlen(wordout);
			for(j=0;j<len3;j++){
				if(wordout[j]>='A'&&wordout[j]<='Z')
				wordout[j]=tolower(wordout[j]);
			}
			
			judge=1;
			for(j=0;j<NUM;j++){
				if(strcmp(list[j].word,wordout)==0){
					list[j].num++;
					judge=0;
				}
			}
			if(judge!=0){
				strcpy(list[j].word,wordout);
				list[j].num=1;
				NUM++;
			}
		}
	}
	for(i=0;i<NUM-1;i++){
		for(j=i;j<NUM;j++){
			if(strcmp(list[i].word,list[j].word)>0){
				tem=list[j];
				list[j]=list[i];
				list[i]=tem;
			}
		}
	}
	for(i=0;i<NUM;i++)
	{
		printf("%s %d\n",list[i].word,list[i].num);
	}
	return 0; 
 } 

