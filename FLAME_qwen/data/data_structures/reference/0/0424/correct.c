#include <stdio.h>

char ch[1000001];

void Out(int p){
	if((ch[p-1]-'a'<=25&&ch[p+1]-'a'<=25&&ch[p-1]>='a'&&ch[p+1]>='a')||(ch[p-1]-'A'<=25&&ch[p+1]-'A'<=25&&ch[p-1]>='A'&&ch[p+1]>='A')||(ch[p-1]-'0'<=9&&ch[p+1]-'0'<=9&&ch[p-1]>='0'&&ch[p+1]>='0')){
		for(int i=ch[p-1]+1;i<ch[p+1];++i)
			printf("%c",i);
	}
	else printf("-");
}

int main(){
	scanf("%s",ch);
	for(int i=0;ch[i];++i){
		if(ch[i]=='-'&&i&&ch[i+1])Out(i);
			else printf("%c",ch[i]);
	}
	return 0;
}
