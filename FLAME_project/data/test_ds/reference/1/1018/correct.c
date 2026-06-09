#include <stdio.h>
int expand(char fir,char thi);
int main(){
	char fir, sec, thi;
	int k;
	while(scanf("%c",&fir) != EOF){
		if(fir == '-'){
			scanf("%c",&thi);
			k = expand(sec,thi);
			sec = thi;
		}
		else {
			printf("%c",fir);
			sec = fir;
		}
	}
	return 0;
}
int expand(char fir,char thi){
	if(fir<='z'&&fir>='a'&&thi<='z'&&thi>fir){
		for(int i=1;i<=thi-fir;i++){
			printf("%c",fir+i);
		}
	}
	else if(fir<='Z'&&fir>='A'&&thi<='Z'&&thi>fir){
		for(int i=1;i<=thi-fir;i++){
			printf("%c",fir+i);
		}
	}
	else if(fir<='9'&&fir>='0'&&thi<='9'&&thi>fir){
		for(int i=1;i<=thi-fir;i++){
			printf("%c",fir+i);
		}
	}
	else printf("-%c",thi);	
	return 0;
}

