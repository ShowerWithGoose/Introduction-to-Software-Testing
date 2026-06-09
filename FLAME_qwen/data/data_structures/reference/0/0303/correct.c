#include <stdio.h>

void expand(char p, char c){
	if('0'<=p&&p<='9' && '0'<=c&&c<='9' && p<=c){
		for(char i=p+1; i<c; i++)
			printf("%c", i);
	}else if('a'<=p&&p<='z' && 'a'<=c&&c<='z' && p<=c){
		for(char i=p+1; i<c; i++)
			printf("%c", i);
	}else if('A'<=p&&p<='Z' && 'A'<=c&&c<='Z' && p<=c){
		for(char i=p+1; i<c; i++)
			printf("%c", i);
	}else{
		printf("-");
	} 
}

int main(){
	char c;
	char oc = 0;
	char pending = 0;
	int proc = 0;
	while(scanf("%c", &c) != EOF){
		if(c == '-'){
			if(oc == '-')
				printf("-");
			proc = 1;
			pending = oc;
		}else if(proc == 1){
			proc = 0;
			expand(pending, c);
		}
		if(c != '-')
			printf("%c", c);
		oc = c;
	}
	if(proc == 1)
		printf("-");
	return 0;
}



