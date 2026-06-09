#include<stdio.h>
#include<ctype.h>
#include<string.h>
char *getword(FILE*);
int main()
{
	struct{
		char word[32];
		int time;
	} fre[200];
	FILE *in,*out;
	char *s;
	int i=0,j,k,flag;
	in=fopen("article.txt","r");
	while((s=getword(in))!=NULL){
		flag=0;
		for(j=0;j<i;j++){
			if(strcmp(s,fre[j].word)==0){
				fre[j].time++;
				flag=1;
				break;
			}
			else if(strcmp(s,fre[j].word)<0){
				for(k=i-1;k>=j;k--){
					fre[k+1]=fre[k];
				}
				strcpy(fre[j].word,s);
				fre[j].time=1;
				flag=1;
				i++;
				break;
			}
		}
		if(flag==0){
			strcpy(fre[j].word,s);
			fre[j].time=1;
			i++;
		}
	}
	for(j=0;j<i;j++){
		printf("%s %d\n",fre[j].word,fre[j].time);
	}
	return 0;
}
char *getword(FILE *in)
{
	char c,s[32]="",*p;
	int i=0,flag=0;
	while((c=fgetc(in))!=EOF){
		c=tolower(c);
		if((c<'a'||c>'z')&&flag==0)
			continue;
		else if(c>='a'&&c<='z'){
			s[i++]=c;
			flag=1;
		}
		else{
			s[i]='\0';
			p=s;
			return p;
		}
	}
	return NULL;
}



