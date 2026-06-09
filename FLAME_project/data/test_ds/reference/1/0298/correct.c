#include<stdio.h>
#include<math.h>
#include<string.h>
int judge(char a,char b){
	if(a>='0'&&b>a&&b<='9') return 1;
	else if(a>='a'&&b>a&&b<='z') return 1;
	else if(a>='A'&&b>a&&b<='Z') return 1;
	return 0;
}
int main()
{
	char su[100];
	gets(su);
	for(int i=0;su[i]!='\0';i++){
		if(su[i]!='-')
		printf("%c",su[i]);
		else if(judge(su[i-1],su[i+1])){
			for(int j=1;su[i-1]+j<su[i+1];j++)
				printf("%c",su[i-1]+j);
		}
		else printf("-");
	}
	return 0;
}



