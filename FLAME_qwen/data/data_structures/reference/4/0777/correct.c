#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
FILE *in;
struct word{
	char s[10000];
	int cnt; 
}word[20000];
int comp(const void* p,const void* q) {
	struct word *pp=(struct word *)p;
	struct word *qq=(struct word *)q;
	return (strcmp(pp->s,qq->s));
}
int main(){
	in=fopen("article.txt", "r");
	char c;
	char f[10000];
	int i=0,j=0,k=0;
	while((c=fgetc(in))!=EOF){
		f[i++]=c;
	}
	gets(f);
	int len;
	int n=0;
	len=strlen(f);
	for(i=0;i<len;i++){
		if(f[i]>=65&&f[i]<=90){
			f[i]=f[i]+32;
		}
		if(f[i]>=97&&f[i]<=122){
			word[k].s[n++]=f[i];
		}
		if(f[i]<97||f[i]>122){
		   k++;
		   n=0;	
		}
	}
	int num=0,y,t;
	int op;
	for(i=0;i<=k;i++){
		if(word[i].s[0]>=97&&word[i].s[0]<=122){ 
		word[i].cnt++;
			for(y=i+1;y<=k;y++){
				if(strcmp(word[y].s,word[i].s)==0){
					for(t=y;t<k;t++){
						strcpy(word[t].s,word[t+1].s);
						word[t].cnt=word[t+1].cnt;
					}
				    word[i].cnt++;
				    k--;
				    y--; 
				}
			}
		}
		else{		
			for(op=i;op<k;op++){
				strcpy(word[op].s,word[op+1].s);
				word[op].cnt=word[op+1].cnt;
			}k--;i--;
			}
		}
	qsort(word,k+1,sizeof(word[0]),comp);
	for(i=0;i<=k;i++){
		if(word[i].cnt!=0)
		printf("%s %d\n",word[i].s,word[i].cnt);
	}
	return 0;
}

