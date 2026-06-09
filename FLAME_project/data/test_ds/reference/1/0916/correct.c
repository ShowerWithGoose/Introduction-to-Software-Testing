#include<stdio.h>
void f(char *s1,char *s2){
	while(*s2=*s1){
		char a=*(s1-1),b=*s1,c=*(s1+1);
		if(b=='-'&&a<c&&c<='Z'&&a>='A'||b=='-'&&a<c&&c<='z'&&a>='a'||b=='-'&&a<c&&c<='9'&&a>='0'){
			char d=a+1;
			while(d<c)
			*s2++=d++;
			--s2;
		}
		++s1;
		++s2;
	}
}
int main( ){
	char a[100],b[100];
	gets(a);
	f(a,b);
	printf( "%s\n",b);
	return 0;
}

