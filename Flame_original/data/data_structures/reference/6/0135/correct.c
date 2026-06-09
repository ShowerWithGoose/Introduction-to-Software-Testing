#include<stdio.h>
#include<string.h>

int temp[100],top=0;

int get(){
	int a;
	char b;
	//while(getchar()!=' ');
	b = getchar();
	if(b=='-'){
		b = getchar();
		a = -(b-48);
	} 
	else a = b-48;
	while((b=getchar())!=EOF&&b!=' '&&b!='\n'){
		if(a>=0) a = a*10+b-48;
		else a = a*10-b+48;
	} 
	//while(getchar()!=' ');
	return a;
}

int main(){
	int a,b;
	while((a=get())!=-1){
		if(!a&&!top){
			printf("error ");
			continue;
		} 
		else if(a&&top==100){
			b = get();
			printf("error ");
			continue;
		}
		if(a){
			b = get();
			temp[top++] = b;
		} 
		else{
			printf("%d ",temp[--top]);
		}
	}
	return 0;
}

