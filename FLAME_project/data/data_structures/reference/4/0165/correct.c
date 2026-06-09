#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define S scanf
#define P printf
#define L long long
int cmp(const void *a, const void *b){
	return strcmp(a,b);
}
char s[105][105],ch;
int main(){
	FILE *in;
	int i=0,j=0,k,l,m=0,num[105];
	in=fopen("article.txt","r");
	while((ch=fgetc(in))!=-1){
		if(isalpha(ch)){
			s[i][j]=ch;
			j++;
		}
		else if(ispunct(ch)||isspace(ch)){
			s[i][j]='\0';
			i++;
			j=0;
		}
	}
	for(k=0;k<i;k++){
		for(l=0;l<sizeof(s[k]);l++){
			s[k][l]=tolower(s[k][l]);
		}
	}
	qsort(s,i,sizeof(s[0]),cmp);
	for(k=0;k<i;k++){
		num[k]=1;
	}
	for(k=0;k<i;k++){
		if(s[k][0]!='\0'){
			for(l=k+1;l<i;l++){
			    if(strcmp(s[k],s[l])==0){
				num[m]++;
				s[l][0]='\0';
			    }	
		    }
		}
		m++;
	}
	for(k=0;k<i;k++){
		if(s[k][0]!='\0'){
			P("%s %d\n",s[k],num[k]);
		}
	}
	return 0;
}



