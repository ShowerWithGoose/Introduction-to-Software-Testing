#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[100];
	int countZ = 0,countX = 0,i,j,p,q;
	int k,l,Czero = 1;
	int a;
	gets(s);
	for(i = 0;i < strlen(s);i++){
		if(s[i] != '.'){
			countZ++;
		}
		else if(s[i] == '.'){
			break;
		}
	}
	countX = strlen(s) - countZ - 1;
	for(p = 0,q = 0;p < strlen(s);p++){
		if(s[p] != '.'){
			s[q++] = s[p];
		}
	}
	s[q] = '\0';
	/*puts(s);
	printf("%d %d",countZ,countX);*/
	int m;
	if(countX < 0){
		printf("%c.",s[0]);
		for(m = 1;m < strlen(s);m++){
			printf("%c",s[m]); 
		}
		printf("e%d",countZ - 1);
	}								//纯整数 
	
	else if(s[0] == '0'){
		for(k = 1;k < strlen(s) - 1;k++){
			if(s[k] == '0'){
				Czero++;
			}
			else if(s[k] != '0') break;
		}
		if(Czero == strlen(s) - 1){
			printf("%c",s[Czero]);
			printf("e-%d",Czero);
		}
		else if(Czero < strlen(s) - 1){
			printf("%c.",s[Czero]);
			for(l = Czero + 1;l < strlen(s);l++){
				printf("%c",s[l]);
			}
			printf("e-%d",Czero);
		} 
	}							//开头为0的小数
	else if(countZ > 0 && countX >0){
	 		printf("%c.",s[0]);
			for(a = 1;a < strlen(s);a++){
				printf("%c",s[a]);
			}
			printf("e%d",countZ - 1);
	 }
	return 0;
}


