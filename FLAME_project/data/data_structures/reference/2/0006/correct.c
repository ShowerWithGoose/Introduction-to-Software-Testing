#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define FEqual(a,b,eps) (fabs((a)-(b))<(eps)) 

int num[1024];
char v[1024];
char s[1024];
int p=0, l;
void deletespace(); 
int r=0, t=0;

int main(){
	gets(s);
	deletespace();
	
	for (int i=0; ; i++){
		for (; s[p]>='0'&&s[p]<='9'; p++){
			num[i]*=10;
			num[i]+=s[p]-'0';
		}
		v[i]=s[p];
		if (s[p]=='='){
			l=i;
			break;
		}	
		p++;
	}
	t=num[0];
	for (int i=0; i<l; i++){
		switch (v[i]){
			case '+':
				r+=t;
				t=num[i+1];
				break;
			case '-':
				r+=t;
				t=-num[i+1];
				break;
			case '*':
				t*=num[i+1];
				break;
			case '/':
				t/=num[i+1];
				break;
		}
	}r+=t;
	printf ("%d", r);
	return 0;
}

void deletespace(){
	int k=0;
	for (int p=0; s[p]!='\0'; p++){
		if (s[p]!=' '){
			s[k]=s[p];
			k++;
		}
	}
	s[k]='\0';
}

