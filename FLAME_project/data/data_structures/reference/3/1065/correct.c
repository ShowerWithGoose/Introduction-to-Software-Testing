#include<stdio.h>
int main(){
	char number[105];
	int d;
	int i,j;
	gets(number);
	if(number[0]!='0'){
		i=0;
			while(number[i]!='.')
				i++;
		d=i-1;
		printf("%c.",number[0]);
		for(j=1;number[j]!='\0';j++){
			if(number[j]!='.')
			printf("%c",number[j]);
		}
		printf("e%d",d);
	}
	else{
		i=0;
		while(!(number[i]>'0'&&number[i]<='9'))
			i++;
		d=i-1;
		
		printf("%c",number[i]);
		if(number[i+1]!='\0')
			printf(".");
		for(j=i+1;number[j]!='\0';j++){
			if(number[j]!='.')
			printf("%c",number[j]);
		}
		printf("e-%d",d);
	}
	
	return 0;
}

