#include<stdio.h>
#include<string.h>
char ch1[1000],ch2[1000];
int judge(char c1,char c2){
	if((c1>='0'&&c1<='9')&&(c2>='0'&&c2<='9')&&(c2-c1>1))
		return 1;
	else if((c1>='a'&&c1<='z')&&(c2>='a'&&c2<='z')&&(c2-c1>1))
		return 1;
	else if((c1>='A'&&c1<='Z')&&(c2>='A'&&c2<='Z')&&(c2-c1>1))
		return 1;
	else
		return 0;
}
int main(){
	gets(ch1);
	int len=strlen(ch1);
	int i,j;
	for(i=0,j=0;i<len;i++){
		if(ch1[i]=='-'&&judge(ch1[i-1],ch1[i+1])){
			for(char c=ch1[i-1]+1;c<ch1[i+1];c++)
				ch2[j++]=c;
		}
		else
			ch2[j++]=ch1[i];
	}
	puts(ch2);
	return 0;
}



