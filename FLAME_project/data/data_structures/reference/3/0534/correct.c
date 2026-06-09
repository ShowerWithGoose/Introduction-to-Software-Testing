#include<stdio.h>
#include<string.h>

char shu[10001];

int main()
{
	scanf("%s",shu);
	int l=strlen(shu);
	int flag=0,t=0;
	for(int i=0;i<l;++i){
		if(shu[i]=='.'){
			flag=1;
			break;
		}
	} 
	if(flag==0){
		for(int i=l-1;i>=0;i--){
			if(shu[i]!='0'){
				t=i;
			}
		}
		printf("%c.",shu[0]);
		for(int i=2;i<=t;++i){
			printf("%c",shu[i]);
		}
	}
	else {
		if(shu[0]=='0'){
			for(int i=2;i<l;++i){
				if(shu[i]!='0'){
					t=i;
					break;
				}
			}
			if(t==l-1){
			    printf("%c",shu[t]);
			}
			else {
				printf("%c.",shu[t]);
			}
			for(int i=t+1;i<l;++i){
				printf("%c",shu[i]);
			}
			printf("e-%d",t-1);
		}
		else{
			for(int i=l-1;i>=0;i--){
				if(shu[i]=='.'){
					t=i;
				}
		    }
			printf("%c.",shu[0]);
			for(int i=1;i<l;++i){
				if(shu[i]!='.') printf("%c",shu[i]);
			}
			printf("e%d",t-1);
		}
	}
	return 0;
}

