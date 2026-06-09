#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
struct str{
	char s[20];  //µ¥´Ê 
	int t; //´ÎÊý 
};
int cmp(const void*a,const void*b);
int main(){
	FILE *in;
	in=fopen("article.txt","r");
	char s1[20]={},ch;
	char s2[1000];
	int i=0,j,flag=0,k=0,m=0,n=0,p=0;
	struct str words[1000];
	while(~(ch=fgetc(in))){
		s2[k++]=ch;
	}
	for(i=0;i<k;m=0){
		while(1){ 
			if(isalpha(s2[i])&&i<k){
				s1[m++]=tolower(s2[i]);
				i++;
			}
			else{
				i++;
				break;
			}
		}
		if(s1[0]!='\0'){
			strcpy(words[n].s,s1);
			words[n].t=1;
			for(p=0;p<20;p++)
				s1[p]='\0';
			flag=0;
			for(j=0;j<n;j++){
				if(strcmp(words[n].s,words[j].s)==0){  
					words[j].t++;
					flag=1;
					break;
				}
			}
			if(flag==0)
				n++;
		}
	}
	qsort(words,n,sizeof(words[0]),cmp);
	for(j=0;j<n;j++){
		printf("%s %d\n",words[j].s,words[j].t);
	}
	fclose(in);
	return 0;
}
int cmp(const void*a,const void*b){
	struct str*c=(struct str*)a;
	struct str*d=(struct str*)b;
	return strcmp(c->s,d->s);
}

