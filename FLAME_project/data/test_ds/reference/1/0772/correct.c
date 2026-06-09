#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char a[1000],a1[1000];
	int i,j,n;
	gets(a);
	for(i=0,j=0;i<strlen(a);i++){
		if(a[i]!='-'||i==0||i==strlen(a)-1){
			a1[j]=a[i];
			j++;
		}
		else{
			if(a[i+1]-a[i-1]>0&&(a[i-1]-'0'<=9&&a[i+1]-'0'<=9&&a[i-1]-'0'>-1&&a[i+1]-'0'>-1||a[i-1]-'a'<=25&&a[i+1]-'a'<=25&&a[i-1]&&a[i-1]-'a'>-1&&a[i+1]-'a'>-1||a[i-1]-'A'<=25&&a[i+1]-'A'<=25&&a[i-1]-'A'>-1&&a[i+1]-'A'>-1))
			for(n=1;n<a[i+1]-a[i-1];n++){
				a1[j]=a[i-1]+n;
				j++;
			}
			else{
				a1[j]=a[i];
				j++;
			}
		}
	}
	puts(a1);
	return 0;
}

