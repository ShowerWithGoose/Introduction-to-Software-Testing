#include<stdio.h>
char ch[500];
int main(){
	gets(ch);
	int i=0;
	if(ch[0]=='-'){putchar(ch[0]);i++;}
	if(ch[i]=='0'){
		int e=1;
		i++;
		while(ch[++i]=='0')e++;
		printf("%c",ch[i]);
		if(ch[i+1])putchar('.');
		for(i++;ch[i];i++)putchar(ch[i]);
		printf("e-%d",e);
	}
	else{
		int i0=i;
		int e=0;
		for(i++;ch[i]!='.';i++)e++;
		printf("%c",ch[i0]);
		if(ch[i0+1])putchar('.');
		for(i0++;ch[i0];i0++)
			if(ch[i0]!='.')putchar(ch[i0]);
		printf("e%d",e);
	}
	return 0;
}

