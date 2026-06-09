#include<stdio.h>
#include<math.h>
#include<string.h>
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define eps 1e-10
#define MAX(a,b) ((a)>(b)?(a) : (b))
#define MIN(a,b) ((a)>(b)?(a) : (b))
int main() {
    char a[10000];
    gets(a);
    int i=0;
    int str=strlen(a);
    if(a[0]=='0'){
    	i=2;
		while(1){
			if(a[i]=='0')
			i++;
			else break;
		}
		printf("%c",a[i]);
		if(i==str-1) printf("e-%d",str-2);
		else{
			printf(".");
			for(int j=i+1;j<str;j++){
				printf("%c",a[j]);
			}
			printf("e-%d",i-1);
		}
	}
	else{
		i=1;
		while(1){
			if(a[i]=='.')
			break;
			else i++;
		}
		printf("%c.",a[0]);
		for(int j=1;j<i;j++){
			printf("%c",a[j]);
		}
		for(int j=i+1;j<strlen(a);j++)
		{
			printf("%c",a[j]);
		}
		printf("e%d",i-1);
	}
}

