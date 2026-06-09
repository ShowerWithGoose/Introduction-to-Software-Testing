#include<stdio.h>
int main()
{
	char s[100];
	char t[100];
	int n=0;
	int x=0;
	scanf("%s",s);
	if(s[0]!='0'&&s[1]=='.'){
		printf("%s",s);
		printf("e0");
	}
	else if(s[0]=='0'){
		for(int i=2;s[i]=='0';i++){
			n++;
		}
		for(int i=n+2;s[i]!='\0';i++){
			t[x]=s[i];
			x++;
		}
		printf("%c",t[0]);
		if(x>1){
			printf(".");
		}
		for(int i=1;i<x;i++){
			printf("%c",t[i]);
		}
		printf("e-");
		printf("%d",n+1);	
	}
	else{
		for(int i=0;s[i]!='\0';i++){
			if(s[i]!='.'){
				t[x]=s[i];
				x++;
			}
		}
		for(int i=0;s[i]!='.';i++){
			n++;
		}
		printf("%c",t[0]);
		printf(".");
		for(int i=1;i<x;i++){
			printf("%c",t[i]);
		}
		printf("e");
		printf("%d",n-1);
	}
	return 0;
}

