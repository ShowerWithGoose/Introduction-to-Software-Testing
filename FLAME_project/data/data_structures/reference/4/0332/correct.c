#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
char s0[10002];
char s1[10002];
int cmp(const void *,const void *);
typedef struct hyb{
	char string[30];
	int num;
}block;
block a[1000];
int count=0;
int main() {
	int len;
	FILE *in=fopen("article.txt","r");
	fread(s0, sizeof(char), 10000, in);
	fclose(in);
	for(int i=1002;i>=0;i--){
		if(s0[i]!='\0'){len=i+1;break;}
	}
	for(int i=0;i<len;i++){
		if(s0[i]<='Z'&&s0[i]>='A'){
			s1[i]=s0[i]-'A'+'a';
		}
		else s1[i]=s0[i];
	}
	for(int i=0;i<len;i++){
		if(islower(s1[i])&&(!(islower(s1[i-1])))){
			for(int j=0;islower(s1[i+j]);j++){
				a[count].string[j]=s1[i+j];
				a[count].string[j+1]='\0';
			}
			a[count].num=1;
			count++;
		}
	}
	for(int i=0;i<count;i++){
		for(int j=i+1;j<count;j++){
			if(strcmp(a[i].string,a[j].string)==0){
				for(int l=j;l<count-1;l++){
					a[l]=a[l+1];
				}
				count--;
				a[i].num++;
				j--;
			}
		}
	}
	qsort(a,count,sizeof(a[0]),cmp);
	for(int i=0;i<count;i++){
		printf("%s %d\n",a[i].string,a[i].num);
	}
	
	
	return 0;
}
int cmp(const void *x,const void *y){
	char *xx=(char *)x;
	char *yy=(char *)y;
	return strcmp(xx,yy);
}



