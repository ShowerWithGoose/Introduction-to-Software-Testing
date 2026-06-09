#include<stdio.h>
#include<string.h>
char s[100],temp[100];
int main(){
	int i=0,j=0,k=0,l=0;
	int save;
	while(gets(s)!=NULL){
	}
	for(i=0;i<strlen(s);i++){
		if((s[i]=='-') && (((s[i-1]>='A')&&(s[i+1]<='Z')) 
|| ((s[i-1]>='a')&&(s[i+1]<='z')) || ((s[i-1]>='0')&&(s[i+1]<='9')))
&& (s[i-1]<s[i+1])){
			save=s[i+1];
			j=i;
			for(k=0;k<100;k++,j++){
				temp[k]=s[j+2];
			}
			for(k=0,j=i-1;s[j]<=save;k++,j++){
				s[j+1]=s[j]+1;
			}
			for(k=j,l=0;k<100;k++,l++){
				s[k]=temp[l];
			}
		}
	}
	puts(s);
	return 0;
}



