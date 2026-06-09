#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
char temp[10000],c;
int i,j,k,len;
struct word{
	char s[1000];
	int num;
}p[1000];
int cmp(const void *a,const void *b){
	struct word *c=(struct word*)a;
	struct word *d=(struct word*)b;
	return strcmp(c->s,d->s);
}
int main()
{
	FILE *in=fopen("article.txt","r");
	while((c=fgetc(in))!=EOF){
		temp[i]=c;
		i++;
	}
	i=0;
	len=strlen(temp);
	for(k=0;k<len;k++){
		if(isalpha(temp[k])==0){
			i++;
			j=0;	
		}
		else{
			p[i].s[j]=tolower(temp[k]);
			j++;
		}
	}
	qsort(p,i,sizeof(p[0]),cmp);
	for(k=0;k<i;k++){
		if(strlen(p[k].s)!=0){
			p[k].num++;
		}
	}
	for(k=0;k<i;k++){
		if(p[k].num!=0){
			for(j=k+1;j<i;j++){
				if(strcmp(p[k].s,p[j].s)==0){
					p[k].num++;
					p[j].num--;
				}
			}
		}
	}
	for(k=0;k<i;k++){
		if(p[k].num!=0){
			printf("%s %d\n",p[k].s,p[k].num);
		}
	}
	
return 0;
}




