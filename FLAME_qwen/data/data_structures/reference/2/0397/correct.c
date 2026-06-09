#include <stdio.h>

char s[11000], op[50];
int nums[50], len;


void NoSpace() {
	int i, j;
	for (i = 0, j = 0; s[i] != '\0'; i++) {
		if (s[i] != ' ') s[j++] = s[i];
	}
	s[j] = '\0';
	return;
}

void Move(int n){
	int i = n;
	while(i<len){
		nums[i+1] = nums[i+2];
		op[i] = op[i+1];
		i++;
	}
	len--;
}
/*
void Show(){
	for(int i=0;i<len;i++){
		printf("%d%c",nums[i],op[i]);
	}
	printf("\n");
}
*/
int main() {
	
	gets(s);
	NoSpace();
	
	for (int i = 0, j = 0, tmp=0; s[i] != '\0'; i++) {//¶ÁÈë
		if (s[i] >= '0' && s[i] <= '9') 
			tmp = tmp * 10 + (s[i] - '0');	
		else{
			nums[j] = tmp;
			op[j] = s[i];
			len = ++j;
			tmp = 0;
		}
	}
	
	for(int i=0;op[i]!='\0';i++){
		if(op[i]=='*'){
			nums[i] = nums[i] * nums[i+1];
			Move(i);
			//Show();
		}else if (op[i] == '/'){
			nums[i] = nums[i] / nums[i+1];
			Move(i);
			//Show();
		}else i++;
		i--;
	}
	
	for(int i=0;op[i]!='\0';i++){
		if(op[i]=='+'){
			nums[i] = nums[i] + nums[i+1];
			Move(i);
			//Show();
		}else if (op[i] == '-'){
			nums[i] = nums[i] - nums[i+1];
			Move(i);
			//Show();
		}else i++;
		i--;
	}
	
	printf("%d",nums[0]);
	//puts(s);
	return 0;
}

