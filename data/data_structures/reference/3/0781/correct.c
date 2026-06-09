#include<stdio.h>
#include<math.h>
#include<string.h>
char ch1[110];
int main(){
	char t;
	int n=0,m;
	gets(ch1);
	if(ch1[0]=='0'){
		while(ch1[n]=='0'){
			t=ch1[n+1];
			ch1[n+1]=ch1[n+2];
			ch1[n+2]=t;
			n++;
		}
		if(ch1[n+2]=='\0')ch1[n+1]='\0';
		printf("%se-%d",ch1+n,n);
	}
	else{
		for(m=0;ch1[m]!='.';m++);
		while(ch1[1]!='.'){
			t=ch1[m-n];
			ch1[m-n]=ch1[m-n-1];
			ch1[m-n-1]=t;
			n++;
		}
		printf("%se%d",ch1,n);
	}
}

