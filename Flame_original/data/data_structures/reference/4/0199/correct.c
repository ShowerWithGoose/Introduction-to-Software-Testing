
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include <stdio.h>
char txt[200][500];
struct wordlist{
	char word[30];
	int  x;
};
struct wordlist wordn[500];
void num(struct wordlist a[],int size);
int main(){
FILE *fp;
fp = fopen("article.txt","r");
if(fp==NULL){
printf("Can't open the file!\n");
return -1;
}
int i=0,m=0,j=0,k=0;
while(fgets(txt[i],500,fp)!=NULL){
	i++;
}
fclose(fp);
int len;
len=i+1;
int flag=0;
for(i=0;i<len;i++){
	for(j=0;j<strlen(txt[i]);j++){
		k=0;flag=0;
		while(isalpha(txt[i][j])){
			if('A'<=txt[i][j]&&txt[i][j]<='Z')
			txt[i][j]=tolower(txt[i][j]);
			wordn[m].word[k]=txt[i][j];
			j++;
			k++;
			wordn[m].x=1;
			flag=1;
		}if(flag==1){
			wordn[m].word[k]='\0';
			m++;
		}
	}
}
int len1;
len1=m;
for(i=0;i<len1-1;i++){
	for(j=i+1;j<len1;j++){
		if(wordn[j].x==0){
			continue;
		}
		if(strcmp(wordn[i].word, wordn[j].word)==0){
			wordn[i].x++;
			wordn[j].x=0;
		}
	}
}
num(wordn,len1);
for(i=0;i<len1;i++){
	if(wordn[i].x==0){
		continue;
	}else{
		printf("%s %d\n",wordn[i].word,wordn[i].x);
	}
}

    return 0;
}
void num(struct wordlist a[],int size){
	int i=0,j=0;
	char worx[30];
	int m=0;
	int hold=0;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-1-i;j++){
			m=0;
			while(a[j].word[m]==a[j+1].word[m]&&a[j].word[m]!='\0'&&a[j+1].word[m]!='\0'){
				m++;
			}
			if (a[j].word[m]>a[j+1].word[m]||a[j+1].word[m]=='\0'){
				hold=a[j].x;
				strcpy(worx,a[j].word);
				a[j].x=a[j+1].x;
				strcpy(a[j].word,a[j+1].word);
				a[j+1].x=hold;
				strcpy(a[j+1].word,worx);
			}
		}
	}
	return ;
}


