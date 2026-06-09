#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char str[10000];
	char b[10000];
	gets(str);
	n=strlen(str);
	int num=1;
	b[0]=str[0];
	for(int i=1;i<n-1;i++){
		if(str[i]=='-'&&'a'<=str[i-1]&&str[i-1]<str[i+1]&&str[i+1]<='z'){
			for(int j=1;j<str[i+1]-str[i-1];j++){
				b[num++]=str[i-1]+j;
			}
		}
		else if(str[i]=='-'&&'A'<=str[i-1]&&str[i-1]<str[i+1]&&str[i+1]<='Z'){
			for(int j=1;j<str[i+1]-str[i-1];j++){
				b[num++]=str[i-1]+j;
			}
		}
		else if(str[i]=='-'&&'0'<=str[i-1]&&str[i-1]<str[i+1]&&str[i+1]<='9'){
			for(int j=1;j<str[i+1]-str[i-1];j++){
				b[num++]=str[i-1]+j;
			}
		}
		else{
			b[num++]=str[i];
		}
	}
	b[num++]=str[n-1];
	b[num]='\0';
	printf("%s",b);
	return 0;
}

