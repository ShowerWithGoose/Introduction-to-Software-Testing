#include <stdio.h>
#include <string.h>
char s[105];
char a[105];
int main(){
	gets(s);
	int i=0;
	int cnt=0;
	int num,point,k=0;
	int sign=1;
	while(s[i]=='0'||s[i]=='.'){
		i++;
	}
	num=i; //第一个有效数字的位置
	for(;i<strlen(s);i++){
		if(s[i]=='.')continue;
		a[k]=s[i];
		k++;//把有效数字都存进数组 ,k为有效数字的长度 
	}
	i=0;
	while(s[i]!='.'){
		i++;
	}
	point=i;//小数点的位置 
	
	if(num>point) sign=-1;//sign是-1则是-，1为正
	printf("%c",a[0]);
	if(i<strlen(a))printf(".");
	for(i=1;i<strlen(a);i++){
		printf("%c",a[i]);
	}
	printf("e");
	if(sign==-1)printf("-");
	i=point;
	while(i!=num){
		if(i>num){
			i--;
			cnt++;
		}else{
			i++;
			cnt++;
		}
	}
	if(sign==1)cnt--;

	printf("%d",cnt);
	return 0;
}

