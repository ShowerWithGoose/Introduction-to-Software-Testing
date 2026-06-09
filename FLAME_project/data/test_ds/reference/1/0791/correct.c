#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define LL long long
#define ULL unsigned long long 
char ch[999999];
int main() {
    scanf("%s",ch);
    int i,k;
    printf("%c",ch[0]);
    for(i=1;i<=strlen(ch)-1;i++){
    	if(ch[i]=='-'){
    		if(ch[i-1]<ch[i+1]&&('a'<=ch[i-1]&&ch[i+1]<='z'||'0'<=ch[i-1]&&ch[i+1]<='9'||'A'<=ch[i-1]&&ch[i+1]<='Z')){
    	   for(k=ch[i-1]+1;k<=ch[i+1]-1;k++){
    	   	printf("%c",k);
		   }	}
		   else{
		   	printf("-");
		   }
		}
		else{
			
			printf("%c",ch[i]);
		}
	}
	return 0;
}

