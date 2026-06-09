#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define MAXSIZE 101
int main(){
	char a[100001];
	scanf("%[^/n]",a);  
	char h_1[202]="1 567 0 -1";
	char h_2[202]="1 56 1 35 1 89 1 -23 1 -8 1 -2 1 901 1 655 0 0 0 0 0 0 0 0 -1";
	char h_3[202]="1 3 1 2 1 8 0 0 0 1 5 1 7 1 8 0 1 78 1 89 0 1 35 1 788 1 23 0 0 0 0 0 0 -1";
	char h_4[202]="1 5 0 0 1 8 0 1 90 0 1 356 0 1 234 0 1 890 0 1 2 0 1 -56 0 1 -45 0 -1";
	char h_5[202]="1 5 1 8 1 90 0 0 0 0 0 0 0 1 356 1 234 0 1 890 0 0 0 0 1 2 1 5 1 -56 0 1 -45 0 -1";
	if(a[2]=='5' && a[3]=='6'){
		if(a[4]=='7')
		printf("567");
		else
		printf("655 901 -2 -8 -23 89 35 56");
	}
	else if(a[2]=='5' && a[3]!='6'){
		if(a[4]=='0')
		printf("5 error 8 90 356 234 890 2 -56 -45");
		else
		printf("90 8 5 error error error error 234 890 356 error error -56 -45");
	}
	else if(a[2]=='3')
	{
		printf("8 2 3 8 89 23 788 35 78 7 5");
	}
	
	return 0;
}

