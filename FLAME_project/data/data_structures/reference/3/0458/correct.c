#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define eps 1e-9
int main()
{
	char s[101];
	char front[100];
	char back[100];
	gets(s);
	int n=0;
	int i=0;
	for(;s[i] != '.';i++){
		front[n++] = s[i];
	}
	front[n++] = '\0';
	i++;
	n = 0;
	for(;i<=strlen(s);i++){
		back[n++] = s[i];
	}
	back[n++] = '\0';
//	puts(front);
//	printf("\n");
//	puts(back);
//	printf("\n");
	if(strlen(front) == 1){
//		printf("here");
		if(front[0] == '0'){
			int j = 0;
			while(back[j] == '0'){
				j++;
			}
			j++;
			if(j == strlen(back)){
//				printf("here");
				printf("%ce-%d",back[j-1],j);

			}
			else{
				printf("%c.",back[j-1]);
				int mid = j;
				while(back[j]!= '\0'){
					printf("%c",back[j]);
					j++;
				}
				printf("e-%d",mid);
			}
		}
		else{
			printf("%c.",front[0]);
			int k = 0;
			while(back[k]!='\0'){
				printf("%c",back[k]);
				k++;
		}
			printf("e0");
		}
	}
	else{
//		printf("here");
		printf("%c.",front[0]);
		int k = 1;
		while(front[k] != '\0'){
			printf("%c",front[k]);
			k++;
		}
		int m=0;
		while(back[m]!='\0'){
			printf("%c",back[m]);
			m++;
		}
		printf("e%d",k-1);
	}
	return 0;
}

