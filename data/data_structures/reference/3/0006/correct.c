#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define FEqual(a,b,eps) (fabs((a)-(b))<(eps)) 

char s[1024], t[1024];
char *p;
int l, cnt=0;
int j=0;
int main(){
	gets (s);
	l=strlen(s);
	if (s[0]=='0'){
		cnt--;
		for (int i=2; i<l&&s[i]=='0'; i++, cnt--);
	}
	else{
		cnt=strchr(s,'.')-s-1;
	}
	int flag=0;
	for (int i=0; i<l; i++){
		
		if (s[i]!='0'&&s[i]!='.'&&flag==0){
			flag=1;
		}
		if (flag==1&&s[i]!='.'){
			t[j]=s[i];
			j++;
		}
	}
	putchar(t[0]);
	if(j>=2)putchar('.');
	for (int i=1; i<j; i++){
		putchar (t[i]);
	}
	putchar('e');
	printf ("%d", cnt);
	return 0;
}





