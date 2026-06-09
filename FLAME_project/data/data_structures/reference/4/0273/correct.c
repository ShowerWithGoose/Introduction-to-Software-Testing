#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct god{
	int num;
	char word[1000];
};
int max(int x,int y){
	if(x<y) return y;
	else return x;
}
int main(){
	int i,t=0,k,flag1,flag2,j,l;
	struct god a[1000];
	char s[1000],example[1000];
	FILE *fp;
	fp=fopen("article.txt","r");
	while(fgets(s,1000,fp)!=NULL){
		for(l=0;l<strlen(s);l++) if(isalpha(s[l])) {
			k=0;
			j=strlen(example);
			for(i=0;i<j;i++) example[i]='\0';
		while(1){
			example[k++]=tolower(s[l++]);
			if(!isalpha(s[l])) {
				l--;
				flag1=1;
				for(i=1;i<=t;i++) if(a[i].word[0]==example[0]) {
				flag2=0;
				for (j=1;j<max(strlen(example),strlen(a[i].word));j++)
														if(example[j]!=a[i].word[j]){
															flag2=1;
															break;
														}
				if (flag2==0) {
					flag1=0;
					break;
				}
				}
				if(flag1==1) t++,strcpy(a[t].word,example),a[t].num++;
				else a[i].num++;
				break;
			}
		}
		
	}
	}
	for(i=1;i<t;i++)
		for(j=1;j<=t-i;j++)
			if(strcmp(a[j].word,a[j+1].word)>0) {
				a[0]=a[j];
				a[j]=a[j+1];
				a[j+1]=a[0];
			}
	for(i=1;i<=t;i++) {
		for(j=0;j<strlen(a[i].word);j++) printf("%c",a[i].word[j]);
		printf(" ");
		printf("%d\n",a[i].num);
	}
	fclose(fp);
} 

