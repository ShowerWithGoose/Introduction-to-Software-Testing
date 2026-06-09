#include <stdio.h>
#include <string.h>
void clear(char s[], int length);
int calcu(int* t);
int num[100] = {0};
char tape[100] = {0};
int main(){
	char s[200];
	int sum = 0, part_sum = 0, counter = 1;
	int i=0, j=0, t=0;
	gets(s);
	clear(s,strlen(s));
	while(1){
		for(;s[i]>='0' && s[i]<='9';i++){
			num[j] = num[j]*10 + s[i]-'0';
		}
		if(s[i] == '=')break;
		tape[j] = s[i];
		j++;
		i++;
	}
	if(tape[0]=='+'||tape[0]=='-')sum = num[0];
    else if(tape[0] == '\0'){
		sum = num[0];
	}
	for(;t<j;){
		if(tape[t] == '+'){
			counter = 1;
			t++;
		}
		else if(tape[t] == '-'){
			counter = -1;
			t++;
		}
		part_sum = calcu(&t);
		sum += counter * part_sum;
	}
	printf("%d",sum);
return 0;
} 


void clear(char s[], int length){
	int i=0, j=0, length2 = length;
	for(;i<=length;i++){
		if(s[i] != ' '){
			s[j++] = s[i]; 
		}
		else length2--;
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
		}
	}
	s[length2] = '\0';
	return;
}
int calcu(int* t){
	int part_sum;
	part_sum = num[*t];
	while(1){
		if(tape[*t]=='*'){
			part_sum *= num[*t+1];
			*t += 1;
		}
		else if(tape[*t]=='/'){
			part_sum /= num[*t+1];
			*t += 1;
		}
		if(tape[*t] == '+' || tape[*t] == '-' || tape[*t] == '\0'){
			return part_sum;
		}
	}
}

