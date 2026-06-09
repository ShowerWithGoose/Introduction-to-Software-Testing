#include<stdio.h>
#include<string.h>
int main(){
	char a[1000];
	scanf("%s",a);
	int i,j=0,h=1,flag=0;
	for(i=0;a[i]!='\0';i++){
		if(a[i]!='-')
		printf("%c",a[i]);
		else{
			if((a[i-1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1])||(a[i-1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1])||(a[i-1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1])){
				for(j=a[i+1]-a[i-1];h<j;h++)
				printf("%c",a[i-1]+h);
				h=1; 
				flag=1;
				}
				if(flag==0)
				printf("-");
				flag=0;
			}
}
	return 0;

}

