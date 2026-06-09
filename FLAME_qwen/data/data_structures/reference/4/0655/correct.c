#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define Arraynum(x) (sizeof(x)/sizeof(x[0]))
#define MAXSIZES 1024
char now[MAXSIZES];
char s[1001][MAXSIZES],s1[1001][MAXSIZES];
int u,v,flag,book[1001];
void sta(char *pIn) {
	char *pi,a;
	pi=pIn;
	while(*pi!='\0') {
		a=*pi;
		if((a>='A'&&a<='Z')||(a>='a'&&a<='z')) {
			if(islower(a)) s[u][v++]=a;
			else s[u][v++]=a-'A'+'a';
			flag=1;
		} else if(flag) {
			s[u][v]='\0';
			u++;
			v=0;
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
	while(fgets(now,MAXSIZES,fin)!=NULL) { //判断文件是否已结束；!feof(fpSrc)
		sta(now);
	}
	qsort(s,u,sizeof(s[0]),cmp);
	for(i=0,j=0; i<u; i++) {
		k=i;
		x=1;
		strcpy(s1[j],s[i]);
		while(strcmp(s[k],s[k+1])==0) {
			x++;
			k++;
		}
		book[j++]=x;
		i=k;
	}
	for(i=0; i<j; i++) {
		printf("%s %d\n",s1[i],book[i]);
	}
	fclose(fin);
	getchar();
	getchar();
	return 0;
}


