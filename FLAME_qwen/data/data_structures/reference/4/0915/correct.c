#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
struct wan {
	char s[50];
	int num;
} p[110],tmp;
int main() {
	FILE *in;
	in=fopen("article.txt","r");
	int i=1;
	int flag=1;
	char c;
	while((c=fgetc(in))!=EOF) {
		if(!isalpha(c)) continue;
		int k=0;
		while(isalpha(c)) {
			tmp.s[k]=tolower(c);
			k++;
			c=fgetc(in);
		}
		tmp.s[k]='\0';
		tmp.num=1;
		for(int j=1; j<i; j++) {
			if(strcmp(p[j].s,tmp.s)==0) {
				p[j].num++;
				flag=0;
				break;
			}
		}
		if(flag) {
			p[i++]=tmp;
		}
		flag=1;
	}
	for(int q=1; q<100; q++) {
		for(int j=q+1; j<=100; j++) {
			if(strcmp(p[q].s,p[j].s)>0) {
				tmp=p[q];
				p[q]=p[j];
				p[j]=tmp;
			}
		}
	}
	for(int i=1; i<=100; i++) {
		if(p[i].num!=0)
			printf("%s %d\n",p[i].s,p[i].num);
	}
	fclose(in);
	return 0;
}



