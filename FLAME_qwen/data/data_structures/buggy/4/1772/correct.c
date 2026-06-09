#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*x,const void*y);
int main() {
	FILE *in=fopen("article.txt","r");
	char c,word[77][17];
	int i=0,j=0,flag=0,book[77]= {0};
	while((c=fgetc(in))!=EOF) {
		if(c<=90&&c>=65) {
			flag=0;
			word[i][j++]=c+32;
		} else if(c<=122&&c>=97) {
			flag=0;
			word[i][j++]=c;
		} else if(flag==0) {
			word[i++][j]='\0';
			flag=1;
			j=0;
		} else;
	}
	qsort(word,i,sizeof(word[0]),cmp);
	for(int t=0; t<i; t++) {
		if(book[t]==0) {
			int num=0;
			for(int p=t; p<i; p++) {
				if(strcmp(word[t],word[p])==0) {
					num++;
					book[p]=1;
				}
			}
			printf("%s %d\n",word[t],num);
		}
	}
	fclose(in);
	return 0;
}
int cmp(const void*x,const void*y)
{
	char *p=(char*)x;
	char *q=(char*)y;
	if(strcmp(p,q)>0)
	return 1;
	else
	return -1;
}
