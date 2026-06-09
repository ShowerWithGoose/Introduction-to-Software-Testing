#include<stdio.h>
#include<string.h>
#include<math.h>
int main() {
	char num[200];
	int i,j,k,m,count1=0;
	scanf("%s",num);
	int len = strlen(num);
	if(num[1]=='.') {
		if(num[0]!='0') {
			printf("%c",num[0]);
			printf(".");
			for(i=2; i<=len-1; i++) {
				printf("%c",num[i]);
			}
			printf("e0");
		} else {
			for(k=2; num[k]=='0'; k++) {
				count1++;
			}
			printf("%c",num[k]);
			if(k+1<len-1) printf(".");
			for(m=k+1;m<=len-1;m++){
				printf("%c",num[m]);
			}
			printf("e");
			printf("-%d",count1+1);
		}
	} else {
		printf("%c",num[0]);
		printf(".");
		for(i=1; num[i]!='.'; i++) {
			printf("%c",num[i]);
		}
		int count = i;
		i++;
		for(j=i; j<=len-1; j++) {
			printf("%c",num[j]);
		}
		printf("e");
		printf("%d",count-1);
	}
	return 0;
}



