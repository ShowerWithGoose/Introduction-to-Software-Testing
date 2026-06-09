#include<stdio.h>
#include<string.h>
int main(){
	char a[105], b[105];
	int i, j, k;
	gets(a);
	for(i = 0; a[i] != '\0'; i++){
		if(a[i] == '.') break;
	}
	if(a[0] != '0'){
		b[0] = a[0]; b[1] = '.';
		for(j = 1, k = 2; a[j] != '\0'; j++)
			if(a[j] != '.') b[k++] = a[j];
		b[k] = '\0';
		printf("%s",b);
		printf("e%d",i-1);
	}
	else{
		for(i = 0; a[i] != '\0'; i++)
			if(a[i]!='0'&&a[i]!='.') break;
		if(strlen(a) - 1 > i){
			b[0] = a[i]; b[1] = '.';
			for(j = i+1, k = 2; a[j] != '\0'; j++)
				b[k++] = a[j];
				b[k] = '\0';
		}
		else {
			b[0] = a[i];b[1] = '\0';
		}
		printf("%s", b);
		printf("e-%d",i-1);
	}
	return 0;
}


