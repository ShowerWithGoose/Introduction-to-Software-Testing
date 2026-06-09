#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int read(){
	int s=0,f=1;char t=getchar();
	while('0'>t||t>'9'){
		if(t=='-')f=-1;
		t=getchar();
	}
	while('0'<=t&&t<='9'){
		s=(s<<1)+(s<<3)+(t-'0');
		t=getchar();
	}
	return s*f;
}

#define N (100005)

struct tree{
	int ch[26];
	int num;
}t[N];
int cnt=1;

char buf[1<<10];

#define NOT_CHAR 0

char trans(char a){
	if('a'<=a&&a<='z')return a;
	if('A'<=a&&a<='Z')return a-'A'+'a';
	return NOT_CHAR;
}

int get_word(FILE* f){
	char c=fgetc(f);
	if(c==EOF)return 0;
	int l=0;
	while(trans(c)==NOT_CHAR&&c!=EOF)
		c=fgetc(f);
	if(c==EOF)return 0;
	while(trans(c)!=NOT_CHAR){
		buf[l++]=c;
		c=fgetc(f);
	}buf[l]='\0';
	return 1;
}

void insert(){
//	printf("<%s>",buf);
	int l=strlen(buf);
	int u=1;
	for(int i=0;i<l;i++){
		if(trans(buf[i])==NOT_CHAR)continue;
		int dir=trans(buf[i])-'a';
		if(!t[u].ch[dir]){
			t[u].ch[dir]=++cnt;
		}
		u=t[u].ch[dir];
	}
	t[u].num++;
}

char stk[1005];
int top;

void Dfs(int u){
	if(t[u].num){
		for(int i=1;i<=top;i++){
			printf("%c",stk[i]);
		}printf(" %d\n",t[u].num);
	}
	for(int i=0;i<26;i++){
		if(t[u].ch[i]){
			stk[++top]=i+'a';
			Dfs(t[u].ch[i]);
			top--;
		}
	}
}

int main(){
	FILE* f=fopen("article.txt","r");
	while(get_word(f)){
		insert();
	}Dfs(1);
	fclose(f);
	return 0;
}



