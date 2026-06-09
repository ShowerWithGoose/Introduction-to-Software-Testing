#include<stdio.h>
#include<string.h>
char in[105],num;
int p1,p2,op,n,e,i;
int main(){
	fgets(in,105,stdin);
	for(i=0;i<strlen(in);i++){
		if(in[i]=='.'){
			p2=i;
		}
	}
	for(i=strlen(in)-1;i>=0;i--){
		if(in[i]!='0'&&in[i]!='.'&&in[i]!='\n'){
			p1=i;
			num=in[i];
			n++;
		}
	}
	e=p2-p1;
	if(p1==0)e--;
	if(n==1){
		printf("%ce%d",num,e);
	}else{
		printf("%c.",num);
		for(i=p1+1;i<strlen(in);i++){
			if(in[i]!='.'&&in[i]!='\n')
				printf("%c",in[i]);
		}
		printf("e%d",e);
	}
	return 0;
}
