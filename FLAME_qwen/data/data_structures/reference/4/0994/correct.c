#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct{
	
	char str[55]; 
	int cnt;
	
}strcnt;

strcnt words[1024];

int comp(const void *,const void *);

void low(char s[]);

int main() {
	
	char buf[55],c,cc; 
	FILE *fp;
	int num=0;
	int i,j,n=1;

	fp=fopen("article.txt","r");
	while((c=fgetc(fp))!=EOF){
		if(isalpha(c)==0){
			continue;
		}
		else{
			buf[0]=c;
			cc=fgetc(fp);
			int ans=1;
			while(isalpha(cc)!=0){
				buf[ans]=cc;
				ans++;
				cc=fgetc(fp);
			}
			buf[ans]='\0';
			low(buf);
			n=1;
			for (i=0;i<num;i++) {
				if (strcmp(buf, words[i].str)==0){
					n=0;
					words[i].cnt++;
				}
			}
			if (n){
				for (j=0; buf[j]!='\0'; j++) {
					words[num].str[j] = buf[j];
				}
				words[num].str[j] = '\0';
				words[num++].cnt = 1;
			}		
		}
	}
	qsort(words,num,sizeof(strcnt),comp);
	for (i=0;i<num; i++) {
		printf("%s %d\n", words[i].str, words[i].cnt);
	}
	fclose(fp);
	return 0;
}

int comp(const void *_p1,const void *_p2){
	
	strcnt *x=(strcnt *)_p1;
	strcnt *y=(strcnt *)_p2;
	
	return strcmp(x->str,y->str);
}

void low(char s[]){
	
	int len=strlen(s);
	for(int i=0;i<len;i++){
		s[i]=tolower(s[i]);
	}	
	
	return ;
}

