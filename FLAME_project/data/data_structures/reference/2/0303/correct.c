#include <stdio.h>
#include <string.h>

int opt[10000];
char opr[10000];

int opt_top=-1, opr_top=-1;

char s[10000];

void calc(){
	while(opr_top >= 0){
		char c = opr[opr_top--];
		if(c == '*'){
			opt[opt_top-1] = opt[opt_top] * opt[opt_top-1];
			opt_top--;
		}
		if(c == '/'){
			opt[opt_top-1] = opt[opt_top-1] / opt[opt_top];
			opt_top--;
		}
		if(c == '+' || c == '-'){
			opr_top++;
			break;
		}
	}
}

void calc2(){
	for(int i=0; i<=opr_top; i++){
		char c = opr[i];
		if(c == '+'){
			opt[i+1] = opt[i] + opt[i+1];
		}
		if(c == '-'){
			opt[i+1] = opt[i] - opt[i+1];
		}
	}
}

int main(){
	gets(s);
	int n = strlen(s);
	for(int i=0, j=0; i<n; i++){
		if(s[i]!=' ')
			s[j++] = s[i];
	}
	
	char c;
	int len;
	int ofs = 0;
	while(1){
		sscanf(s+ofs, "%d%n%c", &opt[++opt_top], &len, &c);
		ofs += len+1;
		if(c == '='){
			calc();
			calc2();
			break;
		}
		calc();
		opr[++opr_top] = c;
	}
	
	printf("%d", opt[opt_top]);
	
	return 0;
}

