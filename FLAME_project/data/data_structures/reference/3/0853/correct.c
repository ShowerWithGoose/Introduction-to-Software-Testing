#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX(a,b) ((a)?(b)? (a): (b))
#define MIN(a,b) ((a)?(b)? (a): (b))
#define pi acos(-1)
#define eps 1e-8
#define ULL unsigned long long
#define LL long long
int main(){
	char a[102];
	int m,n,i,j,k;
	gets(a);
	m=strlen(a);
	if(a[1]=='.'&&a[0]>'0'){
				for(i=0;i<m;i++){
					printf("%c",a[i]);
				}
				printf("e0");
				return 0;
			}
	else if(a[1]=='.'&&a[0]=='0'){
			for(j=2;j<m;j++){
				if(a[j]>'0'&&j!=m-1){
					printf("%c.",a[j]);n=j;
					break;
					}
				else if(a[j]>'0'&&j==m-1){
					printf("%c",a[j]);n=j;
					break;
				}
				}j++;
			for(j;j<m;j++){
					printf("%c",a[j]);
				}
				printf("e-%d",n-1);
				return 0;
			}
	printf("%c.",a[0]);
	for(i=1;i<m;i++){
	if(a[i]=='.'){
		k=i;
		continue;
	}
	else{
		printf("%c",a[i]);
	}
}
    printf("e%d",k-1);
}

