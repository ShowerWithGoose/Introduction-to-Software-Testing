#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char S[105],answer[105];
int main()
{
	int i,flag1,flag2;
	scanf("%s",S);
	int L=strlen(S);
	//printf("%d",L);
	for(i=0;S[i]!='.';i++);
	flag1=i;
	//printf("%d",flag1);
	if(flag1==1){
		if(S[0]!='0') printf("%s",S),printf("e0");
		else{
			for(i=2;S[i]!='\0';i++){
				if(S[i]!='0'){flag2=i;break;}
			}
			//printf("%d\n",flag2);
			if(flag2==L-1) printf("%ce-%d",S[flag2],flag2-1);
			else{
				printf("%c.",S[flag2]);
				for(i=flag2+1;S[i]!='\0';i++) printf("%c",S[i]);
				printf("e-%d",flag2-1);
			}
			
		}
	}
	else{
		printf("%c.",S[0]);
		for(i=1;S[i]!='\0';i++){
			if(S[i]!='.') printf("%c",S[i]);
		}
		printf("e%d",flag1-1);
	}
	
	return 0;
}

