#include<stdio.h>
#include<string.h>
#include<math.h>
int think(char a[],int num){
	if(a[num+1]=='-'){
	if(('0'<=a[num]&&a[num]<='9'&&'0'<=a[num+2]&&a[num+2]<='9'&&a[num]<a[num+2])||('A'<=a[num]&&a[num]<='Z'&&'A'<=a[num+2]&&a[num+2]<='Z'&&a[num]<a[num+2])||('a'<=a[num]&&a[num]<='z'&&'a'<=a[num+2]&&a[num+2]<='z'&&a[num]<a[num+2]))
	return 1;}
	else return 0;
}
int main(){
	int num=0,max;
	char i;
	char a[10000];
	gets(a);
	max=strlen(a);
	while(num<max){
		if(think(a,num)==1){
			if(a[num-1]=='-'){
				if(think(a,num-2)==0)
				printf("%c",a[num]);
				else;
				i=a[num]+1;
				while(i<=a[num+2]){
					if(a[num]=='-');
					else printf("%c",i);
					i++;
				}
			}
			else{
				i=a[num];
				while(i<=a[num+2]){
					if(a[num]=='-'){
						;
					}
					else printf("%c",i);
			i++;
				}
			}
		}
		else if(think(a,num-2)==1);
		else if(think(a,num-1)==1&&a[num]=='-');
	    else printf("%c",a[num]);
	num++;
	}
	return 0;
}

