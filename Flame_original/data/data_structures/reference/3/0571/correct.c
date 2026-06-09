#include<stdio.h>
#include<string.h>
int main(){
	char a[100000],b[100000];
	int i,j,k,l,m;
	gets(a);
	l=strlen(a);
	for(i=0;i<=l-1;i++){
		if(a[i]=='.'){
		m=i;
		break;}
	}
	if(m==1&&a[0]=='0'){
		j=1;
		while(a[j+1]=='0'){
			j++;
		}
		if((j+2)==l){
			b[0]=a[j+1];
			b[1]='e';
		}
		else{
		b[0]=a[j+1];b[1]='.';
		for(k=1;k<=l-j-1;k++){
			b[k+1]=a[j+k+1];
		}
			b[k]='e';
		}
		printf("%s",b);
		printf("-%d",j);
	}
	else if(m==1){
		a[l]='e';a[l+1]='0';
		puts(a);
	}
	else{
		b[0]=a[0];b[1]='.';
		for(j=1;j<=m;j++){
			b[j+1]=a[j];
		}
		for(j=m+1;j<=l-1;j++){
		b[j]=a[j];}
		b[j]='e';
		printf("%s",b);
		printf("%d",m-1);
	}
	return 0;
}

