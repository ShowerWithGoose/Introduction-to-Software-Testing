#include<stdio.h>
#include<string.h>
int main()
{
	char s[101];
	int i,cnt,result=0;
	gets(s);
	if(s[0]=='0'){
		for(i=2;i<=101;i++){
			if(s[i]=='0')
				cnt++;
			else if(s[i]!='0')
				break;
		}
//		printf("%d %d",cnt,i);
		printf("%c",s[cnt+2]);
		i=cnt+3;
		if(s[i]!='\0'){
			printf(".");
			while(s[i]!='\0'){
				printf("%c",s[i]);
				i++;
			}
		}
		printf("e-");
		printf("%d\n",cnt+1);
	}
	else{
		i=1,cnt=0;
		printf("%c",s[0]);
		printf(".");
		while(s[i]!='.'){
			printf("%c",s[i]);
			i++;
			cnt++;
		}
		i=cnt+2;

		do{
			printf("%c",s[i]);
			i++;
		}while(s[i]!='\0');
		printf("e");
		printf("%d\n",cnt);
	}
	return 0;
}

