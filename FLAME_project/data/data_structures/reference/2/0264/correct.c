#include<stdio.h>
#include<string.h>
char* p;
int tran(int a){
	while(*p>='0'&&*p<='9'){
		a=a*10+(*p-'0');
		p++;
	}
	return a;
}
int main()
{
	int i,j,equ1=0,n1=0,equ2=0,n2=0,judgeOfSym1=0,judgeOfSym2=0;
	char sen[1000],fsen[1000];
	gets(sen);
	for(i=0,j=0;sen[i]!='\0';i++){
		if(sen[i]!=' '){
			fsen[j]=sen[i];
			j++;
		}
	}
	p=&fsen[0];
	equ1=tran(0);
	while(*p=='*'||*p=='/'){
		if(*p=='*'){
			judgeOfSym2=1;
		}
		else{
			judgeOfSym2=0;
		}
		p++;
		n1=tran(0);
		switch(judgeOfSym2){
			case 1:equ1*=n1;
					break;
			case 0:equ1/=n1;
					break;
		}
	}
	while(*p!='='){
		if(*p=='+'){
			judgeOfSym1=1;
		}
		else if(*p=='-'){
			judgeOfSym1=-1;
		}
		p++;
		equ2=tran(0);
		while(*p=='*'||*p=='/'){
			if(*p=='*'){
				judgeOfSym2=1;
			}
			else{
				judgeOfSym2=0;
			}
			p++;
			n2=tran(0);
			switch(judgeOfSym2){
				case 1:equ2*=n2;
						break;
				case 0:equ2/=n2;
						break;
			}
		}
		equ1=equ1+equ2*judgeOfSym1;
	}
	printf("%d\n",equ1);
	return 0;	
} 

