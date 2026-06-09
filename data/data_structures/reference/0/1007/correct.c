#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char a[1000],b[1000];
void f(int i,int c){
	int q=0;
	for(q=0;q<=c;q++){
		a[i+q-1]=a[i-1]+q;
	}
}
int main(){
	gets(a);
	int i,j,k,c;
	for(i=0;i<strlen(a);i++){
		if(a[i]=='-'&&a[i+1]>a[i-1]){
			for(j=0;j<strlen(a);j++){
				b[j]=a[i+1+j];
			}
			c=a[i+1]-a[i-1]-1;
			if(a[i+1]-'a'>0&&a[i-1]-'a'<25&&a[i-1]-'a'>=0&&a[i+1]-'a'<=25)
				f(i,c);
				else if(a[i+1]-'A'>0&&a[i+1]-'A'<=25&&a[i-1]-'A'>=0&&a[i-1]-'A'<25)
				f(i,c);
				else if(a[i+1]-'0'>0&&a[i+1]-'0'<=9&&a[i-1]-'0'>=0&&a[i-1]-'0'<9)
				f(i,c);
		for(k=0;k<strlen(a);k++){
			a[i+c+k]=b[k];
		}
		}
	}
	printf("%s",a);
}



