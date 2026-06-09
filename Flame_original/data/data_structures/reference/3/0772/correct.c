#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//qsort顺序为数组名，元素数量，元素大小，cmp 
void dele(char *s){
	int i,j=0;
	for(i=j=0;s[i]!='\0';i++)
	if(s[i]!='.')
	s[j++]=s[i];
	s[j]='\0';
}//删. 
void shanlin(char *s){
	int i;
	for(i=strlen(s)-1;s[i]=='0';i--)
	s[i]='\0';
}
int main(){
	char n[100];
	gets(n);
	int i,j,d1,u1,e,feilin=0,k1=0;
	for(i=0;n[i]!='.'&&n[i]!='\0';i++);
	d1=i;
	for(i=0;n[i]!='\0';i++){
		if(n[i]=='.')
		j--;
		if(n[i]>='1'&&n[i]<='9')
		break;
	}
	j+=i;
	u1=j;
	e=d1-u1;
	dele(n);
	shanlin(n);
	for(i=0;n[i]!='\0';i++){
		if(n[i]!='0'&&feilin==1&&k1==0){
			printf(".");
			k1=1;
		}
		if(n[i]!='0'&&feilin==0)
		feilin=1;
		if(feilin==0)
		continue;
		else
		printf("%c",n[i]);
	}
	printf("e%d",e-1);
    return 0;
} 

