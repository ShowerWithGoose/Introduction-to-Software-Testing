#include<stdio.h>
#include<string.h>
#include<ctype.h>
int check(char a[],int i){
	if(islower(a[i-1])&&islower(a[i+1])&&(a[i-1]<a[i+1]-1))return 1;
	if(isupper(a[i-1])&&isupper(a[i+1])&&(a[i-1]<a[i+1]-1))return 1;
	if(isdigit(a[i-1])&&isdigit(a[i+1])&&(a[i-1]<a[i+1]-1))return 1;
	else return 0;
}
int main(){
	char a[105],b[105];
	int i,j=0,k=0;
	scanf("%s",&a);	//printf("%s",a);
	for(i=0;i<=strlen(a);i++){
		if(a[i]!='-'){
			b[j]=a[i];
			j++;
		}
		else if((a[i]=='-')&&(check(a,i))){
			for(k=0;k<(a[i+1]-a[i-1])-1;k++){
				b[j]=a[i-1]+k+1;
				j++;
			}
			
		}
		else{
				b[j]=a[i];
				j++;
			}
	}
	printf("%s",b);
	return 0;
}

