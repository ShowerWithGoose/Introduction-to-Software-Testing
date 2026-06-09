#include<stdio.h>
#include <math.h> //数学公式
#include <stdlib.h> //快排和malloc
#include <ctype.h> //字符处理函数
#include <string.h> //字符串函数
#define ll long long
#define eps 1e-6
#define MAX 1000005
typedef struct list{
	char word[105];
	int cnt;
}num;
	num s[10005];
int main(){
	FILE *fp=fopen("article.txt","r");
	char s1[10005]="";
	char s2[10005]="";
	char *a[1005]={NULL};
	fread(s1,sizeof(s1[0]),10005,fp);
	int len1=strlen(s1),i=0,j=0;
	for(i=0;i<len1;i++){
		if(s1[i]>='A'&&s1[i]<='Z'){
			s1[i]=s1[i]-'A'+'a';
		}
	}
	int n=0;
	for(i=0;i<len1;){
		if(!isalpha(s1[i])){
		 i++;
		 continue;
		}
		else{
			int tmp=j;
			while(isalpha(s1[i])){
				
				s2[j++]=s1[i];
				i++;
			}
			s2[j++]='\0';
			strcpy(s[n].word,&s2[tmp]);
			a[n++]=&s2[tmp];
		}
	}
	int n1;
	for(i=0;i<n;i++){
		for(n1=i;n1<n;n1++){
			if(strcmp(a[n1],a[i])==0){
				s[i].cnt++;
			}
		}
	}
	for(i=0;i<n;i++){
		int flag=0;
		for(j=0;j<n-1;j++){
			if(strcmp(s[j].word,s[j+1].word)>0){
				num tp=s[j];
				s[j]=s[j+1];
				s[j+1]=tp;
				flag=1;
			}	
		}
		if(flag==0) break;
	}
	for(i=0;i<n;i++){
		int flag=0;
		for(j=0;j<i;j++){
			if(strcmp(s[i].word,s[j].word)==0){
				flag=1;
			}
		}
		if(flag==0)
		printf("%s %d\n",s[i].word,s[i].cnt);
	}
	fclose(fp);

	return 0;
}


