#include<stdio.h>
char a[105];
int main(){
	char ch;
	int i=0,j=0;
	ch=getchar();
	a[i++]=ch;
	while(ch!='\n'){
		ch=getchar();
	    a[i++]=ch;
	}
	
	//puts(a);
	//printf("%d",i);
	while(a[j]=='0'||a[j]=='.'){
		j++;
	}
	printf("%c",a[j]);
	if(a[j+1]!='\n'){
		printf(".");	
    }
	for(j++;j<i;j++){
		if(a[j]!='.'&&a[j]!='\n'){
			printf("%c",a[j]);
		}
	}
	printf("e");
	if(a[1]=='.'){
		if(a[0]!='0'){
			printf("0");
		}
		else if(a[0]=='0'){
			for(i=2;a[i]=='0';i++){
			}
			printf("-%d",i-1);
		}
	}
	else if(a[1]!='.'){
		for(i=0;a[i]!='.';i++){
		}
		printf("%d",i-1);
	}
}

