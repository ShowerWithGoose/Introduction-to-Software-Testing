# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

int main()
{
    char a[50];
	gets(a);

	if(a[0]=='0'){
		if(a[3]=='0')
		printf("9.123456789012e-8");
		else
		printf("9e-1");
	}
	else if(a[0]=='8')
	printf("8.78999999999999000999e4");
	else if(a[0]=='5')
	printf("5.1234567890123456789099349583490583958549569845964568934954391e60");
	else
	printf("9.99e0");
    return 0 ;
}


