#include<stdio.h>
int main(){
	char a[110];
	scanf("%s",a);
	int i,ef,f=0,p,t;
	for(i=0;a[i]!='\0';i++){
		if(a[i]!='0'&&f==0&&a[i]!='.'){
			ef=i;	
			f=1;
		}
		if(a[i]=='.'){
			p=i;
		}
	}
	t=p-ef;
	printf("%c",a[ef]);
	for(ef++;ef<i;ef++){
		if(f==1){
			printf(".");
			f=0;
		}
		if(a[ef]!='.'){
			printf("%c",a[ef]);
		}
	}
	if(t<0)printf("e%d",t);
	else printf("e%d",t-1);
	return 0;
}

