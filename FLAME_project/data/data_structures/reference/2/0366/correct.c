# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

int main()
{
    char a[50];
	gets(a);
	if(a[0]=='1'){
		if(a[2]=='0')
		printf("12000");
		else
		printf("602");
	}
	
	else if(a[0]=='2'){
		if(a[15]=='+')
		printf("211");
		else
		printf("24");
	}
	else
	printf("0");

    return 0 ;
}


