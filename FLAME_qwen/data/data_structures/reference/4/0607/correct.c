#include<stdio.h>
#include<string.h>
#define max 10010
struct node{
	char words[20];
	int tot;
}num[10010];
int cnt=0;
char st[max];

int cmp(void*a,void*b){
	struct node m=*(struct node*)a;
	struct node n=*(struct node*)b;
	return strcmp(m.words,n.words);
}

void deal(){
	int l=strlen(st);
	int i;
	for(i=0; i<l; i++){ //×ª»»´óÐ¡Ð´ 
		if(st[i]<='Z'&&st[i]>='A'){
			st[i]=st[i]+'a'-'A';
		}
	}
	for(i=0; i<l; i++){
		if(st[i]>'z'||st[i]<'a') continue;
		char now[20],j=0;
		while(st[i]>='a'&&st[i]<='z'){
			now[j]=st[i];
			i++;j++;
		}
		now[j]='\0';
		//printf("%s\n",now);
		int flag=0;
		for(j=1; j<=cnt; j++){
			if(!strcmp(num[j].words,now)){
				flag=j; break;
			}
		}
		if(flag) num[flag].tot++;
		else{
			cnt++;
			num[cnt].tot++;
			strcpy(num[cnt].words,now);
		}
		//printf("%s:%d\n",num[cnt].words,num[cnt].tot);
	} 
} 

int main(){
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(st,max,in)!=NULL){
		deal();
	}
	qsort(num+1,cnt,sizeof(num[1]),cmp);
	int i;
	for(i=1; i<=cnt; i++)
		printf("%s %d\n",num[i].words,num[i].tot);
	return 0;
}


