#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char a[100] ;
char out[100];
int judge(char x, char y);
int main()
{
	scanf("%s", a);
	int len = strlen(a);
	for (int i=0; i<len; i++){
		if (a[i]=='-') continue;
		if (a[i-1]!='-'){
			putchar(a[i]);
			
		}else if(judge(a[i-2], a[i])){
			for (char m=a[i-2]+1; m<=a[i]; m++){
				putchar(m);
			}
		}else{
			printf("-%c", a[i]);
		}
	}
	return 0;

}

int judge(char x, char y)
{
	int flag = 1;
	if (!((x<='z'&&x>='a'&&y<='z'&&y>='a')||(x<='Z'&&x>='A'&&y<='Z'&&y>='A')||(x<='9'&&x>='0'&&y<='9'&&y>='0')))
		flag = 0;
	if (x>=y) flag = 0;
	return flag;
}
