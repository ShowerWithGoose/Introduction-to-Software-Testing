#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct word{
	char w[500];
	int num;
}; 
typedef struct word P;
int cmp(const void*p1,const void*p2){
	struct word* a=(struct word*) p1;
	struct word* b=(struct word*) p2;
	return strcmp(a->w,b->w);
}
P a[1000];
char s[100000],c,s1[10000];
int main(){
	FILE *fp=fopen("article.txt","r");
	int i=0,j,cnt=0,k;
	while((c=fgetc(fp))!=EOF){
		s[i++]=c;
	}
	int len=strlen(s);
	for(i=0;i<strlen(s);i++){
		if(isalpha(s[i])){
			s[i]=tolower(s[i]);
		}
	}
	for(i=0;i<len;i++){
		if(isalpha(s[i])){
			for(j=i;j<len;j++){
				if(!isalpha(s[j])) break;
			}
			for(k=0;k<j-i;k++){
				s1[k]=s[i+k];
			}
			strcpy(a[cnt].w,s1);
			cnt++;
			memset(s1,0,sizeof(s1));
			i=j;
		}
	}
	qsort(a,cnt,sizeof(P),cmp);
	for(i=0;i<cnt;i++){
		a[i].num=1;
	}
	for(i=0;i<cnt;i++){
		if(strcmp(a[i].w,a[i+1].w)==0){
			a[i+1].num+=a[i].num;
			a[i].num=0;
		}
	}
	for(i=0;i<cnt;i++)
		if(a[i].num!=0){
			printf("%s %d\n",a[i].w,a[i].num);
		}
}


