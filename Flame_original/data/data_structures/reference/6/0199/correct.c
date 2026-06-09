#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include <stdio.h>
int main(){
int a[200];
int top=-1;
char s[1000];
fgets(s,1000,stdin);
int i=0;
int m[200]={};
int k=0;
int flag=0;
int note;
while(i<strlen(s)){
	flag=0;
	note=0;
	if(s[i]=='-'){
		note=1;
		i++;
	}
	while('0'<=s[i]&&s[i]<='9'){
		m[k]=m[k]*10+s[i]-'0';
		i++;
		flag=1;
	}
	if(note==1){
		m[k]=-m[k];
	}
	if(flag==1){
		k++;
	}
	i++;
}
note=k;
for(k=0;k<note;k++){
	if(m[k]==1){
		if(top==99){
			printf("error ");
		}else{
			top++;
			a[top]=m[k+1];
		}
	}
	else if(m[k]==0){
		if(top==-1){
			printf("error ");
		}else{
			printf("%d ",a[top]);
			top--;
		}
	}
}
return 0;
}



