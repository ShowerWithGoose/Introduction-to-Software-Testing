#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define lower(c) c>='A'&&c<='Z'?c+32:c
struct node{
	char w[20];
	int count;
}words[1500];
int main(){
	FILE *in;
	in=fopen("article.txt","r");
	char c;
	int len=0;
	c=fgetc(in);
	while(c!=EOF){
		char word[30]={'\0'};
		if(isalpha(c)){
			c=lower(c);
			int n=0;
			word[n++]=c;
			c=fgetc(in);
			while(isalpha(c)){
				c=lower(c);
				word[n++]=c;
				c=fgetc(in);
			}
			word[n]='\0';
			int low=0,high=len,mid,op=0; 
			while(low<=high){
				mid=(low+high)/2;
				if(strcmp(word,words[mid].w)<0){
					high=mid-1;
				}
				else if(strcmp(word,words[mid].w)>0){
					low=mid+1;
				}
				else if(strcmp(word,words[mid].w)==0){
					words[mid].count++;
					op++;
					break;
				}	
			}
			if(op==0){
				len++;
				for(int i=len;i>low;i--){
					words[i].count=words[i-1].count;
					strcpy(words[i].w,words[i-1].w);
				}
				words[low].count=1;
				strcpy(words[low].w,word);
			}
		continue;
		}
		c=fgetc(in);
	}
	for(int i=1;i<len+1;i++)
		printf("%s %d\n",words[i].w,words[i].count);
	return 0;
}



