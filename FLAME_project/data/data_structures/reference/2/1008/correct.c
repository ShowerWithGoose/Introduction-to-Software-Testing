#include<stdio.h>
#include<string.h>
int number(char c){
	if(c<='9'&&c>='0') return 1;
	else return 0;
}
int jj(char c){
	if(c == '+'||c == '-') return 1;
	else return 0;
}
int cc(char c){
	if(c == '*'||c == '/') return 1;
	else return 0;
}
int main(){
	char s[100], jjcc[100], jiajian[100];
	int num1[100], num2[100], i, j, k, ans;
	gets(s);
	for(i = 0, j = 0, k = 0; s[i] != '\0'; i++){
		if(jj(s[i])||cc(s[i])) jjcc[j++] = s[i];
		if(number(s[i])){
			num1[k] = s[i] - '0';
			while(number(s[i+1])){
				num1[k] = 10*num1[k] + s[i+1] - '0';
				i++;
			}
			k++;
		}
	}
	jjcc[j] = '\0';
	num2[0] = num1[0];
	for(i = 0, j = 0, k = 0; jjcc[i] != '\0'; i++){
		if(jj(jjcc[i])){
			jiajian[j++] = jjcc[i];
			num2[++k] = num1[i+1];
		}
		else{
				if(jjcc[i] == '*') num2[k] = num2[k]*num1[i+1];
				if(jjcc[i] == '/') num2[k] = num2[k]/num1[i+1];
		}	
	}
	jiajian[j] = '\0';
	ans = num2[0];
	for(i = 0; jiajian[i] != '\0'; i++){
		if(jiajian[i] == '+') ans += num2[i+1];
		if(jiajian[i] == '-') ans -= num2[i+1];
	}
	printf("%d",ans);
	return 0;
}





