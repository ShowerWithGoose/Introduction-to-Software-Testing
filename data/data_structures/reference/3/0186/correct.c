#include<stdio.h>
#include<string.h>

int main(){
	char c[1000],d[1000];
	int b=0,x=0,t=0,e=0;
	gets(c);
	if(c[0]=='-'){
		b=1;
		d[0]='-';
		t=1;
	}
	if(c[b]=='0'){
		while(c[b]=='0'||c[b]=='.'){
			if(c[b]=='0') e++;
			b++;
		}
		d[t++]=c[b++];
		if(c[b]!='\0') d[t++]='.';
		while(c[b]!='\0'){
			d[t++]=c[b++];
		}
		d[t++]='e';
		d[t++]='-';
		if(e>=10){
			d[t++]=e/10+'0';
			d[t++]=e%10+'0';
			d[t]='\0';
			puts(d);
			return 0;
		}
		else{
			d[t++]=e%10+'0';
			d[t]='\0';
			puts(d);
			return 0;
		}
	}
	else{
		d[t++]=c[b++];
		if(c[b]!='\0') d[t++]='.';
		while(c[b]!='.'&&c[b]!='\0'){
			d[t++]=c[b++];
			e++;
		}
		if(c[b]=='.') b++;
		while(c[b]!='\0') d[t++]=c[b++];
		d[t++]='e';
		if(e>=10){
			d[t++]=e/10+'0';
			d[t++]=e%10+'0';
			d[t]='\0';
			puts(d);
			return 0;
		}
		else{
			d[t++]=e%10+'0';
			d[t]='\0';
			puts(d);
			return 0;
		}
	}
}

