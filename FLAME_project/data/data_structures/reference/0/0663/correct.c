#include<stdio.h>
#include<string.h>
int main()
{
	char ch[100];
	scanf("%s",ch);
	for(int i=0;i<strlen(ch);i++){
		if(ch[i]!='-')printf("%c",ch[i]);
		else if(ch[i]=='-'){
			if(('a'<=ch[i-1]&&ch[i-1]<ch[i+1]&&ch[i+1]<='z')||('0'<=ch[i-1]&&ch[i-1]<ch[i+1]&&ch[i+1]<='9')||('A'<=ch[i-1]&&ch[i-1]<ch[i+1]&&ch[i+1]<='Z'))
			{ 	
				for(int j=1;j<ch[i+1]-ch[i-1];j++){
					printf("%c",ch[i-1]+j);
				}
			}
			else printf("-");
		}
	}
	return 0;
}



