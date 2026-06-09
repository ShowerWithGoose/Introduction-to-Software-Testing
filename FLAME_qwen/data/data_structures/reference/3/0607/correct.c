#include<stdio.h>
char st[110];
int cnt1=0,cnt2=0;

void deal(){
	int i;
	for(i=0; st[i]!='.'&&st[i]!='\0'; i++)
		cnt1++;
	for(i+=1;st[i]!='\0';i++)
		cnt2++;
	if(cnt1!=1){
		putchar(st[0]);
		putchar('.');
		for(i=1; st[i]!='\0'; i++){
			if(st[i]=='.') continue;
			putchar(st[i]);
		}
		printf("e%d",cnt1-1);
		return;
	}
	else{
		if(st[0]!='0'){
			printf("%se0",st);
			return;
		}
		else{
			for(i=2; st[i]!='\0'; i++)
				if(st[i]!='0') break;
			putchar(st[i]);
			if(i==cnt2+1){
				printf("e-%d",cnt2);
				return;
			}
			else {
				printf(".");
				int cnt=0;
				for(i+=1; st[i]!='\0'; i++)
					putchar(st[i]),cnt++;
				printf("e-%d",cnt2-cnt);
				return;
			}
		} 
	}
}

int main(){
	
	gets(st);
	deal();
	return 0;
}


