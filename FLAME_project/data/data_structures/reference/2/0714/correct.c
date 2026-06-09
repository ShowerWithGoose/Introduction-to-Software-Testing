#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE (100000)

char buffer[MAX_SIZE];
int tbuffer[MAX_SIZE];
int type[MAX_SIZE];
int cursor;
int tot;

int read_number(){
	int x=0,flg=1;
	while('0'>buffer[cursor]||buffer[cursor]>'9'){
		if(buffer[cursor]=='-')flg=-1;
		cursor++;
	}
	while('0'<=buffer[cursor]&&
		  buffer[cursor]<='9'){
		x=(x<<1)+(x<<3)+(buffer[cursor]-'0');
		cursor++;
	}
	return x*flg;
}

int read_operator(){
start:
	switch(buffer[cursor]){
		case '+':cursor++;return 0;
		case '-':cursor++;return 1;
		case '*':cursor++;return 2;
		case '/':cursor++;return 3;
		case '=':cursor++;return 4;
		default:
			cursor++;
			goto start;
	}
}

void count(){
	int len=(int)strlen(buffer);
	while(1024){
		tbuffer[tot]=read_number();
		
		if(tot){
			if(type[tot-1]==2){
				tbuffer[tot-1]=tbuffer[tot-1]*tbuffer[tot];
				tot--;
			}
			if(type[tot-1]==3){
				tbuffer[tot-1]=tbuffer[tot-1]/tbuffer[tot];
				tot--;
			}
		}
		
		type[tot]=read_operator();
		if(type[tot]==4)break;
		tot++;
	}
	int ans=tbuffer[0];
	for(int i=1;i<=tot;i++){
		if(type[i-1]==0)
			ans+=tbuffer[i];
		else
			ans-=tbuffer[i];
	}
	printf("%d",ans);
}

int main(){
	gets(buffer);
	count();
	return 0;
}
/*
-2 +2 =
*/

