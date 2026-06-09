#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

char word[100000][100],input[10000];

int comp(const void *a,const void *b);

int main(){
	int flag=0,i,j=0,k=0;
	freopen("article.txt","r",stdin);
	while(scanf("%s",input)!=EOF){
		for(i=0;i<strlen(input);i++){
			if(isupper(input[i])) input[i]+=32;
			if(islower(input[i])) word[j][k]=input[i],flag=1,k++;
			else if(flag==1) flag=0,j++,k=0;
		}
		if(flag==1) j++,k=0,flag=0;
	}
	qsort(word,j,sizeof(word[0]),comp);
	for(int num=1,m=0;m<=j;m++){
		if(!strcmp(word[m],word[m+1])) num++;
		else{
			printf("%s %d\n",word[m],num);
			num = 1;
		} 
	}
	return 0;
}

int comp(const void *a,const void *b){
	char *aa = (char *)a;
	char *bb = (char *)b;
	return strcmp(aa,bb);
}

