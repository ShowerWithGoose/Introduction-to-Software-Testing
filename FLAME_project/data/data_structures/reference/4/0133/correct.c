#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct studen {
	char word[1000];
	int count;
} student;
student words[1000],temp;
int i,j,flag1,flag2,num;
char s[1000],tran[1000];
int main() {
	FILE *fp=fopen("article.txt","r");
	while(fgets(s,1000,fp)!=NULL) {
		int len=strlen(s);
		int cnt=0;
		flag1=0;
		for(i=0; i<len; i++) {
			if(isalpha(s[i])) {
				tran[cnt++]=tolower(s[i]);
				flag1=1;
			} else if(flag1==1) {
				flag1=0;
				flag2=0;
				for(j=0; j<num; j++) {
					if(strcmp(words[j].word,tran)==0) {
						words[j].count++;
						flag2=1;
						break;
					}
				}
				if(flag2==0) {
					strcpy(words[num].word,tran);
					words[num++].count=1;
				}
				memset(tran,0,sizeof(tran));
				cnt=0;
			}
		}
	}
	for(i=0; i<num; i++) {
		for(j=i; j<num; j++) {
			if(strcmp(words[i].word,words[j].word)>0) {
				temp=words[i];
				words[i]=words[j];
				words[j]=temp;
			}
		}
	}
	for(i=0; i<num; i++) printf("%s %d\n",words[i].word,words[i].count);
	fclose(fp);
	return 0;
}



