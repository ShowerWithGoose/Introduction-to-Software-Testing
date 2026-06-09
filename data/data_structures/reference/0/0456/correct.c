#include<stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	char a,b,c,i;
	while(scanf("%c",&b)!=EOF){
		if(b!='-')
        {
         printf("%c",b);
         a=b;
        }
		else
        {
        scanf("%c",&c);
        if(('a'<=a&&c<='z'&&a<c)||('A'<=a&&c<='Z'&&a<c)||('0'<=a&&c<='9'&&a<c))
        {
				for(i=a+1;i<=c;i++) printf("%c",i);
        }
			else printf("%c%c",b,c);
			a=c;
		}
	}
	return 0;
}



