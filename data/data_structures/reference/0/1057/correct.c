#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y
#define MAXN 10000
//define mst(s) memset(s,0,sizeof(s))
char s[MAXN];
int main(void)
{
	int i,j,k,n,m;
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++){
		if(s[i]!='-'){
			printf("%c",s[i]);
		}else{
			if(i!=0&&s[i+1]!='\0'&&(islower(s[i-1])&&islower(s[i+1])||isupper(s[i-1])&&isupper(s[i+1])||isdigit(s[i-1])&&isdigit(s[i+1]))&&s[i+1]>s[i-1])
			{
				for(j=1;s[i-1]+j<s[i+1];j++){
					printf("%c",s[i-1]+j);
				}
			}else{
				printf("%c",s[i]);
			}
		}
	}

	return 0;
}





