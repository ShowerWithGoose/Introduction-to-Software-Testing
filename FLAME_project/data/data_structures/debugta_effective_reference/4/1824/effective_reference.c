#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define Arraynum(x) (sizeof(x)/sizeof(x[0]))
#define MAXSIZES 1024
char c[MAXSIZES];
char s[1001][MAXSIZES],s1[1001][MAXSIZES];
int num,len,flag,num0[1001];
void sta(char *pIn) {
	char *pi,a;
	pi=pIn;
	while(*pi!='\0') {
		a=*pi;
		if((a>='A'&&a<='Z')||(a>='a'&&a<='z')) {
			if(islower(a)) s[num][len++]=a;
			else s[num][len++]=a-'A'+'a';
			flag=1;
		} else if(flag) {
			s[num][len]='\0';
			num++;
			len=0;
			flag=0;
		}
		pi++;
	}
}
int cmp(const void *x,const void *y) {
	return strcmp(x,y);
}
int main() {
	int i,j,k;
	int n,m,len,sum,num,x,y;
	FILE *fin;
	//打开文件
	if((fin=fopen("article.txt","r"))==NULL) {
		printf("fail to open the file1 !\n");
		exit(1);
	}
	while(fgets(c,MAXSIZES,fin)!=NULL) { //判断文件是否已结束；!feof(fpSrc)
		sta(c);
	}
	qsort(s,num,sizeof(s[0]),cmp);
	for(i=0,j=0; i<num; i++) {
		k=i;
		x=1;
		strcpy(s1[j],s[i]);
		while(strcmp(s[k],s[k+1])==0) {
			x++;
			k++;
		}
		num0[j++]=x;
		i=k;
	}
	for(i=0; i<j; i++) {
		printf("%s %d\n",s1[i],num0[i]);
	}
	fclose(fin);
	getchar();
	getchar();
	return 0;
}


