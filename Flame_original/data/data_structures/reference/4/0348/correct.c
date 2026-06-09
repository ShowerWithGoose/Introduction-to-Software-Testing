#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct word{
	char name[105];
	int cnt;
	int flag;
};

char bcxx(char o){
	if(o<='Z'&&o>='A'){
		return o+=32;
	}
	else{
		return o;
	}
}


char s[100005];
struct word wor[200];
int main(){
	FILE *in;
	in=fopen("article.txt","r");
	int cnt=0;
	char c;
	while((c=fgetc(in))!=EOF){
		s[cnt]=c;
		cnt++;
	}
	int cnt1=0,k=0;
	for(int i=0;i<=cnt;i++){
		if((s[i]<='Z'&&s[i]>='A')||(s[i]<='z'&&s[i]>='a')){
			wor[cnt1].name[k]=bcxx(s[i]);
			k++;
		}
		else{
			cnt1++;
			k=0;
			continue;
		}
	}
	for(int i=0;i<cnt1;i++){
		for(int j=0;j+1<cnt1-i;j++){
			if(strcmp(wor[j].name,wor[j+1].name)>0){
				char gap[30];
				strcpy(gap,wor[j].name);
				strcpy(wor[j].name,wor[j+1].name);
				strcpy(wor[j+1].name,gap);
			}
		}
	}
	for(int i=0;i<cnt1;i++){
		if(strlen(wor[i].name)!=0){
			wor[i].cnt=1;
		}
	}
	for(int i=cnt1-1;i>=0;i--){
		if(strcmp(wor[i].name,wor[i+1].name)==0){
			wor[i].cnt+=wor[i+1].cnt;
			wor[i+1].cnt=0;
		}
	}
	for(int i=0;i<cnt1;i++){
		if(wor[i].cnt!=0){
			printf("%s %d\n",wor[i].name,wor[i].cnt);
		}
	}
	return 0;
}



