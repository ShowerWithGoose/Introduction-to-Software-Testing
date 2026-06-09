#include<stdio.h>
#include<string.h>
int broaden(char,char);
int i,j=0;
int main()
{
	char s[100],flag[1000];
	gets(s);
	int len=strlen(s);
	for(i=0;i<len-1;i++){
		if(s[i]!='-') printf("%c",s[i]);
		else broaden(s[i-1],s[i+1]);
	}
	printf("%c",s[len-1]);
	return 0;
}

int broaden(char a,char b)
{
	int m;
	int dis=b-a;
	if(a>='0'&&b<='9'&&b-a>1){
		for(m=1;m<dis;m++){
			printf("%c",a+m);
		}
	}
	else if(a>='a'&&b<='z'&&b-a>1){
		for(m=1;m<dis;m++){
			printf("%c",a+m);
		}
	}
	else if(a>='A'&&b<='Z'&&b-a>1){
		for(m=1;m<dis;m++){
			printf("%c",a+m);
		}
	}
	else printf("-");
}



